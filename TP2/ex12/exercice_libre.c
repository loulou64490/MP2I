#include <stdio.h>
#include <stdlib.h>


// Renvoie le n-ième terme de la suite de Fibonacci
long int fibonacci(long int n)
{
    if (n <= 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Renvoie la factorielle de n
long int factorielle(long int n)
{
    if (n < 0)
    {
        return -1;
    }
    if (n == 0 || n == 1)
    {
        return 1;
    }
    return n * factorielle(n - 1);
}

// Renvoie le PGCD de a et b
long int pgcd(long int a, long int b)
{
    if (b == 0)
    {
        return a;
    }
    return pgcd(b, a % b);
}

// Vérifie si n est premier
long int premier(long int n)
{
    if (n <= 1)
    {
        return 0;
    }
    for (int i = 2; i * i <= n; i++) // i <= sqrt(n) <=> i*i <= n
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

// Lire un long int, ferme le programme en cas d'erreur
void sf(long int *n)
{
    if (!scanf("%ld", n)) exit(-1);
}

int main(void)
{
    while (1)
    {
        printf("\nSélectionnez une fonction:\n");
        printf("1 Fibonacci | 2 Factorielle | 3 PGCD | 4 Premier | _ Quitter");
        long int choix;
        sf(&choix);
        switch (choix) // Switch pour choisir la fonction (c'est pratique :)
        {
        case 1:
            {
                long int n;
                printf("Entrez n: ");
                sf(&n);
                printf("Fibonacci(%ld) = %ld\n", n, fibonacci(n));
                break;
            }
        case 2:
            {
                long int n;
                printf("Entrez n: ");
                sf(&n);
                long int result = factorielle(n);
                if (result == -1) printf("Factorielle n'est pas définie pour les nombres négatifs.\n");
                else printf("Factorielle(%ld) = %ld\n", n, result);
                break;
            }
        case 3:
            {
                long int a, b;
                printf("Entrez a: ");
                sf(&a);
                printf("Entrez b: ");
                sf(&b);
                printf("PGCD(%ld, %ld) = %ld\n", a, b, pgcd(a, b));
                break;
            }
        case 4:
            {
                long int n;
                printf("Entrez n: ");
                sf(&n);
                if (premier(n)) printf("%ld est premier\n", n);
                else printf("%ld n'est pas premier\n", n);
                break;
            }
        default: return 0;
        }
    }
}
