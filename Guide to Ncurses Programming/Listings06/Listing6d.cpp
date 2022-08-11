/*
*  clrtobot() function (see Listing 6-4) takes all the text from the cursor’s
*  position to the last position on the screen and replaces the text with blanks
*  (spaces).
* Listing 6-4: blah5.c
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
    clrtobot();                     /* clear to the end of screen */
    refresh();
    getch();

    endwin();
    return 0;
}
