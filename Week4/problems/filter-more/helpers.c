#include "helpers.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
            {
                double average = (image[i][j].rgbtRed + image[i][j].rgbtGreen +
                image[i][j].rgbtBlue) / 3;

                image[i][j].rgbtRed = average;
                image[i][j].rgbtGreen = average;
                image[i][j].rgbtBlue = average;
            }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a temporary copy of image
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Count number of neighboring pixels
            float count = 0.00;
            int count_Red, count_Green, count_Blue = 0;
            count_Red = count_Green = count_Blue = 0;

            // Check the neighboring pixels
            for (int x = - 1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    // Keep track of current pixel
                    int currentX = i + x;
                    int currentY = j + y;

                    // Check if neighboring pixel is a boundary
                    if (currentX < 0 || currentX > (height - 1) ||
                        currentY < 0 || currentY > (width - 1))
                    {
                        continue;
                    }

                    // Add the color value to sum to calculate average later
                    count++;
                    count_Red += temp[currentX][currentY].rgbtRed;
                    count_Green += temp[currentX][currentY].rgbtGreen;
                    count_Blue += temp[currentX][currentY].rgbtBlue;
                }

            temp[i][j].rgbtRed = round(count_Red / count);
            temp[i][j].rgbtGreen = round(count_Green / count);
            temp[i][j].rgbtBlue = round(count_Blue / count);
            }
        }
    }
    for (int i = 0; i < height; i ++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a temporary copy of image
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    int arrayX[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, -1}};
    int arrayY[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int redX = 0;
            int greenX = 0;
            int blueX = 0;
            int redY = 0;
            int greenY = 0;
            int blueY =  0;

            // Check neighboring pixels
            for (int x = 0; x < 3; x++)
            {
                for (int y = 0; y < 3; y++)
                {
                    // Check if current pixel is invalid
                    if (i - 1 + x < 0 || i - 1 + x > height - 1 ||
                        j - 1 + y < 0 || j - 1 + y > width - 1)
                    {
                        continue;
                    }

                    // Calculate for x value
                    redX = redX + (image[i - 1 + x][j - 1 + y].
                    rgbtRed * arrayX[x][y]);
                    blueX = blueX + (image[i - 1 + x][j - 1 + y].
                    rgbtBlue * arrayX[x][y]);
                    greenX = greenX + (image[i - 1 + x][j - 1 + y].
                    rgbtGreen * arrayX[x][y]);

                    // Calculate for y value
                    redY = redY + (image[i - 1 + x][j - 1 + y].
                    rgbtRed * arrayY[x][y]);
                    blueY = blueY + (image[i - 1 + x][j - 1 + y].
                    rgbtBlue * arrayY[x][y]);
                    greenY = greenY + (image[i - 1 + x][j - 1 + y].
                    rgbtGreen * arrayY[x][y]);

                }
            }

            // Calculate the square root (formula)
            int red = round(sqrt((redX * redX) + (redY * redY)));
            int green = round(sqrt((greenX * greenX) + (greenY * greenY)));
            int blue = round(sqrt((blueX * blueX) + (blueY * blueY)));

            // Make sure no values go over 255
            if (red > 255)
            {
                red = 255;
            }

            if (green > 255)
            {
                green = 255;
            }

            if (blue > 255)
            {
                blue = 255;
            }

            // Copy values into temp image
            temp[i][j].rgbtRed = red;
            temp[i][j].rgbtGreen = green;
            temp[i][j].rgbtBlue = blue;

        }
    }

    // Copy temp into original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }
    return;
}

