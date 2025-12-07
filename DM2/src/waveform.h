#pragma once
#include "sound.h"

/* génère un bruit blanc de durée T (en secondes) et de fréquence d’échantillonnage f_ech */
sound_t* white(float T, int f_ech);
