#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include "sound.h"
#include "waveform.h"

sound_t* white(float T, int f_ech)
{
    sound_t* s = malloc(sizeof(sound_t));
    s->n_samples = T * f_ech;
    s->samples = malloc(s->n_samples * sizeof(int16_t));
    for (int i = 0; i < s->n_samples; ++i)
    {
        s->samples[i] = rand() % (2 * Ae) - Ae;
    }
    return s;
}

sound_t* sine(float f, int A, float T, int f_ech)
{
    sound_t* s = malloc(sizeof(sound_t));
    s->n_samples = T * f_ech;
    s->samples = malloc(s->n_samples * sizeof(int16_t));
    for (int i = 0; i < s->n_samples; ++i)
    {
        s->samples[i] = A * sin(2 * M_PI * f * i / f_ech);
    }
    return s;
}

sound_t* square(float f, int A, float T, int f_ech)
{
    sound_t* s = malloc(sizeof(sound_t));
    s->n_samples = T * f_ech;
    s->samples = malloc(s->n_samples * sizeof(int16_t));
    for (int i = 0; i < s->n_samples; ++i)
    {
        float x = f * i / f_ech;
        s->samples[i] = A * (2 * (floor(x) - floor(x - 0.5)) - 1);
    }
    return s;
}

sound_t* triangle(float f, int A, float T, int f_ech)
{
    sound_t* s = malloc(sizeof(sound_t));
    s->n_samples = T * f_ech;
    s->samples = malloc(s->n_samples * sizeof(int16_t));
    for (int i = 0; i < s->n_samples; ++i)
    {
        s->samples[i] = A * 2 / M_PI * asin(sin(2 * M_PI * f * i / f_ech));
    }
    return s;
}

sound_t* sawtooth(float f, int A, float T, int f_ech)
{
    sound_t* s = malloc(sizeof(sound_t));
    s->n_samples = T * f_ech;
    s->samples = malloc(s->n_samples * sizeof(int16_t));
    for (int i = 0; i < s->n_samples; ++i)
    {
        float x = f * i / f_ech - 0.5;
        s->samples[i] = A * (2 * (x - floor(x)) - 1);
    }
    return s;
}
