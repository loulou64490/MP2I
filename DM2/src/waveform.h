#pragma once
#include "sound.h"

/* génère un bruit blanc */
sound_t *white(double length, unsigned sample_rate);

/* génère un unique sample */
short sample(char signal, double frequency, unsigned sample_rate,
             double amplitude, double omega, unsigned i);

/* génère un son
 * signal: 0 blanc, default 1 sinusoïdal, 2 créneaux, 3 triangle, 4 dent de scie
 */
sound_t *waveform(char signal, double frequency, double length,
                  unsigned sample_rate, double attack, double decay,
                  double sustain, double release);
