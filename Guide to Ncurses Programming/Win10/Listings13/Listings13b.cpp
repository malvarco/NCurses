/*
* ALL_MOUSE_EVENTS constant can be used to determine whether
* terminal can see anything the mouse does 
* Listing 13-2: mtest.c
*/

#include <curses.h>

int main()
{
    mmask_t mmask;

    initscr();


    /* BLOCK IN ORIGINAL SOURCE DOES NOT WORK ON WIN10 PDCURSES 3.9
    if (NCURSES_MOUSE_VERSION > 0)
           addstr("This version of NCurses supports the mouse.\n");
    else
        addstr("This version of NCurses does not support the mouse.\n");

          refresh();
        */

    mmask = mousemask(ALL_MOUSE_EVENTS, NULL);
    if (mmask == 0)
        addstr("Unable to access the mouse on this terminal.\n");
    else
        addstr("Mouse events can be captured.\n");
    refresh();
  
    getch();
    endwin();
    return 0;
}

