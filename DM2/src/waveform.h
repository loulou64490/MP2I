#pragma once
#include "sound.h"

/* génère un bruit blanc */
sound_t* white(double length, unsigned sample_rate);

/* renvoie un son sinusoïdal de fréquence */
sound_t* sine(double frequency, double amplitude, double length, unsigned sample_rate);

/* renvoie un son en créneaux */
sound_t* square(double frequency, double amplitude, double length, unsigned sample_rate);

/* renvoie un son en triangle */
sound_t* triangle(double frequency, double amplitude, double length, unsigned sample_rate);

/* renvoie un son en dent de scie */
sound_t* sawtooth(double frequency, double amplitude, double length, unsigned sample_rate);
