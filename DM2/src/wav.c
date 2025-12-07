#include "wav.h"

void write_int(FILE* f, int a, int size)
{
    for (int i = 0; i < size; ++i)
    {
        fputc(a & 0xff, f); // équivalent à fprintf(f, "%c", a & 0xff); mais plus rapide
        a >>= 8;
    }
}

void write_header(FILE* f, int n)
{
    int l = L >> 3; // L/8
    fprintf(f, "RIFF");
    write_int(f, 36 + l * n, 4);
    fprintf(f, "WAVEfmt ");
    write_int(f, 16, 4);
    write_int(f, 1, 2);
    write_int(f, 1, 2);
    write_int(f, fe, 4);
    write_int(f, l * fe, 4);
    write_int(f, l, 2);
    write_int(f, L, 2);
    fprintf(f, "data");
    write_int(f, l * n, 4);
}

void save_sound(char* filename, sound_t* s)
{
    FILE* f= fopen(filename, "w");
    write_header(f, s->n_samples);
    for (int i = 0; i < s->n_samples; ++i)
    {
        write_int(f, s->samples[i], 2);
    }
    fclose(f);
}