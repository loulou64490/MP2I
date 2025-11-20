#include <assert.h>
#include <stdio.h>

/* renvoie le nom du fichier associé au char m */
char* fichier(char m)
{
    if (m >= 'A' && m <= 'Z')
    {
        static char s[] = "lettres/xx.txt"; // c'est pratique static :)
        s[8] = m;
        s[9] = m;
        return s;
    }
    static char s[] = "lettres/x.txt";
    s[8] = m;
    return s;
}

/* affiche la j-ème ligne du char m avec le char c */
void affiche(int j, char m, char c)
{
    if (m == ' ')
    {
        printf("        ");
        return;
    }

    FILE* f = fopen(fichier(m), "r");
    assert(f!=NULL);

    int t;
    for (int i = 0; i <= j; ++i)
    {
        fscanf(f, "%d", &t);
        // lit j entier, le j-eme est dans t
    }
    fclose(f);

    for (int l = 7; l > -1; --l)
    {
        if (t >> l & 1) printf("%c", c); // vérifie si le bit vaut 1
        else printf("%c", ' ');
    }
}


int main(int argc, char** argv)
{
    assert(argc ==2); // un caractère doit être spécifié
    const int n = 9; // nombre de caractères à afficher par ligne

    char p[100]; // on suppose que la chaine fait moins de 100 caractères
    printf("Rentrez la phrase à afficher: ");
    scanf("%[^\n]", p);
    // merci internet, je ne savais vraiment pas comment faire simplement
    int l = 0;
    while (p[l] != '\0') l++; // taille de la chaine

    for (int i = 0; i < (l + n - 1) / n; ++i)
    // (l + n - 1) / n équivalent à un arrondi par excès de l / n
    {
        for (int j = 0; j < 8; ++j)
        {
            for (int k = 0; k < n && n * i + k < l; ++k)
            // n * i + k < l pour ne pas dépasser la chaine
            {
                affiche(j, p[n * i + k], argv[1][0]);
            }
            printf("\n");
        }
    }
}
