#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


/* lit n entier pour les mettre dans un tableau
 * on suppose que filename ne contient que des entiers
 */
int* lire_entiers(char* filename, int* n)
{
    FILE* f = fopen(filename, "r");
    assert(f!= NULL);
    int* t = malloc(*n * sizeof(int));
    int c = 0, x;
    while (fscanf(f, "%d", &x) == 1 && c < *n)
    {
        t[c++] = x; // haha
    }
    fclose(f);
    *n = c;
    return t;
}

int main()
{
    // test
    int n = 4;
    int* t = lire_entiers("test", &n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", t[i]);
    }
    printf("\n");
    free(t);
}
