
/*
* delwin() removes the window’s internal structure and memory used by
* the window, but it does not erase the window’s screen image. To do
* that, you’ll have to wrefresh(), and possibly touchwin(), another
* window on the screen.
* Listing 8-3: twowin2.c.c
*/

#include <curses.h>

int main(void)
{
    WINDOW* two;                    /* pointer for new window */

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
    wrefresh(two);
    getch();

    delwin(two);
    addstr("The second window was removed.\n");
    touchwin(stdscr);               /* Added later in the book */
    refresh();
    getch();

    endwin();
    return 0;
}
