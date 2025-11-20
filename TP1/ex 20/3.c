#include<stdio.h>
#include<time.h>

int main() {
    long int t = time(NULL);
    int m = t / (30.44 * 24 * 3600);
    int y = t / (365.24 * 24 * 3600);
    printf("%d/%d\n", m % 12 + 1, y + 1970);

    return 0;
}
