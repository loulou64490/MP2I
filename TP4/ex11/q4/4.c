#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int ma_getline(char** buffer, int* n, FILE* f)
{
    if (*buffer == nullptr)
    {
        *n = 30;
        *buffer = malloc(*n * sizeof(char));
    }
    char c;
    int len = 0;
    do
    {
        if (fscanf(f, "%c", &c) == EOF) break;
        if (len >= *n)
        {
            *n = *n * 2;
            *buffer = realloc(*buffer, *n * sizeof(char));
        }
        (*buffer)[len] = c;
        len++;
    }
    while (c != '\n');

    if (len == 0) return EOF;
    return len;
}

int main(int argc, char** argv)
{
    FILE* f = fopen(argv[1], "r");
    assert(f!= NULL);
    char* ligne = nullptr;
    int n = 0;
    int c = 1;
    int len = ma_getline(&ligne, &n, f);
    while (len != EOF)
    {
        printf("%d. ", c++);
        for (int i = 0; i < len; ++i)
        {
            printf("%c", ligne[i]);
        }
        len = ma_getline(&ligne, &n, f);
    }
    printf("\n");
    free(ligne);
    fclose(f);
}
