#include <stdlib.h>
#include "sound.h"

#include "wav.h"


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

void free_m(mix_t* m)
{
    for (int i = 0; i < m->n_tracks; ++i)
    {
        free_t(m->tracks[i]);
    }
    free(m->tracks);
    free(m->vols);
    free(m);
}

sound_t* reduce_mix(mix_t* m)
{
    // générer chaque tracks
    sound_t** ls = malloc(m->n_tracks * sizeof(sound_t*));
    int me = 0; // nombre d'échantillons maximum
    float sv = 0; // somme des volumes
    for (int i = 0; i < m->n_tracks; ++i)
    {
        sv += m->vols[i];
        ls[i] = reduce_track(m->tracks[i]);
        if (ls[i]->n_samples > me) me = ls[i]->n_samples;
    }

    // sound à renvoyer
    sound_t* s = malloc(sizeof(sound_t));
    s->n_samples = me;
    s->samples = malloc(me * sizeof(int16_t));
    for (int i = 0; i < me; ++i)
    {
        float se = 0; // somme des échantillons
        // j'utilise un float et pas int car les volumes
        // sont des floats non?
        for (int j = 0; j < m->n_tracks; ++j)
        {
            if (ls[j]->n_samples > i)
                se += ls[j]->samples[i] * m->vols[j]; // valeur pondérée par le volume
        }
        s->samples[i] = se / sv; // moyenne
    }

    // libérer ls
    for (int i = 0; i < m->n_tracks; ++i)
    {
        free_s(ls[i]);
    }
    free(ls);

    return s;
}
