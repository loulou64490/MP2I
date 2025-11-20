#include <assert.h>
#include <stdio.h>

int main(int argc, char** argv)
{
    FILE* a = fopen(argv[1], "r");
    FILE* b = fopen(argv[2], "w");
    assert(a != NULL && b != NULL);
    char c;
    while (fscanf(a, "%c", &c) != EOF)
    {
        fprintf(b, "%c", c);
    }
    fclose(a);
    fclose(b);
}
