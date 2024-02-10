#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    string number;
    string value;
}


float average();

int main(void)
{
    int values[5];
    for (int i = 0 ; i < 5; i++)
    {
        do
        {
            values[i] = get_int("Input a value: ");
        }
        while (values[i] >= 100);
    }
    string request = get_string("A for average, S for sum, and P for product: ");
    return 1;
}
