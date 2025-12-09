#include "melody.h"
#include "sound.h"
#include "waveform.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double pitch_to_freq(int n) { return 440 * pow(2, (double)n / 12); }

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
        default: t->sounds[i] = sine(pitch_to_freq(n), v * Ae, d, fe);
        case 1: t->sounds[i] = square(pitch_to_freq(n), v * Ae, d, fe);
        case 2: t->sounds[i] = triangle(pitch_to_freq(n), v * Ae, d, fe);
        case 3: t->sounds[i] = sawtooth(pitch_to_freq(n), v * Ae, d, fe);
        }
    }
    return t;
}
