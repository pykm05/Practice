#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *list = malloc(sizeof(int));
    *list = 18;
    *(list + 1) = 20;
    printf("%p %p\n", list, list + 1);
}