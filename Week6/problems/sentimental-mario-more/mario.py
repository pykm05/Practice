# TODO
from cs50 import get_int


def main():
    height = get_height()

    # Build the first half
    for i in range(height):
        for j in range(height - i - 1):
            print(" ", end="")

        for k in range(i + 1):
            print("#", end="")

        # Build the second half
        print("  ", end="")
        for k in range(i + 1):
            print("#", end="")

        print("")


# Get user input for height
def get_height():
    while True:
        try:
            n = get_int("Height: ")
            if (n > 0) & (n < 9):
                return n
        except ValueError:
            print("Not an integer")


main()