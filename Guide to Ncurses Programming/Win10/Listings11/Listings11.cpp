/*
* Pads are created like windows. Though a new command is used to actually create the pad:
* newpad(rows,cols)
* Listing 11-1: bigpad1.c
*/

#include <curses.h>


int main()
{
    WINDOW* p;
    int x, c;

    initscr();

    /* create a new pad */
    p = newpad(50, 100);
    if (p == NULL)
    {
        addstr("Unable to create new pad");
        refresh();
        endwin();
        return(1);
    }

    // addstr("New pad created");   // Original source
    // refresh();                   // Original source

    waddstr(p, "New pad created");      // Added later in book as pad example.
    // wrefresh(p);                        // Added later, changed after.
    prefresh(p, 0, 0, 0, 0, 1, 15);

    endwin();
    return (0);
}
