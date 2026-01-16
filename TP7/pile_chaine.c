#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "pile.h"
/* Implémentation des piles par liste chaînée */

typedef struct maillon {
	int elem;
	struct maillon* suivant;
} maillon_t;


struct pile{
	maillon_t* sommet;
};

pile_t* pile_vide(){
	pile_t* p = malloc(sizeof(pile_t));
	p->sommet = NULL;
	return p;
}

bool est_vide(pile_t* p){
	return (p->sommet == NULL);
}

void empiler(pile_t* p, int x){
	maillon_t* m = p->sommet;
	maillon_t* nouveau_sommet = malloc(sizeof(maillon_t));

	nouveau_sommet->elem = x;
	nouveau_sommet->suivant = p->sommet;
	p->sommet = nouveau_sommet;
}

int depiler(pile_t* p){
	assert(!est_vide(p));
	int res = p->sommet->elem;
	maillon_t* nouveau_sommet = p->sommet->suivant;
	free(p->sommet); // éviter les fuites mémoire
	p->sommet = nouveau_sommet;
	return res;
}

void free_maillon(maillon_t* m){
    if (m != NULL){
        free_maillon(m->suivant);
        free(m);
    }
}

void free_pile(pile_t* p){
    free_maillon(p->sommet);
    free(p);
}


void affiche_pile(pile_t* p){
	for (maillon_t* m = p->sommet; m != NULL; m = m->suivant)
	{
		printf("%d ", m->elem);
	}
	printf("\n");
}
