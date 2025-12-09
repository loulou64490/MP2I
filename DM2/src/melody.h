#pragma once
#include <stdio.h>
#include "sound.h"

/* calcule la fréquence associée à la hauteur de note n */
double pitch_to_freq(int n);

/* crée une piste à partir d’un fichier */
track_t* read_track(FILE* f);