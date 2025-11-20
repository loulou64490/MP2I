#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {
    // initialisation seed
    srand(time(NULL));

    const int n = rand() % 100 + 1; // nombre à trouver
    int x = 0; // entrée utilisateur
    long int t = time(NULL); // début du chrono
    int a = 0; // compteur d'essais

    printf("JEU DU PLUS OU MOINS\n");

    while (x != n) { // boucle tant que l'utilisateur n'a pas trouvé
        a++; // incrémentation essai
        printf("Entrez un nombre: ");
        scanf("%d",&x); // récupération de l'entrée utilisateur
        if (x<n) { // vérification plus ou moins
            printf("C'est plus !\n");
        } else if (x>n) {
            printf("C'est moins !\n");
        }
    }

    // message
    printf("Bravo, vous avez trouver en %d essais et %ld secondes!\n",a ,time(NULL)-t);

    return 0;
}
