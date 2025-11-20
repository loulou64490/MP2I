#include <stdio.h>

// variables principale accessible partout
int memoire[1024];
int taille_memoire;
bool presence_valeur[1024];

// j'ai réussi à fusionner les fonctions
// de lecture d'entier dans un truc comme ça,
// c'est pas très beau mais c'est mieux que trois fonctions séparés

/*lit 1, 2 ou 3 entiers et les mets dans a, b et c
 * renvoie true si cela a fonctionné, false sinon
 */
bool lire(int n, int* a, int* b, int* c)
{
    bool r;
    if (n == 1) r = scanf("%d", a) == 1;
    else if (n == 2) r = scanf("%d %d", a, b) == 2;
    else if (n == 3) r = scanf("%d %d %d", a, b, c) == 3;
    else return false;
    char k = 0;
    while (k != '\n') scanf("%c", &k);
    return r;
}

/*vérifie si l’adresse existe*/
bool adresse(int a)
{
    if (a < 0 || a > taille_memoire)
    {
        printf("Les adresses doivent êtres comprises en 0 et %d\n", taille_memoire);
        return false;
    }
    return true;
}

/*vérifie si la valeur existe*/
bool valeur(int a)
{
    if (!presence_valeur[a])
    {
        printf("L'adresse %d n'a pas de valeur\n", a);
        return false;
    }
    return true;
}

/*simule une petite mémoire RAM*/
void memory()
{
    for (int i = 0; i < 1024; i++) presence_valeur[i] = false; // aucune adresse accessible

    while (1)
    {
        printf("Choisir la taille de la mémoire: ");
        if (!lire(1, &taille_memoire, NULL,NULL)) printf("Saisie incorrecte\n");
        else if (taille_memoire < 0 || taille_memoire > 1024)
            printf(
                "La taille de la mémoire doit être comprise en 0 et 1024\n");
        else break;
    }

    int choix, a, b, c; // a, b et c adresse mémoire
    while (1)
    {
        printf("Que voulez vous faire ?\n1. Acceder à une valeur\n"
            "2. Stocker une valeur\n3. Faire une addition\n4. Quitter le programme\nChoix: ");
        if (!lire(1, &choix, NULL,NULL))
        {
            printf("Saisie incorrecte\n");
            continue;
        }
        if (choix == 1)
        {
            printf("Rentrez l’adresse mémoire: ");
            if (lire(1, &a, NULL,NULL))
            {
                if (adresse(a) && valeur(a))
                {
                    printf("La case %d contient %d\n", a, memoire[a]);
                }
                continue;
            }
        }
        else if (choix == 2)
        {
            printf("Rentrez l’adresse mémoire puis la valeur à stocker: ");
            if (lire(2, &a, &b,NULL))
            {
                if (adresse(a))
                {
                    memoire[a] = b;
                    presence_valeur[a] = true;
                    printf("%d stocké dans la case %d\n", b, a);
                }
                continue;
            }
        }
        else if (choix == 3)
        {
            printf("Rentrez les deux adresses de départ et l'adresse d'arrivée: ");
            if (lire(3, &a, &b, &c))
            {
                if (adresse(a) && adresse(b) && adresse(c) && valeur(a) && valeur(b))
                {
                    memoire[c] = memoire[a] + memoire[b];
                    presence_valeur[c] = true;
                    printf("%d stocké dans la case %d\n", memoire[a] + memoire[b], c);
                }
                continue;
            }
        }
        else if (choix == 4) break; // quitter le programme
        printf("Saisie incorrecte\n");
    }
}

int main()
{
    memory();
}
