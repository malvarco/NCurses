
/*
* Code to create two windows on the screen. The first, naturally,
* is the standard screen. But the newwin() function
* in line 13 creates a second window, named two.
Listing 8-1: twowin1.c
*/

#include <curses.h>

int main(void)
{
    WINDOW* two;                            /* pointer for new window */

    initscr();

    addstr("This is the original window, stdscr.\n");
    refresh();
    getch();

    two = newwin(0, 0, 0, 0);
    if (two == NULL)
    {
        addstr("Unable to allocate memory for new window.");
        endwin();
        return(1);
    }
    waddstr(two, "This is the new window created!\n");

    wrefresh(two);          // Not in original source. Added as example of wrefresh vs. refresh
    getch();
    endwin();
    return 0;
}
