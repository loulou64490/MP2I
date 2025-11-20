#include <assert.h>
#include <math.h>
#include <stdio.h>

/*Résout l’équation quadratique aX ^2 + bX + c = 0
et renvoie le nombre de solutions réelles (0, 1 ou 2).
Stocke également la ou les racines réelles dans les zones
pointées par x1 et x2.*/
int quad_solve(float a, float b, float c, float* x1, float* x2)
{
    assert(x1 && x2 && a); // vérifie que les pointeurs ne sont pas NULL (et a non nul)
    float d = b * b - 4 * a * c; // calcul du discriminant
    if (d < 0) return 0;
    *x1 = (-b - sqrtf(d)) / (2 * a);
    *x2 = (-b + sqrtf(d)) / (2 * a);
    return !!d + 1; // si delta nul renvoie 1, sinon renvoie 2
}

int main()
{
    // test
    float x1, x2;
    assert(quad_solve(2, 4, 2, &x1, &x2)==1);
    assert(x1==-1 && x2==-1);
    assert(quad_solve(1, 1, 0, &x1, &x2)==2);
    assert(x1==-1 && x2==0);
    assert(quad_solve(1, 1, 1, &x1, &x2)==0);
}
