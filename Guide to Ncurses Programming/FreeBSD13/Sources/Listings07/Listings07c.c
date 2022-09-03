
/*
* Creating a kbhit() function.
* Listing 7-3: kbhit.c
*/

#include <curses.h>

int kbhit(void)
{
    int ch, r;

    /* turn off getch() blocking and echo */
    nodelay(stdscr, TRUE);
    noecho();

    /* check for input */
    ch = getch();
    if (ch == ERR)                 /* no input */
        r = FALSE;
    else                            /* input */
    {
        r = TRUE;
        ungetch(ch);
    }

    /* restore block and echo */
    echo();
    nodelay(stdscr, FALSE);
    return(r);
}

int main(void)
{
    initscr();

    addstr("Press any key to end this program:\n");
    while (!kbhit())
        ;

    endwin();
    return 0;
}
