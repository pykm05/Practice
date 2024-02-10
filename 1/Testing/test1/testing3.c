#include <stdio.h>

int main(void)
{
    char *s = "Hi!";
    printf("%c\n", *s);
    printf("%p\n", s);
    printf("%p\n", &s[0]);
    printf("%p\n", &s[1]);
}