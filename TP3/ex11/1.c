#include <assert.h>

/*renvoie la longueur de la chaine s*/
int str_len(char* s)
{
    int n = 0;
    while (s[n] != '\0') n++;
    return n;
}

int main()
{
    char s[50] = "Hello world!";
    assert(str_len(s) == 12);
}
