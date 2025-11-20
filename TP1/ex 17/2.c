#include<stdio.h>

int main() {
    float x;
    printf("Entrez un nombre : ");
    scanf("%f", &x);

    if (x < -0.33) {
        printf("cas A");
    } else if (x <= 7.89) {
        printf("cas B");
    } else {
        printf("cas C");
    }
    return 0;
}
