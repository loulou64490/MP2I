#include "melody.h"
#include "sound.h"
#include "waveform.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void error() {
  fprintf(stderr, "Erreur : un fichier est mal encodé\n");
  exit(EXIT_FAILURE);
}

double pitch_to_freq(int pitch) { return 440 * pow(2, (double)pitch / 12); }

track_t *read_track(FILE *file) {
  track_t *track = malloc(sizeof(track_t));

  char str_signal[9]; // pour récupérer le nom du signal
  if (fscanf(file, "%u %8s", &track->n_sounds, str_signal) != 2)
    error();
  char signal = 1;
  if (strcmp(str_signal, "square") == 0)
    signal = 2;
  if (strcmp(str_signal, "triangle") == 0)
    signal = 3;
  if (strcmp(str_signal, "sawtooth") == 0)
    signal = 4;

  track->sounds = malloc(track->n_sounds * sizeof(sound_t *));
  int pitch;
  double length, sustain;
  for (unsigned i = 0; i < track->n_sounds; ++i) {
    if (fscanf(file, "%d %lf %lf", &pitch, &length, &sustain) != 3)
      error();

    track->sounds[i] =
        waveform(signal, pitch_to_freq(pitch), length, SAMPLE_RATE,
                 DEFAULT_ATTACK, DEFAULT_DECAY, sustain, DEFAULT_RELEASE);
  }
  return track;
}

mix_t *load_mix(char *filename) {
  mix_t *mix = malloc(sizeof(mix_t));
  FILE *f = fopen(filename, "r");
  if (!f) {
    fprintf(stderr, "Erreur : le fichier %s n'existe pas !\n", filename);
    exit(EXIT_FAILURE);
  }
  if (fscanf(f, "%d", &mix->n_tracks) != 1)
    error();
  mix->vols = malloc(mix->n_tracks * sizeof(double));
  for (unsigned i = 0; i < mix->n_tracks; ++i) {
    if (fscanf(f, "%lf", &mix->vols[i]) != 1)
      error();
  }
  mix->tracks = malloc(mix->n_tracks * sizeof(track_t *));
  for (unsigned i = 0; i < mix->n_tracks; ++i) {
    mix->tracks[i] = read_track(f);
  }
  fclose(f);
  return mix;
}
