#include <stdio.h>
#include <unistd.h>

void pong(void); // Déclaration anticipée

void ping(void)
{
    printf("Ping\n");
    sleep(1);
    pong();
}

void pong(void)
{
    printf("Pong\n");
    sleep(1);
    ping();
}

int main(void)
{
    ping();
    return 0;
}
