#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing
    for (int column = 0; column < height; column++)
    {
        // Go through each row and check to see if they are black
        for (int row = 0; row < width; row++)
        {
            if (image[column][row].rgbtBlue == 0 &&
                image[column][row].rgbtGreen == 0 &&
                image[column][row].rgbtRed == 0)
            {
                // Change color to purple
                image[column][row].rgbtBlue = 120;
                image[column][row].rgbtGreen = 0;
                image[column][row].rgbtRed = 60;
            }
        }
    }
}
