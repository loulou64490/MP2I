#pragma once
#include "sound.h"

/* génère un bruit blanc de durée T (en secondes) et de fréquence d’échantillonnage f_ech */
sound_t* white(double T, int f_ech);

/* renvoie un son sinusoïdal de fréquence f, d'amplitude A, de durée T (en secondes)
 * et de fréquence d’échantillonnage f_ech
 */
sound_t* sine(double f, int A, double T, int f_ech);

/* renvoie un son en créneaux */
sound_t* square(double f, int A, double T, int f_ech);

/* renvoie un son en triangle */
sound_t* triangle(double f, int A, double T, int f_ech);

/* renvoie un son en dent de scie */
sound_t* sawtooth(double f, int A, double T, int f_ech);
