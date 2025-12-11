#pragma once
#include <stdint.h>

static const int L = 16, fe = 44100, Ae = 16000;
static const float Te = 5, ff = 440;

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

typedef struct mix
{
    int n_tracks; // nombre de pistes
    track_t** tracks; // liste des pistes
    float* vols; // liste des volumes des pistes
} mix_t;

/*libère un élément mix_t* */
void free_m(mix_t* m);

/* transforme un mix en son */
sound_t* reduce_mix(mix_t* m);
