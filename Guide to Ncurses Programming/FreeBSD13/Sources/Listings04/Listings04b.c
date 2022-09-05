
// Listing 4-2 stdscrsize.c

#include <curses.h>

int main(void)
{
    initscr();

    printw("Window size is %d rows, %d columns.\n", LINES, COLS);

    refresh();
    getch();
    endwin();
    return 0;
}
