#include "waveform.h"
#include "sound.h"
#include <math.h>
#include <stdint.h>
#include <stdlib.h>

short sample(char signal, double frequency, unsigned sample_rate,
             double amplitude, double omega, unsigned i) {
  double x;
  switch (signal) {
  case 0: // white
    return (short)(rand() % (short)(2 * amplitude) - amplitude);
  case 1: // sine
  default:
    return (short)(amplitude * sin(omega * i));
  case 2: // square
    x = frequency * i / sample_rate;
    return (short)(amplitude * (2 * (floor(x) - floor(x - 0.5)) - 1));
  case 3: // triangle
    return (short)(amplitude * 2 * asin(sin(omega * i) / M_PI));
  case 4: // sawtooth
    x = frequency * i / sample_rate - 0.5;
    return (short)(amplitude * (2 * (x - floor(x)) - 1));
  }
}

sound_t *waveform(char signal, double frequency, double length,
                  unsigned sample_rate, double attack, double decay,
                  double sustain, double release) {

  // constantes
  unsigned n_samples = (unsigned)(length * sample_rate);
  unsigned n_attack = (unsigned)(attack * sample_rate);
  unsigned n_decay = (unsigned)(decay * sample_rate);
  unsigned n_release = (unsigned)(release * sample_rate);
  unsigned n_length = n_samples - n_release;

  sound_t *sound = malloc(sizeof(sound_t));
  sound->n_samples = n_samples;
  sound->samples = malloc(n_samples * sizeof(short));

  // s'il n'y a pas de son ou que le release est supérieur à la durée du son
  if (sustain == 0 || n_release > n_samples) {
    for (unsigned i = 0; i < n_samples; ++i) {
      sound->samples[i] = 0;
    }
    return sound;
  }

  double omega = 2 * M_PI * frequency / sample_rate;
  unsigned i = 0;
  double
      amp; // pour sauvegarder la dernière amplitude, pour le release à la fin

  // attack
  while (i < n_attack && i < n_length) {
    amp = (double)i / n_attack;
    sound->samples[i] = sample(signal, frequency, sample_rate,
                               DEFAULT_AMPLITUDE * amp, omega, i);
    i++;
  }

  // decay
  unsigned n_temp = n_decay + n_attack;
  while (i < n_temp && i < n_length) {
    amp = ((1 - sustain) * (n_temp - i) / n_decay + sustain);
    sound->samples[i] = sample(signal, frequency, sample_rate,
                               DEFAULT_AMPLITUDE * amp, omega, i);
    i++;
  }

  if (i < n_length) {
    amp = sustain;
  }

  // sustain
  while (i < n_length) {
    sound->samples[i] = sample(signal, frequency, sample_rate,
                               DEFAULT_AMPLITUDE * sustain, omega, i);
    i++;
  }

  // release
  while (i < n_samples) {
    sound->samples[i] =
        sample(signal, frequency, sample_rate,
               DEFAULT_AMPLITUDE * amp * (n_samples - i) / n_release, omega, i);
    i++;
  }

  return sound;
}
