#include <stdio.h>
#include <string.h>

typedef struct
{
    int level;
    int dungeon;
    string inventory;
    int health;
    int attack;
}
stats;

int turn(string name, char initialize, int health);
int begin(string name, int health);

int main(void)
{
    string name = get_string("Welcome, player! Enter your name: ");
    printf("Hello, %s\n", name);
    player stat[1];
    stat[0].health = 100;
    begin(name, stat[0].health);
    return 1;
}

int begin(string name, int health)
{
    char initialize = get_char("Type d for dungeon, s for stats, and i for inventory: ");
    switch (initialize)
    {
        char i;
        case 'd':
            i = 'd';
            printf("%i\n", turn(name, i, health));
            break;

        case 's':
            i = 's';
            printf("%i\n", turn(name, i, health));
            break;

        default:
            printf("n is neither -1 nor 1\n");
            break;
    }
    return 1;
}

int turn(string name, char initialize, int health)
{
    if (initialize == 'd')
    {
        health -= 11;
        printf("this is a dungeon %i\n", health);
        begin(name, health);
    }
        if (initialize == 's')
    {
        printf("this is stats %i\n", health);
        begin(name, health);
    }
    return health;
}