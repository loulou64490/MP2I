#include "base.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int mediane(int *T, int a, int b) {
  int m = (a + b) / 2;
  if ((T[b] <= T[a] && T[a] <= T[m]) || (T[b] >= T[a] && T[a] >= T[m]))
    return a;
  else if ((T[a] <= T[b] && T[b] <= T[m]) || (T[a] >= T[b] && T[b] >= T[m]))
    return b;
  return m;
}

void tri_rapide_entre(int *T, int a, int b) {
  if (a < b) {
    int p = partition_entre(T, a, b);
    // on récupère la valeur médiane
    // et on l'échange avec notre premier élément
    // pour en faire notre pivot :)
    echanger(T, a, mediane(T, a, p - 1));
    tri_rapide_entre(T, a, p - 1);
    echanger(T, p + 1, mediane(T, p + 1, b));
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

  FILE *f = fopen("sortie/mediane.txt", "w");
  for (int i = 1; i <= 40; ++i) {
    fprintf(f, "%f\n", test_tri_rapide(i * 100));
  }
  fclose(f);
}
