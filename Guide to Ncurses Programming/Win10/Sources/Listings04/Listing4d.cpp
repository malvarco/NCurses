// Listing 4-4 corners2.c

#include <curses.h>

int main(void)
{
    int rows, cols;

    initscr();
    getmaxyx(stdscr, rows, cols);
    rows--;
    cols--;

    mvaddch(0, 0, '*');                     /* UL corner */
    refresh();
    napms(500);                     /* pause half a sec */

    mvaddch(0, cols, '*');                 /* UR corner */
    refresh();
    napms(500);

    mvaddch(rows, 0, '*');                 /* LL corner */
    refresh();
    napms(500);

    mvaddch(rows, cols, '*');              /* LR corner */
    refresh();
    getch();

    endwin();
    return 0;
}