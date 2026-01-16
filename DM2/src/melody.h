#pragma once
#include "sound.h"
#include <stdio.h>

/* stop le programme pour une erreur d'encode de fichier */
void error();

/* calcule la fréquence associée à la hauteur */
double pitch_to_freq(int pitch);

/* crée une piste à partir d’un fichier */
track_t *read_track(FILE *file);

/* crée un mix à partir d’un fichier */
mix_t *load_mix(char *filename);
