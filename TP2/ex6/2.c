#include <stdio.h>

/* affiche la k-ième ligne */
void ligne(int k)
{
    for (int i = 0; i < k * 2 + 1; i++)
    {
        printf("-");
    }
    printf("|\n");
}

/* affiche un escalier de n lignes */
void escalier(int n)
{
    for (int i = 0; i < n; i++)
    {
        ligne(i);
    }
}

int main(void)
{
    int n;
    printf("Entrez le nombre de lignes : ");
    scanf("%d", &n);
    escalier(n);
    return 0;
}
