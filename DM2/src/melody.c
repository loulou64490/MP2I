#include "melody.h"

#include <assert.h>

#include "sound.h"
#include "waveform.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float pitch_to_freq(int n) { return 440 * pow(2, (float)n / 12); }

track_t* read_track(FILE* f)
{
    track_t* t = malloc(sizeof(track_t));
    char sg[9];
    fscanf(f, "%d %8s", &t->n_sounds, sg);
    int s = 0;
    if (strcmp(sg, "square") == 0) s = 1;
    if (strcmp(sg, "triangle") == 0) s = 2;
    if (strcmp(sg, "sawtooth") == 0) s = 3;
    t->sounds = malloc(t->n_sounds * sizeof(sound_t*));
    int n; // hauteur
    float d, v; // volume durée
    for (int i = 0; i < t->n_sounds; ++i)
    {
        fscanf(f, "%d %f %f", &n, &d, &v);
        switch (s)
        {
        case 0:
        default:
            t->sounds[i] = sine(pitch_to_freq(n), v * Ae, d, fe);
            break;
        case 1:
            t->sounds[i] = square(pitch_to_freq(n), v * Ae, d, fe);
            break;
        case 2:
            t->sounds[i] = triangle(pitch_to_freq(n), v * Ae, d, fe);
            break;
        case 3:
            t->sounds[i] = sawtooth(pitch_to_freq(n), v * Ae, d, fe);
            break;
        }
    }
    return t;
}

mix_t* load_mix(char* filename)
{
    mix_t* m = malloc(sizeof(mix_t));
    FILE* f = fopen(filename, "r");
    if (!f)
    {
        fprintf(stderr, "Erreur : le fichier %s n'existe pas !\n", filename);
        exit(EXIT_FAILURE);
    }
    fscanf(f, "%d", &m->n_tracks);
    m->vols = malloc(m->n_tracks * sizeof(float));
    for (int i = 0; i < m->n_tracks; ++i)
    {
        fscanf(f, "%f", &m->vols[i]);
    }
    m->tracks = malloc(m->n_tracks * sizeof(track_t*));
    for (int i = 0; i < m->n_tracks; ++i)
    {
        m->tracks[i] = read_track(f);
    }
    fclose(f);
    return m;
}
