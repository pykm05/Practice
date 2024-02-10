#include <stdio.h>

int main(int argc, char *argv[])
{
    // Make sure there is only one argument
    if (argc != 2)
    {
        printf("Argument error.\n");
        return 1;
    }
    char *filename = argv[1];
    FILE *ptr = fopen(filename, "a");
    if (ptr == NULL)
    {
        printf("Error opening the file %s.\n", filename);
        return 1
    }


    fprintf(ptr, "Hello, world");
    fprintf(ptr, "Hello, dad");
    fputc('!', ptr);

    fclose(ptr);
    fopen(filename, "r");
    char ch;
    while ((ch = fgetc(ptr)) != EOF)
    {
        printf("%c", ch);
        fprintf(ptr, "hi");
    }
    fclose(ptr);

    return 0;
}