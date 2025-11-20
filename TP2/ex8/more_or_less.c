#include <stdio.h>
#include <time.h>
#include <stdlib.h>

bool vérifier(int target, int guess)
{
    if (target > guess)
    {
        printf("Plus haut\n");
        return false;
    }
    if (target < guess)
    {
        printf("Plus bas\n");
        return false;
    }
    return true;
}


int main(void)
{
    srand(time(nullptr));
    const int n = rand() % 5000;
    int x;
    bool gagné = false;
    printf("Devinez le nombre entre 0 et 4999\n");
    while (!gagné)
    {
        printf("Votre proposition ? ");
        scanf("%d", &x);
        gagné = vérifier(n, x);
    }
    printf("Gagné\n");

    return 0;
}
