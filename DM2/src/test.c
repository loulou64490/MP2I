#include "sound.h"
#include "wav.h"
#include "waveform.h"

void test(void) {
  sound_t *sound =
      waveform(1, DEFAULT_FREQUENCY, DEFAULT_LENGTH, SAMPLE_RATE,
               DEFAULT_ATTACK, DEFAULT_DECAY, DEFAULT_SUSTAIN, DEFAULT_RELEASE);
  save_sound("output/sound.wav", sound);
  free_sound(sound);
}
