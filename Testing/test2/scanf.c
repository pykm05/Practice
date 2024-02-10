#include <stdio.h>

int main()
{
    char *filename = "test.txt";

    // open the file for writing
    FILE *fp = fopen(filename, "a");
    if (fp == NULL)
    {
        printf("Error opening the file %s", filename);
        return -1;
    }
    // write to the text file
    for (int i = 0; i < 10; i++)
        fprintf(fp, "This is the line #%d\n", i + 1);

    // close the file
    fclose(fp);

    return 0;
}
/*
int main(void)
{
    char s[4];
    printf("s: ");
    scanf("%s", s);
    printf("s: %s\n", s);
}
*/