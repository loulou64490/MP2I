#include<stdio.h>

int main() {
    int n = 1;
    printf("Entrez un entier n : ");
    scanf("%d", &n);

    if (n % 3 == 0 || n % 5 == 0 || n % 7 == 0) {
        if (n % 3 == 0) {
            printf("ga");
        }
        if (n % 5 == 0) {
            printf("bu");
        }
        if (n % 7 == 0) {
            printf("zo");
        }
    } else {
        printf("%d", n);
    }
    printf("\n");

    return 0;
}
