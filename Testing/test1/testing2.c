#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string fruit[] = {"apples", "oranges", "bananas"};
    string price[] = {"0.99", "1.10", "1.50"};

    string input = get_string("Name a fruit: ");
    for (int i = 0; i < 3; i++)
    {
        if (strcmp(fruit[i], input) == 0)
        {
            printf("%s\n", price[i]);
            return 0;
        }
        printf("Not found.\n");
        return 1;
    }

}