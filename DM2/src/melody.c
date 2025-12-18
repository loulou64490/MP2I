#include "melody.h"

#include <assert.h>

#include "sound.h"
#include "waveform.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double pitch_to_freq(int pitch) { return 440 * pow(2, (double)pitch / 12); }

track_t* read_track(FILE* file)
{
    track_t* track = malloc(sizeof(track_t));

    char str_signal[9]; // pour récupérer le nom du signal
    fscanf(file, "%u %8s", &track->n_sounds, str_signal);
    unsigned signal = 0;
    if (strcmp(str_signal, "square") == 0) signal = 1;
    if (strcmp(str_signal, "triangle") == 0) signal = 2;
    if (strcmp(str_signal, "sawtooth") == 0) signal = 3;

    track->sounds = malloc(track->n_sounds * sizeof(sound_t*));
    int pitch;
    double length, volume;
    for (unsigned i = 0; i < track->n_sounds; ++i)
    {
        fscanf(file, "%d %lf %lf", &pitch, &length, &volume);

        // j’ai vu qu’il existait des macros pour simplifier ce genre de if... mais c’est vraiment hors-programme
        if (signal == 1)
        {
            track->sounds[i] = square(pitch_to_freq(pitch), volume * DEFAULT_AMPLITUDE, length,
                                      SAMPLE_RATE);
        }
        else if (signal == 2)
        {
            track->sounds[i] = triangle(pitch_to_freq(pitch), volume * DEFAULT_AMPLITUDE, length,
                                        SAMPLE_RATE);
        }
        else if (signal == 3)
        {
            track->sounds[i] = sawtooth(pitch_to_freq(pitch), volume * DEFAULT_AMPLITUDE, length,
                                        SAMPLE_RATE);
        }
        else
        {
            track->sounds[i] = sine(pitch_to_freq(pitch), volume * DEFAULT_AMPLITUDE, length,
                                    SAMPLE_RATE);
        }
    }
    return track;
}

mix_t* load_mix(char* filename)
{
    mix_t* mix = malloc(sizeof(mix_t));
    FILE* f = fopen(filename, "r");
    if (!f)
    {
        fprintf(stderr, "Erreur : le fichier %s n'existe pas !\n", filename);
        exit(EXIT_FAILURE);
    }
    fscanf(f, "%d", &mix->n_tracks);
    mix->vols = malloc(mix->n_tracks * sizeof(double));
    for (unsigned i = 0; i < mix->n_tracks; ++i)
    {
        fscanf(f, "%lf", &mix->vols[i]);
    }
    mix->tracks = malloc(mix->n_tracks * sizeof(track_t*));
    for (unsigned i = 0; i < mix->n_tracks; ++i)
    {
        mix->tracks[i] = read_track(f);
    }
    fclose(f);
    return mix;
}
