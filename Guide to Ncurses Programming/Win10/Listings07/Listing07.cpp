/*
*    The following program in Listing 7-1 demonstrates how getch()’s personal-
* ity can be changed by using the nodelay() function.
* Listing 7-1: keywait1.c
*/

#include <curses.h>

int main(void)
{
    int value = 0;

    initscr();

    addstr("Press any key to begin:\n");
    refresh();
    getch();

    nodelay(stdscr, TRUE);              /* turn off getch() wait */
    addstr("Press any key to stop the insane loop!\n");
    while (getch() == ERR)
    {
        printw("%d\r", value++);
        refresh();
    }

    endwin();
    return 0;
}
