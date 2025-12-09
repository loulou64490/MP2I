#include <stdlib.h>
#include "sound.h"
#include "wav.h"
#include "waveform.h"
#include "melody.h"

void test_8()
{
    int16_t d[3] = {15387, 815, -6337};
    sound_t s = {
        .n_samples = 3,
        .samples = d
    };

    save_sound("sound/test.wav", &s);
}

void test_9()
{
    sound_t* s = white(Te, fe);
    save_sound("sound/white.wav", s);
    free_s(s);
}

void test_10()
{
    sound_t* s = sine(ff, Ae, Te, fe);
    save_sound("sound/sine.wav", s);
    free_s(s);
}

void test_11()
{
    sound_t* s = square(ff, Ae, Te, fe);
    save_sound("sound/square.wav", s);
    free_s(s);
    s = triangle(ff, Ae, Te, fe);
    save_sound("sound/triangle.wav", s);
    free_s(s);
    s = sawtooth(ff, Ae, Te, fe);
    save_sound("sound/sawtooth.wav", s);
    free_s(s);
}

void test_13()
{
    sound_t* s1 = sine(440, 0, 0.5, fe);
    sound_t* s2 = sine(440, 16000, 0.4, fe);
    sound_t* s3 = sine(440, 0, 0.1, fe);
    sound_t* s4 = sine(440, 16000, 0.4, fe);
    sound_t* s5 = sine(440, 0, 0.1, fe);
    sound_t* s6 = sine(440, 16000, 0.5, fe);
    sound_t* s7 = sine(493.88, 16000, 0.5, fe);
    sound_t* s8 = sine(554.36, 16000, 1, fe);
    sound_t* s9 = sine(493.88, 16000, 1, fe);

    sound_t* st[9] = {s1, s2, s3, s4, s5, s6, s7, s8, s9};
    track_t t = {
        .n_sounds = 9,
        .sounds = st
    };
    sound_t* s = reduce_track(&t);
    save_sound("sound/clair.wav", s);

    for (int i = 0; i < 9; ++i)
    {
        free_s(st[i]);
    }
    free(s->samples);
    free(s);
}

void test_15()
{
    FILE* f = fopen("../archive/question_15/sonata_une_piste.txt", "r");
    track_t* t = read_track(f);
    sound_t* s = reduce_track(t);
    save_sound("sound/sonata.wav", s);
    free_s(s);
    free_t(t);
    fclose(f);
}

int main(void)
{
    // test_8();
    // test_9();
    // test_10();
    // test_11();
    // test_13();
    test_15();
}
