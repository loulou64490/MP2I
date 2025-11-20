#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

bool egaux(int* t1, int* t2, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (t1[i] != t2[i])
            return 0;
    }
    return 1;
}

int* zeros(int n)
{
    int* m = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) m[i] = 0;
    return m;
}

bool* zeros_uns(int n, int m)
{
    bool* tab = malloc((n + m) * sizeof(bool));
    for (int i = 0; i < n; i++) tab[i] = false;
    for (int i = n; i < n + m; i++) tab[i] = true;
    return tab;
}

int main()
{
    int* t1 = malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++)
    {
        t1[i] = i;
    }
    int t2[5] = {0, 1, 2, 3, 4};
    assert(egaux(t1, t2, 5));
    free(t1);

    int* t3 = zeros(3);
    int t4[3] = {0, 0, 0};
    assert(egaux(t3,t4, 3));
    free(t3);

    bool* t5 = zeros_uns(2, 3);
    bool t6[5] = {false, false, true, true, true};
    for (int i = 0; i < 5; i++) assert(t5[i] == t6[i]);
    free(t5);
}
