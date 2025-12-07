#pragma once
#include <stdbool.h>

// élément de menu
struct menu_elem
{
    char nom[50];
    float prix_unite;
    bool vegan;
};

typedef struct menu_elem menu_elem_t;

#define MAX_ELEMS 128

// Invariant: nb_elems <= MAX_ELEMS
struct menu
{
    menu_elem_t elements[MAX_ELEMS];
    int nb_elems; // nombre d'éléments du menu
};

typedef struct menu menu_t;
