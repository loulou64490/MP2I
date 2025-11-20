#include <assert.h>
#include <stdio.h>

int main(void)
{
    int s = 0, v = 0;
    printf("Rentrer des entiers positifs (négatif non compté pour sortir) :\n");
    while (v >= 0)
    {
        scanf("%d", &v);
        if (v >= 0) s += v;
    }
    printf("Somme : %d\n", s);
    return 0;
}
