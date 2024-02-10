#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get user input
    int height;
    do
    {
        height = get_int("Height: ");
    }
    // Check if height is between 0 and 9
    while (height < 1 || height > 8);

    // Print 'height' number of rows
    for (int row = 1; row <= height; row++)
    {
        // Number of spaces per row
        for (int w = 0; w < height - row; w++)
        {
            printf(" ");
        }

        // Number of '#'s per row
        for (int x = 0; x < row; x++)
        {
            printf("#");
        }

        // Print space inbetween
        printf("  ");

        // Print second half

        for (int y = 0; y < row; y++)
        {
            printf("#");
        }

        // Create new line
        printf("\n");
    }

}