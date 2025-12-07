#pragma once
#include <stdint.h>

static const int L = 16, fe = 44100;

typedef struct sound
{
    int n_samples; // nombre d'échantillons
    int16_t* samples; // tableau des échantillons
} sound_t;

/*libère un élément sound_t* */
void free_s(sound_t* s);
