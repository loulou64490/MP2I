#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int ui;

struct etudiant
{
    char* prenom;
    ui age;
};

typedef struct etudiant etu_t;

typedef struct equipe
{
    ui nb_membres;
    etu_t** membres; // tableaux de pointeurs vers les membres de l'equipe
    unsigned int indice_cpt; // indice du capitaine dans le tableau des membres
} equipe_t;

void print_etu(etu_t* e)
{
    printf("%s, %d ans\n", e->prenom, e->age);
}

void print_equipe(equipe_t* e)
{
    printf("Equipe\n");
    for (ui i = 0; i < e->nb_membres; ++i)
    {
        if (i == e->indice_cpt)
            printf("Capitaine: ");
        print_etu(e->membres[i]);
    }
}

void free_etu(etu_t* e)
{
    free(e->prenom);
    free(e);
}

void free_equipe(equipe_t* e)
{
    for (ui i = 0; i < e->nb_membres; ++i)
    {
        free_etu(e->membres[i]);
    }
    free(e->membres);
    free(e);
}


/* Agrandis dst* en y copiant les joueurs de src*
 * Le capitaine choisi est celui de la plus grande équipe
 * src* n’est pas modifiée et * on libère la mémoire
 * de dst* normalement avec free_equipe()
 */
void agrandir_equipe(equipe_t* dst, const equipe_t* src)
{
    dst->membres = realloc(dst->membres, (dst->nb_membres + src->nb_membres) * sizeof(etu_t*));
    for (ui i = 0; i < src->nb_membres; ++i)
    {
        dst->membres[i + dst->nb_membres] = malloc(sizeof(etu_t));
        dst->membres[i + dst->nb_membres]->prenom = malloc(20 * sizeof(char));
        strcpy(dst->membres[i + dst->nb_membres]->prenom, src->membres[i]->prenom);
        dst->membres[i + dst->nb_membres]->age = src->membres[i]->age;
    }
    if (src->nb_membres > dst->nb_membres)
    {
        dst->indice_cpt = src->indice_cpt + dst->nb_membres;
    }
    dst->nb_membres += src->nb_membres;
}

int main()
{
    equipe_t* e1 = malloc(sizeof(equipe_t));
    e1->nb_membres = 3;
    e1->membres = malloc(e1->nb_membres * sizeof(etu_t*));
    for (ui i = 0; i < e1->nb_membres; ++i)
    {
        e1->membres[i] = malloc(sizeof(etu_t));
        e1->membres[i]->prenom = malloc(20 * sizeof(char));
    }
    strcpy(e1->membres[0]->prenom, "Camille");
    e1->membres[0]->age = 23;
    strcpy(e1->membres[1]->prenom, "Leila");
    e1->membres[1]->age = 20;
    e1->indice_cpt = 1;
    strcpy(e1->membres[2]->prenom, "Thibault");
    e1->membres[2]->age = 22;

    equipe_t* e2 = malloc(sizeof(equipe_t));
    e2->nb_membres = 4;
    e2->membres = malloc(e2->nb_membres * sizeof(etu_t*));
    for (ui i = 0; i < e2->nb_membres; ++i)
    {
        e2->membres[i] = malloc(sizeof(etu_t));
        e2->membres[i]->prenom = malloc(20 * sizeof(char));
    }
    strcpy(e2->membres[0]->prenom, "Paul");
    e2->membres[0]->age = 4;
    strcpy(e2->membres[1]->prenom, "Alice");
    e2->membres[1]->age = 99;
    e2->indice_cpt = 1;
    strcpy(e2->membres[2]->prenom, "Léo");
    e2->membres[2]->age = 18;
    strcpy(e2->membres[3]->prenom, "Hugo");
    e2->membres[3]->age = 18;


    print_equipe(e1);
    printf("\n\n");
    agrandir_equipe(e1, e2);
    print_equipe(e1);

    free_equipe(e1);
    free_equipe(e2);
}
