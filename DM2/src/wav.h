#pragma once
#include "sound.h"
#include <stdio.h>

/* écrit un entier a de size octets en little-endian*/
void write_int(FILE *file, int a, unsigned size);

/* écrit l’entête d’un fichier WAV de n échantillons */
void write_header(FILE *file, unsigned n);

/* sauvegarde un son sound_t* s dans un fichier nommé filename */
void save_sound(char *filename, sound_t *sound);
