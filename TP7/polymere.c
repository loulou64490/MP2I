#include "pile.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *taille_stable(char *polymere) {
  pile_t *p = pile_vide();
  empiler(p, polymere[0]);
  int n = strlen(polymere);
  for (int i = 1; i < n; ++i) {
    char c = depiler(p);
    if (abs(c - polymere[i]) != 32) {
      empiler(p, c);
      empiler(p, polymere[i]);
    }
  }
  int t = taille_pile(p);
  char *s = malloc((t + 1) * sizeof(char));
  for (int i = t - 1; i >= 0; --i)
    s[i] = depiler(p);
  s[t] = 0;
  free_pile(p);
  return s;
}

int main() {
  FILE *f = fopen("polymere.txt", "r");
  char *polymere;
  size_t n;
  getline(&polymere, &n, f);

  char *polymere_stable = taille_stable(polymere);

  printf("%s", polymere_stable);

  free(polymere);
  free(polymere_stable);
  fclose(f);
}
