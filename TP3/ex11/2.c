#include <assert.h>

/* renvoie le nombre de fois que le char c apparait dans la chaine s*/
int occurrences(char* s, char c)
{
    int n = 0;
    for (int i = 0; s[i] != '\0'; i++) if (s[i] == c) n++;
    return n;
}

int main()
{
    char s[50] = "Hello world!";
    assert(occurrences(s,'l') == 3);
}
