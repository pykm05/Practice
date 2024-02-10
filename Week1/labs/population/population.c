#include <cs50.h>
#include <stdio.h>

void calc_year(int startSize, int endSize);

int main(void)
{
    // Prompt for start size
    int startSize;
    int endSize;
    do
    {
        startSize = get_int("Enter a starting size: ");
    }
    while (startSize < 9);

    // Prompt for end size
    do
    {
        endSize = get_int("Enter an ending size: ");
    }
    while (endSize < startSize);
    calc_year(startSize, endSize);
}

void calc_year(int s, int f)
{
    // TODO: Calculate number of years until we reach threshold
    int years = 0;
    while (s < f)
    {
        s = s + (s / 3) - (s / 4);
        years ++;
    }
    // TODO: Print number of years
    printf("Years: %d\n", years);
}


