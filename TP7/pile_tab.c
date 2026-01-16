/* Implémentation des piles par tableaux */
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "pile.h"

struct pile {
  int taille;
  int nb_elem;
  int *tab;
};

pile_t *pile_vide() {
  pile_t *p = malloc(sizeof(pile_t));
  p->nb_elem = 0;
  p->taille = 32;
  p->tab = malloc(p->taille * sizeof(int));
  return p;
}

bool est_vide(pile_t *p) { return (p->nb_elem == 0); }

void empiler(pile_t *p, int x) {
  if (p->taille == p->nb_elem) {
    p->taille = p->taille * 2;
    p->tab = realloc(p->tab, p->taille * sizeof(int));
  }
  p->tab[p->nb_elem] = x;
  p->nb_elem++;
}

int depiler(pile_t *p) {
  assert(!est_vide(p));
  if (p->taille == p->nb_elem / 4) {
    p->taille = p->taille / 2;
    p->tab = realloc(p->tab, p->taille * sizeof(int));
  }
  int res = p->tab[p->nb_elem - 1];
  p->nb_elem--;
  return res;
}

void free_pile(pile_t *p) {
  free(p->tab);
  free(p);
}

void affiche_pile(pile_t *p) {
  for (int i = 0; i < p->nb_elem; ++i) {
    printf("%d ", p->tab[i]);
  }
  printf("\n");
}

int taille_pile(pile_t *p) { return p->nb_elem; }
