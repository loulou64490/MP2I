#include <stdlib.h>
#include "sound.h"


void free_s(sound_t* s)
{
    free(s->samples);
    free(s);
}

