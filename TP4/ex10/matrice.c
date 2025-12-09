#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <time.h>

/* renvoie une matrice nulle de dimensions n × m */
int** zeros(int n, int m)
{
    int** g = malloc(n * sizeof(int*));
    for (int i = 0; i < n; ++i)
    {
        g[i] = malloc(m * sizeof(int));
        for (int j = 0; j < m; ++j)
        {
            g[i][j] = 0;
        }
    }
    return g;
}

/* renvoie le minimum entre a et b */
int min(int a, int b)
{
    if (b < a) return b;
    return a;
}

/* renvoie une matrice n × m à coefficients choisis uniformément dans [a, b] */
int** rand_mat(int n, int m, int a, int b)
{
    int** g = zeros(n, m);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            g[i][j] = rand() % (abs(b - a) + 1) + min(a, b); // un nombre entre a et b inclus
        }
    }
    return g;
}

/* libère la mémoire de la matrice g de n lignes */
void free_mat(int** g, int n)
{
    for (int i = 0; i < n; ++i)
    {
        free(g[i]); // il faut d'abord libérer chaques lignes
    }
    free(g);
}

/* affiche la matrice g de n lignes */
void print_mat(int** g, int n, int m)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            printf("%d ", g[i][j]);
        }
        printf("\n");
    }
}

/* renvoie la matrice g1+g2 (g1 et g2 de dimension n × m) */
int** somme_mat(int** g1, int** g2, int n, int m)
{
    int** g = zeros(n, m);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            g[i][j] = g1[i][j] + g2[i][j]; // somme des éléments de mêmes indices
        }
    }
    return g;
}

/* renvoie le produit de la matrice g1 (n×p) avec la matrice g2 (p×m) */
int** produit_mat(int** g1, int** g2, int n, int p, int m)
{
    int** g = zeros(n, m);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            int s = 0;
            for (int k = 0; k < p; ++k)
            {
                s += g1[i][k] * g2[k][j];
            }
            g[i][j] = s;
        }
    }
    return g;
}

/* renvoie la moyenne de la position i [0,n-1] , j [0,m-1] de la matrice g (n×m) */
float moy_ij(int** g, int n, int m, int i, int j)
{
    int s = 0, c = 0; // somme, nb de valeur
    for (int k = i - 1; k < i + 2; ++k)
    {
        for (int l = j - 1; l < j + 2; ++l)
        {
            if (k >= 0 && k < n && l >= 0 && l < m)
            // exclus les valeurs hors matrice
            {
                c++;
                s += g[k][l];
            }
        }
    }
    return (float)s / (float)c; // pour renvoyer un float
}

/* cherche dans une grille g de dimension (n×m) les indices i0 [0,n-1], j0 [0,m-1]
* tels que la moyenne des valeurs de g[i0][j0] et de ses voisines est minimale
* renvoie i0, j0 dans un int*
*/
int* min_moy(int** g, int n, int m)
{
    int* t = malloc(2 * sizeof(int)); // t[0]=i0, t[1]=j0
    t[0] = 0, t[1] = 0;
    float moy = moy_ij(g, n, m, 0, 0);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            float u = moy_ij(g, n, m, i, j);
            if (u < moy)
            {
                moy = u;
                t[0] = i;
                t[1] = j;
            }
        }
    }
    //printf("i0 %d j0 %d moy %f", t[0], t[1], moy);
    return t;
}

/* test zeros(), rand_mat(), print_mat() et free_mat() */
void test1()
{
    int n = 2, m = 2, a = 0, b = 9;
    int** g1 = rand_mat(n, m, a, b);
    int** g2 = rand_mat(n, m, a, b);
    printf("g1\n");
    print_mat(g1, n, m);
    printf("g2\n");
    print_mat(g2, n, m);
    printf("somme\n");
    int** g3 = somme_mat(g1, g2, n, m);
    print_mat(g3, n, m);
    free_mat(g1, n);
    free_mat(g2, m);
    free_mat(g3, n);
}

/* test produit_mat() */
void test2()
{
    int g1l1[] = {1, -3, -2};
    int g1l2[] = {-4, 4, 2};
    int* g1[] = {g1l1, g1l2}; // pour créer une matrice de type int** en clair
    int g2l1[] = {-1, 2, -1, 1};
    int g2l2[] = {3, 4, -4, 1};
    int g2l3[] = {-2, -5, 2, -4};
    int* g2[] = {g2l1, g2l2, g2l3};
    int** g = produit_mat(g1, g2, 2, 3, 4);
    print_mat(g, 2, 4);
    // -6 0 7 6
    // 12 -2 -8 -8
    free_mat(g, 2);
}

/* test moy_ij() et min_moy() */
void test3()
{
    int l1[] = {-1, 2, -1, 1};
    int l2[] = {3, 4, -4, 1};
    int l3[] = {-2, -5, 2, -4};
    int* g1[] = {l1, l2, l3};
    moy_ij(g1, 3, 4, 0, 0); // 2
    moy_ij(g1, 3, 4, 1, 2); // -0.44...

    int r1[] = {0, 0, 0, 0, 0};
    int r2[] = {0, -1, -1, -1, 0};
    int r3[] = {0, -1, -1, -1, 0};
    int r4[] = {0, -1, -1, -1, 0};
    int r5[] = {0, 0, 0, 0, 0};
    int* g2[] = {r1, r2, r3, r4, r5};
    int* t = min_moy(g2, 5, 5);
    assert((t[0]==2 && t[1]==2));
    free(t);
}

int main()
{
    srand(time(NULL));
    test1();
    test2();
    test3();
}
