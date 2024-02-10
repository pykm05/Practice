#include <stdio.h>
#include <string.h> // strcmp()
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>

// malloc gives the address of the first byte of the free memory
// If you use malloc you MUST use free
// malloc(# of bytes)
// malloc can potentially return NULL(address 0)
// malloc will look through heap and will give back a pointer to memory
// if malloc can't give any memory because you've run out, it will return NULL
// this is why whenever you run malloc you need to check if it is not NULL
// this is because if you try to dereference the null pointer you will suffer from a segmentation fault
// use valgrind ./(file name) to see where memory was lost in your program

int main(void)
{
    int x; // statically obtain an integer in stack
    int *px = malloc(sizeofint()); // dynamically obtain an integer in heap. It will give 4 bytes of memory from heap
    int y = GetInt(); // get an integer from user
    float stack_array[x]; // array of floats on the stack
    char *c = malloc(x * sizeof(float)); // array of floats on the heap
    // get_string will return NULL if something goes wrong(like too much text)
    if (c == NULL)
    {
        return 1;
    }
    char *d = malloc(strlen(c) + 1);
    if (d == NULL)
    {
        return 1;
    }

    strcpy(c, d);

    if (strlen(c) > 0)
    {
        d[0] = toupper(d[0]);
    }

    printf("c: %s\n", c);
    printf("d: %s\n", d);

    // whenever you allocate memory with alloc, you must free it when you're done with it
    free(d);

    return 0;
}

int memory()
{
    int *x = malloc(3 * sizeof(int));
    if (x == NULL)
    {
        return 1;
    }
    x[0] = 12;
    x[1] = 54;
    x[2] = 76;
    free(x);
    return 0;
}