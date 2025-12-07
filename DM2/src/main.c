#include "sound.h"
#include "wav.h"

void test_8()
{
    int16_t d[3] = {15387, 815, -6337};
    sound_t s={
        .n_samples = 3,
        .samples = d
    };

    save_sound("test.wav", &s);
}

int main(void)
{
    // test_8();

}
