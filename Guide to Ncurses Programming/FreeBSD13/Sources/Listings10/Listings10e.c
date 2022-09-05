
/*
* The scroll() function scrolls text in the window win up one line. This
* works only if the window has its scrolling attribute set. When in doubt, set
* scrolling on with scrollok(win,TRUE), otherwise the scroll() function
* returns ERR.
* Listing 10-5: scrup1.c
*/

#include <curses.h>


int main()
{
    int maxy, maxx, y;
    initscr();

    getmaxyx(stdscr, maxy, maxx);
    scrollok(stdscr, TRUE);

    for (y = 0; y < maxy; y++)
        mvprintw(y, 0, "This is boring text written to line %d.", y);
    refresh();
    getch();

    scroll(stdscr);
    refresh();
    getch();

    endwin();
    return 0;
}
