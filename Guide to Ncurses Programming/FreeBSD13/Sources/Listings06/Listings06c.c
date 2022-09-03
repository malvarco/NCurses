
/*
*  clrtoeol() function (Listing 6-3) is used to erase text from
*  the cursor’s position to the end of the current line. If you use
*  the vi/vim editor, this is equivalent D.
* Listing 6-3: blah4.c
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

    move(5, 20);                    /* Setup the cursor */
    clrtoeol();                     /* clear to the end of line */
    refresh();
    getch();

    endwin();
    return 0;
}
