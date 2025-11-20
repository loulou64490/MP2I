#include <stdio.h>

int main(void)
{
    int n;
    printf("Entrez un entier : ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        printf("%d\n", i);
    }
    return 0;
}
