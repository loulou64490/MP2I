#include <stdio.h>

// Renvoie le suivant de x dans la suite de Syracuse
long int suivant(long int x)
{
    if (x % 2 == 0)
    {
        return x / 2;
    }
    return 3 * x + 1;
}

// Renvoie le n-ième terme de la suite de Syracuse à partir de x
long int syracuse(long int x, int n)
{
    for (int i = 0; i < n; i++)
    {
        x = suivant(x);
    }
    return x;
}

// Renvoie le temps de vol de x
long int temps_de_vol(long int x)
{
    int n = 0;
    while (x != 1)
    {
        x = suivant(x);
        n++;
    }
    return n;
}

// Renvoie le plus long temps de vol pour les entiers de 1 à N
long int plus_long_vol(long int N)
{
    int m = 0, n = 0;
    for (int i = 1; i <= N; i++)
    {
        int t = temps_de_vol(i);
        if (t > m) m = t, n = i;
    }
    return m;
}

int main(void)
{
    printf("\n");
    return 0;
}
