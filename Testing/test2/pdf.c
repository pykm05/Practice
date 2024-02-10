#include <stdio.h>
#include <stdint.h> // required for buffer
#include <cs50.h>

int main(int argc, string argv[])
{
    //Check if there is only 1 argument
    if (argc != 2)
    {
        printf("Improper usage.\n");
        return 1;
    }

    // Open file
    string filename = argv[1];
    // "r" = read and "w" = write
    FILE *file = fopen(filename, "r");

    // Check if file exists
    if (file == NULL)
    {
        printf("No such file exists.\n");
        return 1;
    }
    // buffer size of 4 to read 4 units
    uint8_t buffer[4];
    uint8_t signature[] = {37, 80, 68, 70};

    fread(buffer, 1, 4, file);
    // Arg1: where to read into
    // Arg2: size of blocks(objects) in bytes (in pdf it is composed of single bytes)
    // Arg3: how many blocks
    // Arg4: where is the file reading from
    // the fread function will return the number of elements succesfully read from the file
    for (int i = 0; i < 4; i++)
    {
        if (buffer[i] != signature[i])
        {
            printf("Likely not a PDF.\n");
            return 0;
        }
        printf("%i", buffer[i]);
        return 0;
    }

}