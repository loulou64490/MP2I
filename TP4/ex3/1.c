#include <assert.h>
#include <stdio.h>

/* Renvoie la somme des deux premiers entiers lus dans le fichier
'nom_fichier'.
Précondition: 'nom_fichier' doit commencer par au moins
deux entiers
*/
int somme2(char* nom_fichier)
{
    FILE* f = fopen(nom_fichier, "r"); // ouverture en mode lecture
    assert(f != NULL);
    int x, y;
    int nb_lus = fscanf(f, "%d %d", &x, &y); // lire deux entiers dans f
    assert(nb_lus == 2);
    fclose(f);
    return x + y;
}

int main()
{
    printf("%d", somme2("test.txt"));
}