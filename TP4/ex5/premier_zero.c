#include <assert.h>
#include <stdio.h>

/* compte le nombre d’entiers strictement
 * positifs lus avant de lire un zéro*/
int premier_zero(char* filename)
{
    FILE* f = fopen(filename, "r");
    assert(f != NULL);
    int c = 0, x;
    while (fscanf(f, "%d", &x) == 1)
    {
        if (x == 0)
        {
            fclose(f);
            return c;
        }
        if (x > 0) c++;
    }
    fclose(f);
    return -1;
}

int main()
{
    // tests
    assert(premier_zero("-1")==-1);
    assert(premier_zero("0")==0);
    assert(premier_zero("1")==1);
    assert(premier_zero("2")==2);
}
