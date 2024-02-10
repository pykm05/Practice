#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
    // index = 0.0588 * L - 0.296 * S - 15.8
    // Get user input
    string input = get_string("Text: ");

    // Average number of letters per 100 words
    int letters = 0;
    int words = 1;
    int sentences = 0;

    // Iterate through each character from input
    for (int i = 0; i < strlen(input); i++)
    {
        // Check if current character is letter
        if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z'))
        {
            letters++;
        }

        // Increase word counter for each space
        if (input[i] == ' ')
        {
            words++;
        }

        // Increase sentence counter for punctuation
        if (input[i] == '.' || input[i] == '!' || input[i] == '?')
        {
            sentences++;
        }
    }

    // Use formula to determine age
    float calc = (0.0588 * letters / words * 100) - (0.296 * sentences / words * 100) - 15.8;
    int grade = round(calc);

    // Print response based on calculation
    if (grade < 1)
    {
        printf("Before Grade 1\n");
        return 0;
    }

    if (grade >= 16)
    {
        printf("Grade 16+\n");
        return 0;
    }

    else
    {
        printf("Grade %i\n", grade);
        return 0;
    }
}
