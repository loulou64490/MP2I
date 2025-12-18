#include <stdlib.h>
#include "sound.h"
#include "wav.h"
#include "waveform.h"
#include "melody.h"

void test_8(void)
{
    short d[3] = {15387, 815, -6337};
    sound_t sound = {
        .n_samples = 3,
        .samples = d
    };

    save_sound("sound/test.wav", &sound);
}

void test_9(void)
{
    sound_t* sound = white(DEFAULT_LENGTH, SAMPLE_RATE);
    save_sound("sound/white.wav", sound);
    free_sound(sound);
}

void test_10(void)
{
    sound_t* sound = sine(DEFAULT_FREQUENCY, DEFAULT_AMPLITUDE, DEFAULT_LENGTH, SAMPLE_RATE);
    save_sound("sound/sine.wav", sound);
    free_sound(sound);
}

void test_11(void)
{
    sound_t* sound = square(DEFAULT_FREQUENCY, DEFAULT_AMPLITUDE, DEFAULT_LENGTH, SAMPLE_RATE);
    save_sound("sound/square.wav", sound);
    free_sound(sound);
    sound = triangle(DEFAULT_FREQUENCY, DEFAULT_AMPLITUDE, DEFAULT_LENGTH, SAMPLE_RATE);
    save_sound("sound/triangle.wav", sound);
    free_sound(sound);
    sound = sawtooth(DEFAULT_FREQUENCY, DEFAULT_AMPLITUDE, DEFAULT_LENGTH, SAMPLE_RATE);
    save_sound("sound/sawtooth.wav", sound);
    free_sound(sound);
}

void test_13(void)
{
    sound_t* s1 = sine(440, 0, 0.5, SAMPLE_RATE);
    sound_t* s2 = sine(440, 16000, 0.4, SAMPLE_RATE);
    sound_t* s3 = sine(440, 0, 0.1, SAMPLE_RATE);
    sound_t* s4 = sine(440, 16000, 0.4, SAMPLE_RATE);
    sound_t* s5 = sine(440, 0, 0.1, SAMPLE_RATE);
    sound_t* s6 = sine(440, 16000, 0.5, SAMPLE_RATE);
    sound_t* s7 = sine(493.88, 16000, 0.5, SAMPLE_RATE);
    sound_t* s8 = sine(554.36, 16000, 1, SAMPLE_RATE);
    sound_t* s9 = sine(493.88, 16000, 1, SAMPLE_RATE);

    sound_t* sound_list[9] = {s1, s2, s3, s4, s5, s6, s7, s8, s9};
    track_t t = {
        .n_sounds = 9,
        .sounds = sound_list
    };
    sound_t* sound = reduce_track(&t);
    save_sound("sound/clair.wav", sound);

    for (unsigned i = 0; i < 9; ++i)
    {
        free_sound(sound_list[i]);
    }
    free(sound->samples);
    free(sound);
}

void test_15(void)
{
    FILE* file = fopen("../archive/question_15/sonata_une_piste.txt", "r");
    track_t* track = read_track(file);
    sound_t* sound = reduce_track(track);
    save_sound("sound/sonata.wav", sound);
    free_sound(sound);
    free_track(track);
    fclose(file);
}

void test_19(void)
{
    mix_t* mix = load_mix("../archive/question_19/test1.txt");
    sound_t* sound = reduce_mix(mix);
    save_sound("sound/sonata2.wav", sound);
    free_sound(sound);
    free_mix(mix);
}

void test(void)
{
    test_8();
    test_9();
    test_10();
    test_11();
    test_13();
    test_15();
    test_19();
}
