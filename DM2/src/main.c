#include "sound.h"
#include "wav.h"
#include "waveform.h"

void test_8()
{
    int16_t d[3] = {15387, 815, -6337};
    sound_t s = {
        .n_samples = 3,
        .samples = d
    };

    save_sound("test.wav", &s);
}

void test_9()
{
    sound_t* s = white(5, fe);
    save_sound("test.wav", s);
    free_s(s);
}

int main(void)
{
    // test_8();
    // test_9();
}
