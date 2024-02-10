#include <cs50.h>
#include <stdio.h>
#include <string.h>


int main()
{
    char *name = get_string("Welcome! Enter your name: ");

    printf("Hello, %s! Choose your class:\n", name);
    printf("Warrior, Mage, Paladin, Thief\n");
    char *class = get_string("");
    
}