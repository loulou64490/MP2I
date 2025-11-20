#include <stdio.h>

/*renvoie la longueur de la chaine s*/
int str_len(char* s)
{
    int n = 0;
    while (s[n] != '\0') n++;
    return n;
}

/* concatène dst+src dans dst*/
void str_cat(char* dst, char* src)
{
    int l = str_len(dst), n = 0;
    while (src[n] != '\0')
    {
        dst[l + n] = src[n];
        n++;
    }
    dst[l + n] = '\0';
}

int main()
{
    char str1[50] = "Bonjour";
    char str2[20] = " tout le monde !";
    str_cat(str1, str2);
    printf("%s\n", str1);
}
