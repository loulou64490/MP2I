#include "base.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void tri_hybride_entre(int *T, int a, int b, int K) {
  if (b - a + 1 > K) {
    int p = partition_entre(T, a, b);
    tri_hybride_entre(T, a, p - 1, K);
    tri_hybride_entre(T, p + 1, b, K);
  } else {
    tri_insertion(&T[a], b - a + 1); //
    // &T[a] donne T à partir de la case a
    // b-a+1 est la taille du tableau
  }
}

void tri_hybride(int *T, int n, int K) { tri_hybride_entre(T, 0, n - 1, K); }

float test_tri_hybride(int n, int K) {
  int *L[20];
  for (int i = 0; i < 20; ++i) {
    L[i] = genere_tab(n);
  }
  float c = clock();
  for (int i = 0; i < 20; ++i) {
    tri_hybride(L[i], n, K);
  }
  c = clock() - c;
  for (int i = 0; i < 20; ++i)
    free(L[i]);
  return c / (20 * CLOCKS_PER_SEC);
}

int main(int argc, char **argv) {
  srand(time(NULL));
  int K = 100;
  
  // pour tester différente valeur de K
  // menfiche si c'est pas optimisé
  // j'avais la flemme de trop réfléchir
  if (argc == 2) {
    sscanf(argv[1], "%d", &K);
    FILE *f1 = fopen("sortie/hybride.txt", "w");
    for (int i = 1; i <= 10; ++i) {
      fprintf(f1, "%f\n", test_tri_hybride(i * 10000, K));
    }
    fclose(f1);
    return 0;
  }

  FILE *f1 = fopen("sortie/hybride.txt", "w");
  FILE *f2 = fopen("sortie/rapide.txt", "w");
  for (int i = 1; i <= 10; ++i) {
    fprintf(f1, "%f\n", test_tri_hybride(i * 10000, K));
    fprintf(f2, "%f\n",
            test_tri_hybride(i * 10000, 1)); // K=1 correspond au tri rapide
  }
  fclose(f1);
  fclose(f2);
}
