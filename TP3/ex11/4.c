#include <stdio.h>

/* copie src dans dst*/
void str_cpy(char* dst, char* src)
{
    int n = 0;
    while (src[n] != '\0')
    {
        dst[n] = src[n];
        n++;
    }
    dst[n] = '\0';
}

int main()
{
    char str1[30] = "Bonjour";
    char str2[50] = "Au revoir";
    str_cpy(str1, str2);
    printf("%s\n", str1);
}
