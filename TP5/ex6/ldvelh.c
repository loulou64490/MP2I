#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct CHOIX
{
    char* texte;
    int page_suivante;
} choix_t;

typedef struct PAGE
{
    char* texte;
    int n_choix;
    choix_t** choix; // tableau de pointeurs vers des choix
} page_t;

typedef struct LIVRE
{
    int n_pages;
    page_t** pages; // tableau de pointeurs vers des pages
} livre_t;

choix_t* generer_choix(FILE* f)
{
    choix_t* c = malloc(sizeof(choix_t));
    c->texte = NULL;
    size_t l = 0;
    getline(&c->texte, &l, f);
    fscanf(f, "%d", &c->page_suivante);
    fgetc(f); // miam le \n
    return c;
}

page_t* generer_page(FILE* f)
{
    page_t* p = malloc(sizeof(page_t));
    p->n_choix=0;
    fscanf(f, "%d", &p->n_choix);
    fgetc(f); // gloups le \n
    p->texte = NULL;
    size_t l = 0;
    getline(&p->texte, &l, f);
    p->choix = malloc(p->n_choix * sizeof(choix_t*));
    for (int i = 0; i < p->n_choix; ++i)
    {
        p->choix[i] = generer_choix(f);
    }
    return p;
}

livre_t* generer_livre(FILE* f)
{
    livre_t* l = malloc(sizeof(livre_t));
    l->n_pages=0;
    fscanf(f, "%d", &l->n_pages);
    fgetc(f); // *avale* le \n
    l->pages = malloc(l->n_pages * sizeof(page_t*));
    for (int i = 0; i < l->n_pages; ++i)
    {
        l->pages[i] = generer_page(f);
    }
    return l;
}

void free_livre(livre_t* l)
{
    for (int i = 0; i < l->n_pages; ++i)
    {
        for (int j = 0; j < l->pages[i]->n_choix; ++j)
        {
            free(l->pages[i]->choix[j]->texte);
            free(l->pages[i]->choix[j]);
        }
        free(l->pages[i]->texte);
        free(l->pages[i]->choix);
        free(l->pages[i]);
    }
    free(l->pages);
    free(l);
}

int main(int argc, char** argv)
{
    assert(argc==2);
    FILE* f = fopen(argv[1], "r");
    livre_t* l = generer_livre(f);
    fclose(f);

    int p = 0;
    while (true)
    {
        system("clear");
        printf("%s\n", l->pages[p]->texte);
        if (l->pages[p]->n_choix == 0) break;
        for (int i = 0; i < l->pages[p]->n_choix; ++i)
        {
            printf("%d. %s\n", i + 1, l->pages[p]->choix[i]->texte);
        }
        int c = 0;
        while (c < 1 || c > l->pages[p]->n_choix)
        {
            printf("Votre choix: ");
            scanf("%d", &c);
            int t;
            while ((t = getchar()) != '\n' && t != EOF); // vider le buffer
        }
        p = l->pages[p]->choix[c - 1]->page_suivante;
    }
    free_livre(l);
}
