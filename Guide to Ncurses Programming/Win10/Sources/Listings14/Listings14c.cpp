/*
* Set characters used to draw the box.
* Listing 14-3: box.c
*/

#include <curses.h>

int main()
{

    initscr();

    box(stdscr, '*', '*');
    refresh();
    getch();

    endwin();
    return 0;
}
