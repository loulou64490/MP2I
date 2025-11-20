# include <stdio.h>

int main(int argc, char** argv)
{
    for (int i = 0; i < argc; i++)
    {
        printf("%d-ème argument: %s\n", i, argv[i]);
    }
}
