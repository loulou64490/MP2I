#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    FILE* f = fopen(argv[1], "r");
    assert(f!= NULL);
    char* ligne = NULL;
    size_t n = 0; // long unsigned int
    int c = 1;
    size_t len = getline(&ligne, &n, f);
    while (len != (size_t)-1)
    {
        printf("%d. ", c++);
        for (size_t i = 0; i < len; ++i)
        {
            printf("%c", ligne[i]);
        }
        len = getline(&ligne, &n, f);
    }
    printf("\n");
    free(ligne);
    fclose(f);
}
