#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// je vais tenter de le faire moi-même
// pour cela, je vais réutiliser les fonctions écrites précédemment
// il me faut aussi une fonction pour echanger deux éléments adjacents

#define N 100 // taille maximale du tableau

/*échange les cases a et b du tableau t */
void echanger(int* tab, int a, int b)
{
    int v = tab[a];
    tab[a] = tab[b];
    tab[b] = v;
}

/*vérifie qu'un tableau de taille n est trié */
bool verifier(int* tab, int n)
{
    // boucle qui vérifie si pour chaque élément, le suivant n'est pas inférieur
    // dans ce cas le tableau ne serait pas trié
    for (int i = 0; i < n - 1; i++) if (tab[i] > tab[i + 1]) return false;
    return true;
}

/*lit un entier*/
int lire(int* x)
{
    int b = scanf("%d", x);
    char c = 0;
    while (c != '\n') scanf("%c", &c);
    return b;
}

/*lit deux entiers*/
int lire2(int* x, int* y)
{
    // je ne sais pas comment la fusionner avec la précédente
    int b = scanf("%d %d", x, y);
    char c = 0;
    while (c != '\n') scanf("%c", &c);
    return b;
}

/*affiche les cases d’un tableau d’entiers */
void afficher(int* tab, int n)
{
    printf("[");
    for (int i = 0; i < n - 1; i++) printf("%d, ", tab[i]);
    printf("%d]\n", tab[n - 1]);
}

/*remplit un tableau tab de taille n avec des nombres aléatoires entre -10 et 10*/
void remplir(int* tab, int n)
{
    for (int i = 0; i < n; i++) tab[i] = rand() % 21 - 10;
}

/*jeu du tri*/
void jeu_du_tri()
{
    int n; // taille du tableau
    int tab[N]; // initialisation du grand tableau


    printf("Bienvenue au jeu du tri. ");
    while (1)
    {
        printf("Choisissez la taille du tableau: ");
        if (!lire(&n)) printf("Saisie incorrecte\n");
        else if (n > N) printf("La taille ne doit pas dépasser %d\n", N);
        else if (n <= 1) printf("La taille doit être au moins égale à 2\n");
        else break;
    }

    do
    {
        remplir(tab, n);
    }
    while (verifier(tab, n)); // pour éviter de générer un tableau déjà trié

    int compteur = 0;
    printf("Voici votre tableau:\n");
    while (!verifier(tab, n))
    {
        afficher(tab, n);
        int a, b; // indices à échanger
        while (1)
        {
            printf("Rentrez les indices à échanger: ");
            if (lire2(&a, &b) != 2) printf("Saisie incorrecte.\n"); // deux valeurs doivent être entrées
            else if (a < 0 || a >= n || b < 0 || b >= n)
                printf("Échange invalide: les indices doivent être entre 0 et %d.\n", n - 1);
            else if (abs(b - a) != 1) printf("Échange invalide: les cases doivent être adjacentes.");
                // étant donné que les cases doivent être adjacentes,
                // ç’aurait été plus simple de rentrer qu’un indice et échanger avec la case suivante…
            else break;
        }
        echanger(tab, a, b);
        compteur++;
    }
    printf("Bravo !! Vous avez gagné en %d coup(s) !\n", compteur);
}

/*test des fonctions*/
void test()
{
    // échanger
    int tab[3] = {1, 2, 3};
    echanger(tab, 0, 2);
    afficher(tab, 3); // doit afficher [3, 2, 1]

    // vérifier
    assert(verifier(tab, 3)==false);
    int tab2[3] = {1, 2, 3};
    assert(verifier(tab2, 3)==true);
}


int main()
{
    srand(time(NULL));
    //test();

    jeu_du_tri();
}
