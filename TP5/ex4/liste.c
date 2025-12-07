#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

struct maillon
{
    struct maillon* suivant;
    int val;
};

typedef struct maillon maillon_t;

struct liste
{
    unsigned int taille;
    maillon_t* tete; // premier maillon
};

typedef struct liste liste_t;


/* Renvoie une liste de n entiers aléatoires entre 0 et 99 */
liste_t* liste_aleatoire(int n)
{
    assert(n >= 0);
    liste_t* res = malloc(sizeof(liste_t));
    res->taille = n;
    // si n = 0, on renvoie une liste vide
    if (n == 0)
    {
        res->tete = NULL;
        return res;
    }
    // sinon, on crée un premier maillon (la tête),
    // et on ajoute les n-1 maillons suivants à la suite
    res->tete = malloc(sizeof(maillon_t));

    // courant représente le dernier maillon ajouté
    maillon_t* courant = res->tete;
    courant->val = rand() % 100;
    for (int i = 1; i < n; ++i)
    {
        // créer un nouveau maillon et s'y positionner,
        // puis rentrer la valeur
        courant->suivant = malloc(sizeof(maillon_t));
        courant = courant->suivant;
        courant->val = rand() % 100;
    }
    // marquer la fin de la liste avec NULL
    courant->suivant = NULL;
    return res;
}

/* Affiche les valeurs de l dans l'ordre */
void liste_print(liste_t* l)
{
    assert(l != NULL);
    // parcourir la liste depuis la tête, en s'arrêtant
    // lorsque l'on atteint le NULL marquant la fin de liste
    maillon_t* m = l->tete;
    while (m != NULL)
    {
        printf("%d ", m->val);
        m = m->suivant;
    }
    printf("\n");
}

/* Renvoie une liste de n entiers de 0 à n-1 */
liste_t* liste_range(int n) // même organisation que liste_aleatoire()
{
    liste_t* l = malloc(sizeof(liste_t));
    l->taille = n;
    if (n == 0)
    {
        l->tete = NULL;
        return l;
    }

    l->tete = malloc(sizeof(maillon_t));
    maillon_t* m = l->tete;
    m->val = 0;
    for (int i = 1; i < n; ++i)
    {
        m->suivant = malloc(sizeof(maillon_t));
        m = m->suivant;
        m->val = i;
    }
    m->suivant = NULL;
    return l;
}

/* libère une chaine de maillon */
void maillon_free(maillon_t* m) // fonction récursive sur les maillons
{
    if (m->suivant != NULL)
    {
        maillon_free(m->suivant);
    }
    free(m);
}

/* libère une liste */
void liste_free(liste_t* l)
{
    if (l->tete != NULL)
    {
        maillon_free(l->tete);
    }
    free(l);
}

/* indique si x est présent dans la liste l */
bool liste_recherche(int x, liste_t* l)
{
    if (l->tete == NULL) return false;
    maillon_t* m = l->tete;
    while (m->suivant != NULL)
    {
        if (m->val == x) return true;
        m = m->suivant;
    }
    return m->val == x; // pour vérifier le dernier maillon
}

/* ajoute x à la fin de la liste l */
void ajoute_fin(int x, liste_t* l)
{
    if (l->tete == NULL)
    {
        l->tete = malloc(sizeof(maillon_t));
        l->tete->suivant = NULL;
        l->tete->val = x;
        l->taille = 1;
        return;
    }
    maillon_t* m = l->tete;
    while (m->suivant != NULL) m = m->suivant; //accéder au dernier maillon
    m->suivant = malloc(sizeof(maillon_t));
    m = m->suivant;
    m->suivant = NULL;
    m->val = x;
    l->taille++;
}

/* ajoute x au début de la liste l */
void ajoute_debut(int x, liste_t* l)
{
    if (l->tete == NULL)
    {
        l->tete = malloc(sizeof(maillon_t));
        l->tete->suivant = NULL;
        l->tete->val = x;
        l->taille = 1;
        return;
    }
    maillon_t* m = l->tete;
    int t = m->val;
    m->val = x;
    while (m->suivant != NULL)
    {
        m = m->suivant;
        int a = m->val;
        m->val = t;
        t = a;
    }
    m->suivant = malloc(sizeof(maillon_t));
    m = m->suivant;
    m->suivant = NULL;
    m->val = t;
    l->taille++;
}

/* retire la première occurrence de x de la liste l
 * renvoie true si cela a fonctionné, false sinon
 */
bool retire_x(int x, liste_t* l)
{
    if (l->tete == NULL) return false;
    maillon_t* m = l->tete;
    maillon_t* p;
    // pour enregistrer le pointeur précédent
    // pour mettre l’avant-dernier maillon->suivant à NULL
    while (m->suivant != NULL)
    {
        if (m->val == x)
        {
            while (m->suivant != NULL)
            {
                m->val = m->suivant->val;
                p = m;
                m = m->suivant;
            }
            p->suivant = NULL;
            free(m);
            l->taille--;
            return true;
        }
        p = m;
        m = m->suivant;
    }
    if (m->val == x)
    {
        p->suivant = NULL;
        free(m);
        l->taille--;
        return true;
    }
    return false;
}

int main()
{
    // srand(time(NULL));
    // liste_t* l = liste_aleatoire(10);


    liste_t* l = liste_range(10);
    ajoute_debut(-1, l);
    ajoute_fin(10, l);
    retire_x(5, l);
    liste_print(l);
    assert(liste_recherche(10,l));
    liste_free(l);
}
