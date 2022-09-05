
/*
* Display windows when a user hits the Help key or some other key
* on the keyboard.
* Listing 8-2: helpmenu1.c
*/

#include <curses.h>

void showhelp(void);

WINDOW* help;

int main(void)
{
    int ch;

    initscr();

/* build help menu */
    // if ((help = newwin(0, 0, 0, 0)) == NULL)   // Original source
    if ((help = newwin(10, 30, 4, 26)) == NULL)      // Added later in book to show window size.
    {
        addstr("Unable to allocate window memory\n");
        endwin();
        return(1);
    }
    /* --- Original in source ---
    mvwaddstr(help, 6, 32, "Help menu Screen");
    mvwaddstr(help, 9, 28, "Press the - key to quit");
    mvwaddstr(help, 12, 28, "Press ENTER to go back");
    */

    // Replacement of lines above added later in book to show window size
    mvwaddstr(help, 1, 7, "Help menu Screen");
    mvwaddstr(help, 5, 3, "Press the - key to quit");
    mvwaddstr(help, 8, 4, "Press ENTER to go back");

    /* now start the program loop */

    addstr("Typer Program\n");
    addstr("Press + for help:\n\n");
    refresh();
    noecho();
    do
    {
        ch = getch();
        refresh();
        if (ch == '+')
            showhelp();
        else
            addch(ch);
    } while (ch != '~');

    endwin();
    return 0;
    }

void showhelp(void)
{
    touchwin(help);             /* Not in original source, added to show use of touchwin() */
    wrefresh(help);
    getch();                            /* wait for key press */
    touchwin(stdscr);           /* Not in original, added by author to explain touchwin() */

    refresh();
}
