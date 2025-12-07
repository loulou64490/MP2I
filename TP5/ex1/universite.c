#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cours
{
    char intitule[50];
    char prof[50];
    int salle; // identifiant unique de la salle
    int jour; // 0 (lundi) - 6 (dimanche)
    bool tp;
};

typedef struct cours cours_t;

void afficher_cours(cours_t* c)
{
    char* jours[] = {
        "lundi", "mardi", "mercredi", "jeudi",
        "vendredi", "samedi", "dimanche"
    };
    char* tp[] = {"non", "oui"};
    printf("Cours: %s\nProfesseur: %s\n", c->intitule, c->prof);
    printf("Salle: %X\nJour: %s\nTP: %s\n", c->salle, jours[c->jour], tp[c->tp]);
}

cours_t* creer_cours(char* intitule, char* prof, int salle, int jour, bool tp)
{
    cours_t* cours = malloc(sizeof(cours_t));
    strcpy(cours->intitule, intitule);
    strcpy(cours->prof, prof);
    cours->salle = salle;
    cours->jour = jour;
    cours->tp = tp;
    return cours;
}

int main()
{
    printf("Taille du type: %ld octets\n", sizeof(cours_t));

    cours_t maths = {
        .intitule = "Mathématiques",
        .prof = "O.G.",
        .salle = 0xDE02,
        .jour = 1,
        .tp = true
    };

    cours_t phy;
    strcpy(phy.intitule, "Physique");
    strcpy(phy.prof, "A.B.");
    phy.salle = 0xA212;
    phy.jour = 2;
    phy.tp = 0;

    cours_t info = {
        .intitule = "Informatique",
        .prof = "G.R.",
        .salle = 0xDE02,
        .jour = 4,
        .tp = 0
    };

    afficher_cours(&maths);

    cours_t* si = creer_cours("Science de l'ingénieur", "M.N.", 0xDE02, 0, false);
    afficher_cours(si);
    free(si);
}
