#include <assert.h>
#include <stdio.h>

/* Vérifie si int a divise int b */
int divise(int a, int b)
{
    assert(a!=0);
    return b % a == 0;
}

/* Affiche un float a et son inverse */
void affiche(float a)
{
    assert(a!=0);
    printf("%f %f\n", a, 1 / a);
}

/* Affiche float (3*x + 5*y - 6.25*z + t) et renvoie son carré */
float calcul(float x, float y, float z, float t)
{
    float a = 3 * x + 5 * y - 6.25 * z + t;
    printf("%f\n", a);
    return a * a;
}

int main(void)
{
    printf("%b %b\n", divise(3, 9), divise(4, 9));
    affiche(3.67);
    printf("%f\n", calcul(1.2, 19.1, 32.7, 4.0));

    return 0;
}
