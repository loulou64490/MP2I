#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "base.h"

float test_tri_insertion(int n) {
  int *L[20];
  for (int i = 0; i < 20; ++i) {
    L[i] = genere_tab(n);
  }
  float c = clock();
  for (int i = 0; i < 20; ++i) {
    tri_insertion(L[i], n);
  }
  c = clock() - c;
  for (int i = 0; i < 20; ++i)
    free(L[i]);
  return c / (20 * CLOCKS_PER_SEC);
}

int main() {
  srand(time(NULL));

  FILE *f = fopen("sortie/insertion.txt", "w");
  for (int i = 1; i <= 40; ++i) {
    fprintf(f, "%f\n", test_tri_insertion(i * 100));
  }
  fclose(f);
}