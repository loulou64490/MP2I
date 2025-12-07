#include <stdlib.h>
#include <stdint.h>
#include "sound.h"
#include "waveform.h"

sound_t* white(float T, int f_ech)
{
    sound_t* s = malloc(sizeof(sound_t));
    s->n_samples = T * f_ech;
    s->samples = malloc(s->n_samples * sizeof(int16_t));
    for (int i = 0; i < s->n_samples; ++i)
    {
        s->samples[i] = (rand() & ((1 << L) - 1)) - (1 << (L - 1));
    }
    return s;
}
