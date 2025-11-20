#include <assert.h>

/* compare s1 et s2
 * s1 = s2 -> 0
 * s1 < s2 -> -
 * s1 > s2 -> +
 */
int str_cmp(char* s1, char* s2)
{
    int n = 0;
    while (s1[n] != '\0' || s2[n] != '\0')
    {
        int r = s1[n] - s2[n]; // différence des caractères
        if (r != 0) return r;
        n++;
    }
    return s1[n] - s2[n];
}

int main()
{
    char s1[50] = "bla";
    char s2[50] = "bla";
    assert(str_cmp(s1, s2) == 0);

    char s3[50] = "bla";
    char s4[50] = "blb";
    assert(str_cmp(s3, s4) == -1);

    char s5[50] = "blb";
    char s6[50] = "blabbed";
    assert(str_cmp(s5, s6) == 1);
}
