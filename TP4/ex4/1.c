#include <assert.h>
#include <stdio.h>

/* Renvoie la somme des entiers lus dans le fichier 'nom_fichier'.
Précondition: 'nom_fichier' ne doit contenir que des entiers. */
int somme(char* nom_fichier)
{
    FILE* f = fopen(nom_fichier, "r"); // ouverture en mode lecture
    assert(f != NULL);
    int x = 0; // pour lire dans le fichier
    int tot = 0; // pour stocker la somme
    int nb_lus = 0;
    while (nb_lus != EOF)
    {
        tot += x;
        nb_lus = fscanf(f, "%d ", &x); // nb_lus vaut 1 ou EOF
    }
    fclose(f);
    return tot;
}

int main()
{
    printf("%d", somme("test.txt"));
}
