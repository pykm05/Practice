#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;

    // Pointer to the next element
    struct node *next;
}
// Name of the node
node;

void unload(node *list);

int main(int argc, char *argv[])
{
    node *list = NULL;

    for (int i = 0; i < argc; i++)
    {
        int number = atoi(argv[i]);

        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }
        n->number = number;
        n->next = list;

        list = n;
    }
    unload(list);
}

void unload(node *list) {
    while(list != NULL) {
        printf("%i\n", list->number);
        node *ptr = list->next;
        free(list);
        list = ptr;
    }

}
