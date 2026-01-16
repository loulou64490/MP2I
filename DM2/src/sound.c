#include "sound.h"
#include <stdlib.h>

unsigned BITS = 16, SAMPLE_RATE = 44100;
double DEFAULT_LENGTH = 1, DEFAULT_FREQUENCY = 440, DEFAULT_AMPLITUDE = 16000;
double DEFAULT_ATTACK = 0.01, DEFAULT_DECAY = 0.05, DEFAULT_SUSTAIN = 0.5,
       DEFAULT_RELEASE = 0.005;

void free_sound(sound_t *sound) {
  free(sound->samples);
  free(sound);
}

void free_track(track_t *track) {
  for (unsigned i = 0; i < track->n_sounds; ++i) {
    free_sound(track->sounds[i]);
  }
  free(track->sounds); // à chaque fois je les oublie...
  free(track);
}

sound_t *reduce_track(track_t *track) {
  sound_t *s = malloc(sizeof(sound_t));
  s->n_samples = 0;
  unsigned n = 1 << 8;
  s->samples = malloc(n * sizeof(short));
  for (unsigned i = 0; i < track->n_sounds; ++i) {
    unsigned n_samples = track->sounds[i]->n_samples;
    if (s->n_samples + n_samples > n) {
      while (s->n_samples + n_samples > n)
        n *= 2; // au cas où plus du double est nécéssaire
      s->samples = realloc(s->samples, n * sizeof(short));
    }
    for (unsigned j = 0; j < n_samples; ++j) {
      s->samples[s->n_samples + j] = track->sounds[i]->samples[j];
    }
    s->n_samples += n_samples;
  }

  s->samples = realloc(
      s->samples,
      s->n_samples * sizeof(short)); // pour ne pas utiliser trop de mémoire
  return s;
}

void free_mix(mix_t *mix) {
  for (unsigned i = 0; i < mix->n_tracks; ++i) {
    free_track(mix->tracks[i]);
  }
  free(mix->tracks); // :)
  free(mix->vols);
  free(mix);
}

sound_t *reduce_mix(mix_t *mix) {
  // générer chaque tracks
  sound_t **sound_list = malloc(mix->n_tracks * sizeof(sound_t *));
  unsigned samp_max = 0; // nombre d'échantillons maximum
  double vol_sum = 0;    // somme des volumes
  for (unsigned i = 0; i < mix->n_tracks; ++i) {
    vol_sum += mix->vols[i];
    sound_list[i] = reduce_track(mix->tracks[i]);
    if (sound_list[i]->n_samples > samp_max)
      samp_max = sound_list[i]->n_samples;
  }

  if (vol_sum == 0)
    vol_sum = 1; // pour éviter de diviser par 0 ???

  // sound à renvoyer
  sound_t *sound = malloc(sizeof(sound_t));
  sound->n_samples = samp_max;
  sound->samples = malloc(samp_max * sizeof(short));
  for (unsigned i = 0; i < samp_max; ++i) {
    double sample_sum = 0;
    // j'utilise un float et pas int car les volumes
    // sont des floats non?
    for (unsigned j = 0; j < mix->n_tracks; ++j) {
      if (sound_list[j]->n_samples > i)
        sample_sum += sound_list[j]->samples[i] *
                      mix->vols[j]; // valeur pondérée par le volume
    }
    sound->samples[i] = (short)(sample_sum / vol_sum); // moyenne
  }

  // libérer liste_sound
  for (unsigned i = 0; i < mix->n_tracks; ++i) {
    free_sound(sound_list[i]);
  }
  free(sound_list);

  return sound;
}
