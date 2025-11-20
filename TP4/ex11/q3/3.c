#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// pour ne pas utiliser realloc je vais partir
// du principe que le fichier fais moins de N lignes
#define N 1000

/* compare s1 et s2 (TP3 ex11 Q5.)
 * s1 = s2 -> 0
 * s1 < s2 -> -
 * s1 > s2 -> +
 */
int str_cmp(char* s1, char* s2)
{
    int n = 0;
    while (s1[n] != '\0' || s2[n] != '\0')
    {
        int r = s1[n] - s2[n];
        if (r != 0) return r;
        n++;
    }
    return s1[n] - s2[n];
}

int main(int argc, char** argv)
{
    assert(argc==3); // 2 fichiers en argument

    FILE* r = fopen(argv[1], "r"); //source
    assert(r!=NULL);
    FILE* w = fopen(argv[2], "w"); //destination
    assert(w!=NULL);

    char* l = nullptr; // ligne
    char* tl[N]; // tableau des pointeurs vers les lignes

    int c = 0; // nombre de lignes
    int tc[N]; // tableau des indices

    size_t x = 0;
    size_t n = getline(&l, &x, r);
    int tn[N]; // tableau des longueurs de ligne

    while (n != (size_t)-1)
    {
        tl[c] = l;
        tn[c] = n-1; // pour enlever le retour chariot
        tc[c] = c;
        c++;
        l=nullptr; // j'ai mis du temps à trouver ça :(
        n = getline(&l, &x, r);
    }
    free(l);
    fclose(r);
    tn[c-1]++; // la dernière ligne n’a pas de retour chariot

    for (int i = 1; i < c; ++i) // tri insertion
    {
        int k = tc[i]; // clé
        int j = i;
        while (j > 0 && str_cmp(tl[k], tl[tc[j - 1]]) < 0)
        {
            tc[j] = tc[j - 1];
            j--;
        }
        tc[j] = k;
    }


    for (int i = 0; i < c; ++i)
    {
        for (int j = 0; j < tn[tc[i]]; ++j)
        {
            fprintf(w, "%c", tl[tc[i]][j]);
        }
        fprintf(w,"\n");
        free(tl[tc[i]]);
    }
    fclose(w);
}
