#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    bool a = true, b = false;
    printf("%d %d %d %d %d\n", a, b, a && b, a || b, !a);

    return 0;
}
