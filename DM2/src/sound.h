#pragma once
#include <stdint.h>

static const int L = 16, fe = 44100, Ae = 10000;
static const double Te = 5, ff = 440;

typedef struct sound
{
    int n_samples; // nombre d'échantillons
    int16_t* samples; // tableau des échantillons
} sound_t;

/*libère un élément sound_t* */
void free_s(sound_t* s);

typedef struct track
{
    int n_sounds; // nombre de son dans la piste
    sound_t** sounds; // liste des sons
} track_t;

/*libère un élément track_t* */
void free_t(track_t* t);

/* transforme une piste en un unique son */
sound_t* reduce_track(track_t* t);