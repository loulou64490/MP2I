#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct eleve
{
    char nom_complet[51];
    int jour, mois, annee; // date de naissance
    char metier[51];
} eleve_t;


eleve_t* lire_eleve(FILE* f)
{
    eleve_t* e = malloc(sizeof(eleve_t));

    char* nom = nullptr;
    size_t l = 0;
    getline(&nom, &l, f);
    strcpy(e->nom_complet, nom);
    free(nom);

    int n;
    fscanf(f, "%d", &n);
    e->jour = n;
    fscanf(f, "%d", &n);
    e->mois = n;
    fscanf(f, "%d", &n);
    e->annee = n;

    char c;
    fscanf(f, "%c", &c); // miam le \n

    char* metier = nullptr;
    l = 0;
    getline(&metier, &l, f);
    strcpy(e->metier, metier);
    free(metier);

    return e;
}

eleve_t** lire_promo(char* filename, int* n)
{
    FILE* f = fopen(filename, "r");
    fscanf(f, "%d", n);
    char c;
    fscanf(f, "%c", &c); // miom le \n
    eleve_t** t = malloc(*n * sizeof(eleve_t*));
    for (int i = 0; i < *n; ++i)
    {
        t[i] = lire_eleve(f);
    }
    fclose(f);
    return t;
}

void affiche_promo(eleve_t** t, int* n)
{
    printf("Promo 2025\n");
    for (int i = 0; i < *n; ++i)
    {
        printf("%s", t[i]->nom_complet);
        printf("Née le %d/%d/%d est %s\n",t[i]->jour, t[i]->mois, t[i]->annee, t[i]->metier);
    }
}

int main()
{
    int n;
    eleve_t** promo = lire_promo("promo_2015.txt", &n);
    affiche_promo(promo, &n);
    for (int i = 0; i < n; ++i)
    {
        free(promo[i]);
    }
    free(promo);
}
