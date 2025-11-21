#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct maillon{
	struct maillon* suivant;
	int val;
};
typedef struct maillon maillon_t;

struct liste {
	unsigned int taille;
	maillon_t* tete; // premier maillon
};
typedef struct liste liste_t;


/* Renvoie une liste de n entiers aléatoires entre 0 et 99 */
liste_t* liste_aleatoire(int n){
	assert(n >= 0);
	liste_t* res = malloc(sizeof(liste_t));
	res->taille = n;
	// si n = 0, on renvoie une liste vide
	if (n == 0){
		res->tete = NULL;
		return res;
	}
	// sinon, on crée un premier maillon (la tête),
	// et on ajoute les n-1 maillons suivants à la suite
	res->tete = malloc(sizeof(maillon_t));
	
	// courant représente le dernier maillon ajouté
	maillon_t* courant = res->tete; 
	courant->val = rand()%100;
	for (int i = 1; i < n; ++i){
		// créer un nouveau maillon et s'y positionner,
		// puis rentrer la valeur
		courant->suivant = malloc(sizeof(maillon_t));
		courant = courant->suivant;
		courant->val = rand()%100;
	}
	// marquer la fin de la liste avec NULL 
	courant->suivant = NULL;
	return res;
}

/* Affiche les valeurs de l dans l'ordre */
void liste_print(liste_t* l){
	assert(l != NULL);
	// parcourir la liste depuis la tête, en s'arrêtant
	// lorsque l'on atteint le NULL marquant la fin de liste
	maillon_t* m = l->tete;
	while (m != NULL){
		printf("%d ", m->val);
		m = m->suivant;
	} 
	printf("\n");
}