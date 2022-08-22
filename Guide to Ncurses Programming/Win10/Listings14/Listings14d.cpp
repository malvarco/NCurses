/*
* border() is specific to the standard screen, stdscr.
* There is a related, wborder() function where the first argument is win, for
* the window to be boxed. The arguments in border() are characters to place
* in one of the eight positions of the box: left, right, top, and bot are the
* sides of the box; uleft, uright, lleft, and lright are the corners.
* Listing 14-4: border.c
*/

#include <curses.h>

int main()
{    

    initscr();

    
    border(0x000000ba, 0x000000ba, 0x000000cd, 0x000000cd,
            0x000000c9, 0x000000bb, 0x000000c8, 0x000000bc);
           


    refresh();
    getch();

    endwin();
    return 0;
}
