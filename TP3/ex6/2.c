# include <stdio.h>

/* affiche les cases d’un tableau d’entiers */
void afficher(int* tab, int n)
{
    for (int i = 0; i < n; i++) printf("%d ", tab[i]);
}

int main()
{
    int t[6] = {2, 3, 5, 1, -3, 3};
    afficher(t, 6);
}
