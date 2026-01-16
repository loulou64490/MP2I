#include "pile.h"
#include <assert.h>

int main() {
  pile_t *p = pile_vide();

  assert(est_vide(p));
  empiler(p, 0);
  empiler(p, 1);
  assert(depiler(p) == 1);
  assert(depiler(p) == 0);

  for (int i = 0; i < 50; ++i) {
    empiler(p, 0);
  }

  free_pile(p);
  return 0;
}
