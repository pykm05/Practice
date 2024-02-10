#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // Check if argument count is 2
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Check if key provided is 26 characters long
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }

    // Store argv[1] in key to view characters
    string key = argv[1];

    // Check if all values in key are letters
    for (int i = 0; i < strlen(key); i++)
    {
        if (key[i] >= 'a' && key[i] <= 'z')
        {
            continue;
        }

        if (key[i] >= 'A' && key[i] <= 'Z')
        {
            continue;
        }

        else
        {
            printf("Invalid character used\n");
            return 1;
        }
    }

    for (int i = 0; i < strlen(key); i++)
    {
        for (int j = i + 1; j < strlen(key); j++)
        {
            if (toupper(key[i]) == toupper(key[j]))
            {
                printf("Cannot contain two of the same characters\n");
                return 1;
            }
        }
    }

    // Get user input
    printf("plaintext:");
    string input = get_string(" ");
    printf("ciphertext: ");

    // Go through each character in input
    int length = strlen(input);
    for (int i = 0; i < length; i++)
    {
        // Check if user input is lowercase
        if (input[i] >= 'a' && input[i] <= 'z')
        {
            int inputNum = input[i] - 97;
            char lower = tolower(key[inputNum]);
            printf("%c", lower);
        }

        // Check if user input is uppercase
        else if (input[i] >= 'A' && input[i] <= 'Z')
        {
            int inputNum = input[i] - 65;
            char upper = toupper(key[inputNum]);
            printf("%c", upper);
        }

        else
        {
            printf("%c", input[i]);
        }
    }
    
    printf("\n");
    return 0;
}