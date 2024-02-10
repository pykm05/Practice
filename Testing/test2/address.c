#include <stdio.h>
#include <string.h> // strcmp()
#include <cs50.h>
#include <ctype.h>

// pointer: a variable that contains the address of some value.
// POINTERS ARE JUST ADDRESSES
// string = *char
// '*p' will go to the value at address stored at p (dereference operator)
// '&p' will give you the address of p
// when comparing strings, you cannot use '==' because it will compare the two addresses
// of the strings which are always going to be different.
// use 'strcmp()' to compare string and include string.h

// File Pointers
// if you make a call fopen for writing and the file already exists it will overwrite
// Append will not overwrite and will go to the end of the file

void stringTest();
void strcmpTest();

int main()
{
    int n = 50;
    // 'int s = &n;' cannot be done because you need the '*' symbol.
    // %p allows you to print address of variable if you use '&'.
    printf("%p\n", &n);
    int *p = &n;
    printf("%p\n", p);
    stringTest();
    strcmpTest();
    mallocTest();
}

// string is a pointer to the first character
// string = *char

void stringTest()
{
    // string = *char
    char *s = "HI!";
    string d = "HI!";
    // string s points to s[0] and only stores the address of the first character.
    // st will then trace the character bytes until it hits null character.
    printf("%s\n", s);
    printf("%p\n", d);
    printf("%p\n", s);
    printf("%p\n", &s[0]);
    // %s will give exact value
    // %p will give address
}

void strcmpTest()
{
    char *s = get_string("s: ");
    char *t = get_string("t: ");
    printf("%c\n", *s);
    // strcmp needs string.h
    // strcmp will return 0 if the two strings are EXACTLY the same
    // when comparing strings, you cannot use == because it will compare the two addresses
    // of the strings which are always going to be different.
    if (strcmp(s, t) == 0)
    {
        printf("same\n");
    }
    else
    {
        printf("different\n");
    }
}