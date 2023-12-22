/*
Get back to cooked mode (normal line buffering mode) temporarily.
First save the tty modes with a call to def_prog_mode() and then call endwin() to end the curses mode.
*/

#include <curses.h>
#include <stdlib.h>

int main()
{
    initscr();                              /* Start curses mode */
    printw("Hello World !!!\n");            /* Print Hello World */
    refresh();                              /* Print it on to the real screen */
    getch(); // Added by me not in original source
    def_prog_mode();                        /* Save the tty modes */
    endwin();                               /* End curses mode temporarily */
    //system("/bin/sh"); // Original source /* Do whatever you like in cooked mode */
    system("pwsh"); // Not in original, go to powershell  /* Do whatever you like in cooked mode */
    reset_prog_mode();                      /* Return to the previous tty mode */
                                            /* stored by def_prog_mode() */
    refresh();                              /* Do refresh() to restore the */
                                            /* Screen contents */
    printw("Another String\n");             /* Back to curses use the full */
    refresh();                              /* capabilities of curses */
    getch(); // Added by me not in original source
    endwin();                               /* End curses mode */
    return 0;
}
