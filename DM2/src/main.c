#include "melody.h"
#include "sound.h"
#include "test.h"
#include "wav.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*

*/

/* scan un float dans une chaine de caractère */
double scan_float(char *s) {
  double v;
  if (sscanf(s, "%lf", &v) != 1) {
    fprintf(stderr, "Erreur : paramètres incorrects\n");
    exit(EXIT_FAILURE);
  }
  return v;
}

int main(int argc, char **argv) {
  if (argc == 1) {
    test();
    printf("Test générés !");
    return 0;
  }

  if (argc == 6) {
    DEFAULT_ATTACK = scan_float(argv[3]);
    DEFAULT_DECAY = scan_float(argv[4]);
    DEFAULT_RELEASE = scan_float(argv[5]);
  } else if (argc != 3) {
    fprintf(stderr, "Erreur : paramètres incorrects\n");
    exit(EXIT_FAILURE);
  }

  long time = clock();

  // génération du son
  mix_t *mix = load_mix(argv[1]);
  sound_t *sound = reduce_mix(mix);
  save_sound(argv[2], sound);

  unsigned length = sound->n_samples / SAMPLE_RATE;
  printf("Fichier %s généré (temps écoulé: %.2fs)\n", argv[2],
         (double)(clock() - time) / CLOCKS_PER_SEC);
  printf("Durée du fichier: %um%us (taille %.1fMo)", length / 60, length % 60,
         (double)sound->n_samples / 500000);
  // taille en Mo: (n_samples * 16 bits) / (8 bits * 1000000) = n_samples /
  // 500000

  free_sound(sound);
  free_mix(mix);
}
