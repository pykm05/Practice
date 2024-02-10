# TODO

from cs50 import get_int
import math


def main():
    # Get user input and find first and last digits
    input = get_int("Number: ")

    lastDigit = math.floor(input % 10)
    secondLast = math.floor(math.floor(input % 100 - lastDigit) / 10)

    factor = 100
    sum = 0

    # Find every other number from input
    for i in range(8):
        # Formula to go through every other number
        temp = (
            math.floor(input % factor) - math.floor(input % math.floor(factor / 10))
        ) / math.floor(factor / 10)

        # Multiply each digit by 2
        temp = temp * 2

        # Split up the product's characters
        if temp >= 10:
            temp = math.floor(temp % 10) + math.floor(math.floor(temp % 100) / 10)

        # Add the digits to the sum
        sum += temp

        # Skip every other number
        factor = factor * 100

    # Find the remaining numbers and add it to sum
    factor = 10
    for i in range(8):
        temp = (
            math.floor(input % factor) - math.floor(input % math.floor(factor / 10))
        ) / math.floor(factor / 10)

        # Split up the product's characters
        if temp >= 10:
            temp = math.floor(temp % 10) + math.floor(math.floor(temp % 100) / 10)

        # Add the digits to the sum
        sum += temp

        # Skip every other number
        factor = factor * 100

    # Number is invalid if the sum doesn't end with a 0
    if math.floor(sum % 10) != 0:
        print("INVALID\n")
        return 0

    # Determine which credit card company based on card digit length
    # American Express: 15
    if (math.floor(input / 100000000000000) < 10) & (
        math.floor(input / 100000000000000) > 0
    ):
        remainder = math.floor(input / 10000000000000)
        if remainder == 34 or remainder == 37:
            print("AMEX\n")
            return 0

        else:
            print("INVALID\n")
            return 0

    # Visa and Mastercard: 16
    if (math.floor(input / 1000000000000000) < 10) & (
        math.floor(input / 1000000000000000) > 0
    ):
        remainder = math.floor(input / 100000000000000)
        if math.floor(remainder / 10) == 4:
            print("VISA\n")
            return 0

        if (
            (remainder == 51)
            or (remainder == 52)
            or (remainder == 53)
            or (remainder == 54)
            or (remainder == 55)
        ):
            print("MASTERCARD\n")
            return 0

        else:
            print("INVALID\n")
            return 0

    # Visa: 13
    if (math.floor(input / 1000000000000) < 10) & (
        math.floor(input / 1000000000000) > 0
    ):
        print("VISA\n")
        return 0

    else:
        print("INVALID\n")
        return 0


main()