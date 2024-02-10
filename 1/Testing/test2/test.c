#include <stdio.h>

int main(void)
{
    int a = 28;
    int b = 50;
    int *c = &a;
    printf("%p\n", &a);
    printf("%i\n", c);
}