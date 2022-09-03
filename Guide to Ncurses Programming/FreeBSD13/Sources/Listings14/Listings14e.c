
/*
* hline() and vline() functions draw a horizontal or vertical line
* from the cursor’s current position (right or down, respectively).
* Listing 14-5: steps.c
*/

#include <curses.h>

int main()
{
    int y, x, maxy, maxx;

    initscr();

    getmaxyx(stdscr, maxy, maxx);

    for ( y = x = 0; y < maxy; y++, x+= 2)
    {
        move(y, x);
        hline(0, maxx - x);
        vline(0, maxy - y);
    }
    refresh();
    getch();

    endwin();
    return 0;
}
