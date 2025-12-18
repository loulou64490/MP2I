#include "wav.h"

void write_int(FILE* file, int a,  unsigned size)
{
    for (unsigned i = 0; i < size; ++i)
    {
        fputc(a & 0xff, file); // équivalent à fprintf(f, "%c", a & 0xff); mais plus rapide
        a >>= 8; // a / 256
    }
}

void write_header(FILE* file,  unsigned n)
{
    unsigned l = BITS >> 3; // BITS/8
    fprintf(file, "RIFF");
    write_int(file, (int)(36 + l * n), 4);
    fprintf(file, "WAVEfmt ");
    write_int(file, 16, 4);
    write_int(file, 1, 2);
    write_int(file, 1, 2);
    write_int(file, (int)SAMPLE_RATE, 4);
    write_int(file, (int)(l * SAMPLE_RATE), 4);
    write_int(file, (int)l, 2);
    write_int(file, (int)BITS, 2);
    fprintf(file, "data");
    write_int(file, (int)(l * n), 4);
}

void save_sound( char* filename,  sound_t* sound)
{
    FILE* file = fopen(filename, "wb"); // write bits
    write_header(file, sound->n_samples);
    for (unsigned i = 0; i < sound->n_samples; ++i)
    {
        write_int(file, sound->samples[i], 2);
    }
    fclose(file);
}
