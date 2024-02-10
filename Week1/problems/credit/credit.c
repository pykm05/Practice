#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get credit card number
    long input = get_long("Number: ");

    // Find last number of credit card
    int lastDigit = input % 10;
    int secondLast = (input % 100 - lastDigit) / 10;
    // long temp = ((input % factor) - (input % (factor / 10))) / 10;

    long factor = 100;
    long sum = 0;

    // Go through every other number
    for (int i = 0; i < 8; i++)
    {
        // Formula to go through every other number
        long temp = ((input % factor) - (input % (factor / 10))) / (factor / 10);

        // Multiply each digit by 2
        temp = temp * 2;

        // Split up the product's characters
        if (temp >= 10)
        {
            temp = (temp % 10) + (temp % 100) / 10;
        }

        // Add the digits to the sum
        sum += temp;

        // Skip every other number
        factor = factor * 100;
    }

    // Find the remaining numbers and add it to sum
    factor = 10;
    for (int i = 0; i < 8; i++)
    {
        long temp = ((input % factor) - (input % (factor / 10))) / (factor / 10);

        // Split up the product's characters
        if (temp >= 10)
        {
            temp = (temp % 10) + (temp % 100) / 10;
        }

        // Add the digits to the sum
        sum += temp;

        // Skip every other number
        factor = factor * 100;
    }

    // Number is invalid if the sum doesn't end with a 0
    if (sum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    // Determine which credit card company based on card digit length
    // American Express: 15
    if (input / 100000000000000 < 10 && input / 100000000000000 > 0)
    {
        int remainder = input / 10000000000000;
        if (remainder == 34 || remainder == 37)
        {
            printf("AMEX\n");
            return 0;
        }
        else
        {
            printf("INVALID\n");
            return 0;
        }
    }

    // Visa and Mastercard: 16
    if (input / 1000000000000000 < 10 && input / 1000000000000000 > 0)
    {
        int remainder = input / 100000000000000;
        if (remainder / 10 == 4)
        {
            printf("VISA\n");
            return 0;
        }

        if (remainder == 51 || remainder == 52 || remainder == 53 || remainder == 54 ||
            remainder == 55)
        {
            printf("MASTERCARD\n");
            return 0;
        }
        else
        {
            printf("INVALID\n");
            return 0;
        }
    }

    // Visa: 13
    if (input / 1000000000000 < 10 && input / 1000000000000 > 0)
    {
        printf("VISA\n");
        return 0;
    }

    else
    {
        printf("INVALID\n");
        return 0;
    }
}