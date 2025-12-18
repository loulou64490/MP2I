#pragma once
#include <stdio.h>
#include "sound.h"

/* calcule la fréquence associée à la hauteur */
double pitch_to_freq(int pitch);

/* crée une piste à partir d’un fichier */
track_t* read_track(FILE* file);

/* crée un mix à partir d’un fichier */
mix_t* load_mix(char* filename);
