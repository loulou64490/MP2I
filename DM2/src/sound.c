#include <stdlib.h>
#include "sound.h"


void free_s(sound_t* s)
{
    free(s->samples);
    free(s);
}

void free_t(track_t* t)
{
    for (int i = 0; i < t->n_sounds; ++i)
    {
        free_s(t->sounds[i]);
    }
    free(t->sounds);
    free(t);
}

sound_t* reduce_track(track_t* t)
{
    sound_t* s = malloc(sizeof(track_t));
    s->n_samples = 0;
    int n = 1 << 16;
    s->samples = malloc(n * sizeof(int16_t));
    for (int i = 0; i < t->n_sounds; ++i)
    {
        const int ns = t->sounds[i]->n_samples;
        while (s->n_samples + ns > n)
        {
            s->samples = realloc(s->samples, (n *= 2) * sizeof(int16_t));
        }
        for (int j = 0; j < ns; ++j)
        {
            s->samples[s->n_samples + j] = t->sounds[i]->samples[j];
        }
        s->n_samples += ns;
    }
    s->samples = realloc(s->samples, s->n_samples * sizeof(int16_t)); // pour ne pas utiliser trop de mémoire
    return s;
}
