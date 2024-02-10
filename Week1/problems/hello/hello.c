#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get user input
    string name = get_string("What's your name? ");

    // Print user's name
    printf("hello, %s\n", name);
}