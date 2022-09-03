
/*
* subpad is created in memory and a pointer to a WINDOW
* structure is returned by subpad(). If NULL is returned,
* the subpad was not created.
* Listing 11-3: sonofpad.c
*/

#include <curses.h>
#include <stdlib.h>

// void bomb(char* message); // Original source, needs 'const'
void bomb(const char* message);        // Added 'const' to 'char*'

int main()
{
    WINDOW* pod, *pea;

    initscr();

    /* create a new pad */
    pod = newpad(50, 50);
    if (pod == NULL)
        bomb("Unable to create new pad\n");

    addstr("New pad created\n");
    refresh();

    /* create a subpad */
    pea = subpad(pod, 20, 20, 29, 29);

    if (pea == NULL)
        bomb("Unable to create subpad");

    addstr("Subpad created\n");
    refresh();
    getch();

    endwin();
    return (0);
}

// void bomb(char* message) // Original source, needs 'const' for WIN10
void bomb(const char* message)      // Added 'const' to 'char*' for WIN10
{
    addstr(message);
    refresh();
    getch();
    endwin();
    exit(1);
}
