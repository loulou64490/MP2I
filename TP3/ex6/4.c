#include <stdio.h>

/* affiche les cases d’un tableau d’entiers */
void afficher(int* tab, int n)
{
    for (int i = 0; i < n; i++) printf("%d ", tab[i]);
}

/* remplit les n + 1 premières cases de U en stockant dans
chaque case U[i] la somme des i premières cases de T*/
void remplir(int* T, int* U, int n)
{
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        U[i] = s;
        s += T[i];
    }
}

int main()
{
    int T[6] = {2, 3, 5, 1, -3, 3};
    int U[6];
    remplir(T, U, 6);
    afficher(U, 6);
}
