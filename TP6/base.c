#include <stdbool.h>
#include <stdlib.h>

void tri_insertion(int *T, int n) {
  for (int i = 1; i < n; ++i) {
    int x = T[i];
    int j = i;
    while (j > 0 && T[j - 1] > x) {
      T[j] = T[j - 1];
      j -= 1;
    }
    T[j] = x;
  }
}

bool est_trie(int *T, int n) {
  for (int i = 0; i < n - 1; ++i) {
    if (T[i] > T[i + 1])
      return false;
  }
  return true;
}

int *genere_tab(int n) {
  int *T = malloc(n * sizeof(int));
  for (int i = 0; i < n; ++i) {
    T[i] = rand();
  }
  return T;
}

void echanger(int *T, int a, int b) {
  int x = T[a];
  T[a] = T[b];
  T[b] = x;
}

int partition_entre(int *T, int a, int b) {
  int i = a + 1, s = b;
  while (i <= s) {
    if (T[i] <= T[a]) {
      i++;
    } else {
      echanger(T, s, i);
      s--;
    }
  }
  echanger(T, a, s);
  return s;
}
