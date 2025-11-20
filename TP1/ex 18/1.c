#include<stdio.h>

int main() {
    float a, b, c;
    printf("Entrez 3 nombres : ");
    scanf("%f%f%f", &a, &b, &c);
    if ((a < b && b < c) || (c < b && b < a)) {
        c=b;
    } else if ((b < a && a < c) || (c < a && a < b)) {
        c=a;
    }
    printf("%f\n", c);
    return 0;
}
