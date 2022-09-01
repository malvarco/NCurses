/*
* Before mouse programming, check NCurses.
* Listing 13-1: mtest.c
* NOT WORKING WITH WIN10 PDCURSES 3.9
*/

#include <curses.h>

int main()
{
    mmask_t mmask;
       
    initscr();
       

    /* BLOCK IN ORIGINAL SOURCE NOT WORKING
    if (NCURSES_MOUSE_VERSION > 0)
           addstr("This version of NCurses supports the mouse.\n");
    else
        addstr("This version of NCurses does not support the mouse.\n");
    
    refresh();
        */

    
    getch();
    endwin();
    return 0;
}

