
// Listing 4-3 corners1.c

#include <curses.h>

int main(void)
{
    int rows, cols;

    initscr();
    getmaxyx(stdscr, rows, cols);
    rows--;
    cols--;

    move(0, 0);                     /* UL corner */
    addch('*');
    refresh();
    napms(500);                     /* pause half a sec */

    move(0, cols);                 /* UR corner */
    addch('*');
    refresh();
    napms(500);

    move(rows, 0);                 /* LL corner */
    addch('*');
    refresh();
    napms(500);

    move(rows, cols);              /* LR corner */
    addch('*');
    refresh();
    getch();

    endwin();
    return 0;
}
