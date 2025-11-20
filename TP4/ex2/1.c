#include <stdio.h>
#include <assert.h>

int main()
{
    FILE* f = fopen("hello.txt", "w"); // ouverture en mode écriture
    assert(f != NULL);
    fprintf(f, "Hello World %d!\n", 2024);
    fclose(f);
}
