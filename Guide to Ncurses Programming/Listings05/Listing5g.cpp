// Listing 5.7 hamlet5.c

#include <curses.h>

int main(void)
{
    char Ham1[] = "To be, or not to be: that is the question:\n";
    char Ham2[] = "Whether 'tis nobler in the mind to suffer\n";
    char Ham3[] = "The slings and arrows of outrageous fortune,\n";
    char Ham4[] = "Or to take arms against a sea of troubles,\n";
    char Ham5[] = "And by opposing end them?\n";
    int c;

    initscr();

    addstr(Ham1);
    addstr(Ham2);
    addstr(Ham3);
    addstr(Ham4);
    addstr(Ham5);
    refresh();
    getch();                /* wait for key press */

    move(2, 25);         /* move to the start of "outrageous" */
    for ( c = 0; c < 11; c++)
            delch();            /* gobble! */
        refresh();
        getch();
    
    endwin();
    return 0;
}
