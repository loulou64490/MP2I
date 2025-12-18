#include <stdlib.h>
#include <time.h>
#include "sound.h"
#include "wav.h"
#include "melody.h"
#include "test.h"

/*
bon, j’ai pris quelques libertés…

j’ai voulu tester le typage et ne pas faire de conversion implicite,
(entre autre pour que mon CLion arrete de me harceler)
j’ai changé les types int en unsigned, et les float en double (pour la précision)
je ne sais pas si c’est forcément très utiles et judicieux,
mais le programme compile avec -Wconversion :D,
j’ai aussi remplacé int16_t par short (c'est la même chose)

j’ai écrit de base les variables avec des courts noms, mais c’était vraiment illisible,
du coup, je les ai toutes renommées, je pense que c’est un peu plus lisible,
comme il y avait des variables et des fonctions en anglais, j’ai tout écrit en anglais...

pour compiler et exécuter rapidement j'utilise un petit script que j'ai dans mon path
et que j'ai inclus dans le projet.
pour exécuter les test:
> mx main.c sound.c wav.c waveform.c melody.c test.c

sinon pour exécuter avec des argument :
> mx main.c sound.c wav.c waveform.c melody.c test.c ../archive/question_19/test5.txt sound/test5.wav
par exemple

je suis passé vers clang pour utiliser les sanitizer, très pratiques
et bien plus rapides que valgrind

je remarque qu'il y a une réelle augmentation des performances
en exécutant avec les optimisations
> clang main.c sound.c wav.c waveform.c melody.c test.c -o main -lm -O3 -ffast-math
je passe de 0.71s à 0.25 pour test5.txt
*/

int main(int argc, char** argv)
{
    if (argc != 3)
    {
        test();
        printf("Test générés !");
        return 0;
    }

    long time = clock();

    // génération du son
    mix_t* mix = load_mix(argv[1]);
    sound_t* sound = reduce_mix(mix);
    save_sound(argv[2], sound);

    unsigned length = sound->n_samples / SAMPLE_RATE;
    printf("Fichier %s généré (temps écoulé: %.2fs)\n", argv[2], (double)(clock() - time) / CLOCKS_PER_SEC);
    printf("Durée du fichier: %um%us (taille %.1fMo)", length / 60, length % 60, (double)sound->n_samples / 500000);
    // taille en Mo: (n_samples * 16 bits) / (8 bits * 1000000) = n_samples / 500000

    free_sound(sound);
    free_mix(mix);
}
