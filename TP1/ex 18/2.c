#include<stdio.h>

int main() {
    int n = 1;
    printf("Entrez un entier n : ");
    scanf("%d", &n);

    // je ne crois pas que ce soit possible de faire avec deux 'if'
    if (n % 3 == 0 || n % 5 == 0) {
        if (n % 3 == 0) {
            printf("ga");
        }
        if (n % 5 == 0) {
            printf("bu");
        }
    } else {
        printf("%d", n);
    }
    printf("\n");

    return 0;
}
