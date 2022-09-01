/*
* scrl() function scrolls the standard screen n number of lines. So to
* scroll up three lines, scrl(3) would be used.
* Listing 10-6: scrup2.c
*/

#include <curses.h>

int main()
{
    initscr();
    int maxy, maxx, y;

    getmaxyx(stdscr, maxy, maxx);
    scrollok(stdscr, TRUE);

    for (y = 0; y < maxy; y++)
        mvprintw(y, 0, "This is boring text written to line %d.", y);
    refresh();
    getch();

    // scrl(3);  // Original source
    scrl(-3);     // Added later in book as example
    refresh();
    getch();

    endwin();
    return 0;
}
