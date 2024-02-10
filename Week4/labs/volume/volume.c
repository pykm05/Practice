// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file

    uint8_t header[HEADER_SIZE];
    fread(header, HEADER_SIZE, 1, input);

    // Write the header into the output file
    fwrite(header, HEADER_SIZE, 1, output);

    // Read the rest of the .wav file (2 byte at a time)

    int16_t buffer;
    while (fread(&buffer, sizeof(int16_t), 1, input))
    {
        // Write new sample to output file
        buffer *= factor;
        fwrite(&buffer, sizeof(int16_t), 1, output);
    }
    /*
    // Free malloc'd memory
    for (int i = 0; i < HEADER_SIZE, i++)
    {
        free(header[i]);
    }
    for (int i = 0; i < sample_length, i++)
    {
        free(buffer[i]);
    }
    */
    fclose(input);
    fclose(output);
}
