#include "menu.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void affiche_elem(menu_elem_t* e)
{
    printf("%s", e->nom);
    if (e->vegan)
        printf(" (V)");
    printf(": %.2f€\n", e->prix_unite);
}

void affiche_menu(menu_t* m)
{
    printf("Menu:\n");
    for (int i = 0; i < m->nb_elems; ++i)
    {
        printf("%d. ", i + 1);
        affiche_elem(&m->elements[i]);
    }
}

void init_commande(int* commande, int nb_elemes)
{
    for (int i = 0; i < nb_elemes; ++i)
    {
        commande[i] = 0;
    }
}

void prendre_commande(int* commande, int nb_elems)
{
    printf("Choisissez les plats à commander en notant leurs numéros, ");
    printf("puis ’#’ pour marquer la fin:\n");
    int c;
    while (scanf("%d", &c) != 0)
    {
        if (0 <= c && c <= nb_elems)
            commande[c - 1]++;
    }
}

void resume_commande(int* commande, menu_t* m)
{
    printf("Vous avez commandé:\n");
    for (int i = 0; i < m->nb_elems; ++i)
    {
        printf("%dx %s\n", commande[i], m->elements[i].nom);
    }
}

float total_commande(int* commande, menu_t* m)
{
    float r = 0;
    for (int i = 0; i < m->nb_elems; ++i)
    {
        r += m->elements[i].prix_unite * commande[i];
    }
    return r;
}

void ajouter_element(menu_t* m, char* nom, float prix_unite, bool vegan)
{
    menu_elem_t e = {
        .prix_unite = prix_unite,
        .vegan = vegan,
    };
    strcpy(e.nom, nom);
    m->elements[m->nb_elems++] = e; // on incrémente de 1 le nb d'élément
}

bool lire_element(FILE* f, menu_elem_t* e)
{
    fscanf(f, "%f", &e->prix_unite);
    fscanf(f, "%d", (int*)&e->vegan);
    return fscanf(f, "%[^\n]", e->nom) == EOF;
}

void lire_menu(char* nom_fichier, menu_t* m)
{
    FILE* f = fopen(nom_fichier, "r");
    assert(f != NULL);
    while (!lire_element(f, &m->elements[m->nb_elems]))
        m->nb_elems++;
    fclose(f);
}

void test()
{
    // menu_elem_t e_1 = {
    //     .nom = "Brocoli au gingembre",
    //     .prix_unite = 7.99,
    //     .vegan = true,
    // };
    // menu_elem_t e_2 = {
    //     .nom = "Hamburger du chef",
    //     .prix_unite = 7.99,
    //     .vegan = false,
    // };
    // menu_elem_t e_3 = {
    //     .nom = "Pâtes au saumon",
    //     .prix_unite = 11.99,
    //     .vegan = false,
    // };
    // menu_elem_t e_4 = {
    //     .nom = "Curry de butternut",
    //     .prix_unite = 8.99,
    //     .vegan = true,
    // };
    // menu_elem_t e_5 = {
    //     .nom = "Soupe de poulet",
    //     .prix_unite = 15.99,
    //     .vegan = false,
    // };

    // menu_t m_1 = {
    //     .elements = {e_3, e_4, e_5},
    //     .nb_elems = 3,
    // };
    // printf("%f", e_1.prix_unite);
    // affiche_elem(&e_1);
}

int main(int argc, char** argv)
{
    // test();

    menu_t m_1 = {.nb_elems = 0};
    lire_menu(argv[1], &m_1);
    affiche_menu(&m_1);
    int commande[MAX_ELEMS];
    init_commande(commande, m_1.nb_elems);
    prendre_commande(commande, m_1.nb_elems);
    resume_commande(commande, &m_1);
    printf("Total: %.2f€", total_commande(commande, &m_1));
}
