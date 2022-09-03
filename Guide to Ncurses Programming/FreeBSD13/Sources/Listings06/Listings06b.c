
/*
* This code shows how the clear function is used to clear the screen.
* Listing 6-2: blah2.c
*/

#include <curses.h>

int main(void)
{
    int c, y, x, cmax;

    initscr();

    getmaxyx(stdscr, y, x);
    cmax = (x * y) / 5;
    for (c = 0; c < cmax; c++) addstr("blah ");
    refresh();

    getch();

    clear();                    /* clear the screen */
    // erase();                    /* same as clear(), but less thorough */
    refresh();                  /* don't forget this! */
    getch();

    endwin();
    return 0;
}
