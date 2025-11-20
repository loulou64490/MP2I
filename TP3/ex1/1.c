#include <stdio.h>

int main()
{
    long int x = 6;
    long int y = 98;
    long int* px = &x;
    long int* py = &y;

    printf("L'adresse de x est %p, celle de y est %p\n", px, py);
    return 0;

}