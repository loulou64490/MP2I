#pragma once
#include <stdio.h>
#include "sound.h"

/* écrit un entier a de size octets en little-indian*/
void write_int(FILE* f, int a, int size);

/* écrit l’entête d’un fichier WAV de n échantillons */
void write_header(FILE* f, int n);

/* sauvegarde un son sound_t* s dans un fichier nommé filename */
void save_sound(char* filename, sound_t* s);
