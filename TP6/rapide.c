#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "base.h"

void tri_rapide_entre(int *T, int a, int b) {
  if (a < b) {
    int p = partition_entre(T, a, b);
    tri_rapide_entre(T, a, p - 1);
    tri_rapide_entre(T, p + 1, b);
  }
}

void tri_rapide(int *T, int n) { tri_rapide_entre(T, 0, n - 1); }

float test_tri_rapide(int n) {
  int *L[20];
  for (int i = 0; i < 20; ++i) {
    L[i] = genere_tab(n);
  }
  float c = clock();
  for (int i = 0; i < 20; ++i) {
    tri_rapide(L[i], n);
  }
  c = clock() - c;
  for (int i = 0; i < 20; ++i)
    free(L[i]);
  return c / (20 * CLOCKS_PER_SEC);
}

int main() {
  srand(time(NULL));

  FILE *f = fopen("sortie/rapide.txt", "w");
  for (int i = 1; i <= 40; ++i) {
    fprintf(f, "%f\n", test_tri_rapide(i * 100));
  }
  fclose(f);
}
