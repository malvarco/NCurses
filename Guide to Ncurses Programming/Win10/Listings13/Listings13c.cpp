/*
* Get information about where the mouse was clicked and displays
* those coordinates on the screen.
* Listing 13-3: mspy.c / clickput.c
*/

#include <curses.h>

int main()
{
    MEVENT mort;
    int ch;
   
    initscr();
    noecho();
    keypad(stdscr, TRUE);

    mousemask(ALL_MOUSE_EVENTS, NULL);

    while (1)
    {
        ch = getch();
        if (ch == KEY_MOUSE)
        {
         // getmouse(&mort);      // Original source not working
         nc_getmouse(&mort);      // Fix for PDCURSES

            move(0, 0);
            clrtoeol();
            printw("%d\t%d", mort.y, mort.x);

            mvaddch(mort.y, mort.x, '*');       // Solution exercise "On Your Own"

            refresh();
            continue;
        }
        if (ch == '\n')
            break;
        }

    endwin();
    return 0;
}

