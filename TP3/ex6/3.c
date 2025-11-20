#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* affiche les cases d’un tableau d’entiers */
void afficher(int* tab, int n)
{
    for (int i = 0; i < n; i++) printf("%d ", tab[i]);
}

/* remplit un tableau tab de taille n avec des nombres aléatoires entre -10 et 10*/
void remplir(int* tab, int n)
{
    for (int i = 0; i < n; i++) tab[i] = rand() % 21 - 10;
}

int main()
{
    srand(time(nullptr));

    int t[6];
    remplir(t, 6);
    afficher(t, 6);
}
