#include <assert.h>
#include <stdio.h>

// ajoute 1 à l’entier pointé par p
void incrementer(int* p)
{
    assert(p != NULL);
    *p = *p + 1; //
}

void echange(float* pa, float* pb)
{
    assert(pa != NULL);
    assert(pb != NULL);
    float temp = *pa;
    *pa = *pb;
    *pb = temp;
}

int main()
{
    int x = 3;
    float a = 4.5;
    float b = 2.5;
    echange(&a, &b);
    printf("a=%f, b=%f\n", a, b);
    printf("Avant : %d \n", x);
    incrementer(&x);
    printf("Après : %d \n", x);
}
