#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include "sound.h"
#include "waveform.h"

// c'est cinq fois la même fonction…

sound_t* white(double length, unsigned sample_rate)
{
    sound_t* sound = malloc(sizeof(sound_t));
    sound->n_samples = (unsigned)(length * sample_rate);
    sound->samples = malloc(sound->n_samples * sizeof(short));
    for (unsigned i = 0; i < sound->n_samples; ++i)
    {
        sound->samples[i] = (short)(rand() % (short)(2 * DEFAULT_AMPLITUDE) - DEFAULT_AMPLITUDE);
    }
    return sound;
}

sound_t* sine(double frequency, double amplitude, double length, unsigned sample_rate)
{
    sound_t* sound = malloc(sizeof(sound_t));
    sound->n_samples = (unsigned)(length * sample_rate);
    sound->samples = malloc(sound->n_samples * sizeof(short));
    double omega = 2 * M_PI * frequency / sample_rate; // calcul des constantes avant
    for (unsigned i = 0; i < sound->n_samples; ++i)
    {
        sound->samples[i] = (short)(amplitude * sin(omega * i));
    }
    return sound;
}

sound_t* square(double frequency, double amplitude, double length, unsigned sample_rate)
{
    sound_t* sound = malloc(sizeof(sound_t));
    sound->n_samples = (unsigned)(length * sample_rate);
    sound->samples = malloc(sound->n_samples * sizeof(short));
    for (unsigned i = 0; i < sound->n_samples; ++i)
    {
        double x = frequency * i / sample_rate;
        sound->samples[i] = (short)(amplitude * (2 * (floor(x) - floor(x - 0.5)) - 1));
    }
    return sound;
}

sound_t* triangle(double frequency, double amplitude, double length, unsigned sample_rate)
{
    sound_t* sound = malloc(sizeof(sound_t));
    sound->n_samples = (unsigned)(length * sample_rate);
    sound->samples = malloc(sound->n_samples * sizeof(short));
    double amp = amplitude * 2 / M_PI, omega = 2 * M_PI * frequency / sample_rate; // pareil
    for (unsigned i = 0; i < sound->n_samples; ++i)
    {
        sound->samples[i] = (short)(amp * asin(sin(omega * i)));
    }
    return sound;
}

sound_t* sawtooth(double frequency, double amplitude, double length, unsigned sample_rate)
{
    sound_t* sound = malloc(sizeof(sound_t));
    sound->n_samples = (unsigned)(length * sample_rate);
    sound->samples = malloc(sound->n_samples * sizeof(short));
    for (unsigned i = 0; i < sound->n_samples; ++i)
    {
        double x = frequency * i / sample_rate - 0.5;
        sound->samples[i] = (short)(amplitude * (2 * (x - floor(x)) - 1));
    }
    return sound;
}
