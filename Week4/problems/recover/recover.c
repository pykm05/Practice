#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Check that the argument count is 2
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // Open file for reading
    FILE *input_file = fopen(argv[1], "r");

    if (input_file == NULL)
    {
        printf("Usage: ./recover IMAGE\n");
        return 2;
    }

    // Signed char can store postitive and negative numbers
    // We will not be recieving negative values so we will used unsigned char
    // Store blocks of 512 into the array
    unsigned char buffer[512];

    // Track the number of images we are generating
    int count_image = 0;

    // File pointer for recovered images
    FILE *output_file = NULL;

    // char filename[8]
    char *filename = malloc(8 * sizeof(char));

    while (fread(buffer, sizeof(char), 512, input_file))
    {
        // Check if byte indicate start of JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2]
            == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (count_image > 0)
            {
                fclose(output_file);
            }
            // Write the JPEG file names
            // Arg 1: Pointer to an array of char elements where the resulting C string is stored
            // Arg 2: Format of what to print. The file we generate should be named a three-digit decimal.
            // This means that we will print 0 in front of the number, up to 3 places.
            // Arg 3: The i value to print in the file name
            sprintf(filename, "%03i.jpg", count_image);

            // Open output file for writing
            output_file = fopen(filename, "w");

            // Count number of images found
            count_image++;
        }
        if (output_file != NULL)
        {
            fwrite(buffer, sizeof(char), 512, output_file);
        }
    }

    free(filename);
    fclose(output_file);
    fclose(input_file);

    return 0;
}