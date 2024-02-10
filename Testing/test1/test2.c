#include <stdio.h>
#include <cs50.h>

int main(void)
{
    for (int i = 0; i < 3; i++)
    {
        printf("meow\n");
    }

    int p = 5;
    int j = 3;
    int k = p / j;
    printf("k = %d", k);
}