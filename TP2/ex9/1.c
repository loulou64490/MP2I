#include <stdio.h>

// Affiche les entiers décroissants de n à 1
void decr(int n)
{
    printf("%d\n", n);
    if (n > 1) decr(n - 1);
}

// Affiche les entiers croissants de 1 à n
void cr(int n)
{
    if (n > 1) cr(n - 1);
    printf("%d\n", n);
}


//Affiche n sur plusieurs lignes
void f(int n)
{
    if (n < 0)
    {
        printf("-\n");
        n = -n;
    }
    if (n / 10 != 0) f(n / 10);
    printf("%d\n", n % 10);
}

void o(int n)
{
    printf("o");
    if (n == 1) printf("\n");
    else o(n - 1);
}

void of(int n)
{
    if (n < 0)
    {
        printf("-\n");
        n = -n;
    }
    if (n / 10 != 0) of(n / 10);
    o(n % 10);
}

int main(void)
{
    //Test question 1
    decr(5);
    //Test question 2
    cr(5);
    //Test question 3
    f(-894);
    //Test question 4
    o(5);
    //Test question 5
    of(-894);

    return 0;
}
