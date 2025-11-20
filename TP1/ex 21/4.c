#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int main() {
    // seed
    srand(time(NULL));

    printf("%d\n", rand() % 100);

    return 0;
}
