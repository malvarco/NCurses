
/*
* Listing 7-5 inserts the flushinp() function before getnstr().
* Because input is flushed, anything you type will be erased
* from the buffer and getnstr() will just have to wait!
* Listing 7-5: flush2.c
*/

#include <curses.h>

int main(void)
{
    char buffer[81];

    initscr();

    addstr("Type on the keyboard whilst I wait... \n");
    refresh();
    napms(5000);                /* 5 seconds */

    addstr("Here is what you typed:\n");
    flushinp();
    getnstr(buffer, 80);
    refresh();

    endwin();
    return 0;
}
