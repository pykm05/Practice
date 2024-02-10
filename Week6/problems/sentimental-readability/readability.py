# TODO
from cs50 import get_string


def main():
    # index = 0.0588 * L - 0.296 * S - 15.8
    # Get user input
    input = get_string("Text: ")

    # Average number of letters per 100 words
    letters = 0
    words = 1
    sentences = 0

    # Iterate through each character from input
    for i in range(len(input)):
        # Check if current character is letter
        if ((input[i] >= "a") & (input[i] <= "z")) or (
            (input[i] >= "A") & (input[i] <= "Z")
        ):
            letters += 1

        # Increase word counter for each space
        if input[i] == " ":
            words += 1

        # Increase sentence counter for punctuation
        if input[i] == "." or input[i] == "!" or input[i] == "?":
            sentences += 1

    # Use formula to determine age
    calc = (0.0588 * letters / words * 100) - (0.296 * sentences / words * 100) - 15.8
    grade = round(calc)

    # Print response based on calculation
    if grade < 1:
        print("Before Grade 1\n")
        return 0

    if grade >= 16:
        print("Grade 16+\n")
        return 0

    else:
        print("Grade ", +grade)
        return 0


main()
