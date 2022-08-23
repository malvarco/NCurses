
/*
* mvwin() function moves window win to new location row, col,
* relative to the standard screen.
* Listing 10-7: windrop.c
*/

#include <curses.h>

#define TSIZE 18

int main()
{
    WINDOW* b;
    int maxy, maxx, y, x;

    initscr();

    getmaxyx(stdscr, maxy, maxx);

    x = (maxx - TSIZE) >> 1;

    bkgd('.');           // Added later in book as example.
    refresh();          // Added later in book as example.

    b = newwin(1, TSIZE, 0, x);
    waddstr(b, "I'm getting sick!");

    for ( y = 1; y < maxy; y++)
    {
        mvwin(b, y, x);
        wrefresh(b);
        touchline(stdscr, y - 1, 1);    // Added later in book as example.
        refresh();                      // Added later in book as example.
        getch();
    }

    endwin();
    return (0);
}
