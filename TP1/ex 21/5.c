#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int main() {
    // seed
    srand(time(NULL));

    printf("%d\n", rand() % 11 + 10);

    return 0;
}
