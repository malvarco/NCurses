// Listing 5.6 hamlet4.c

#include <curses.h>

int main(void)
{
    char Ham1[] = "To be, or not to be: that is the question:\n";
    char Ham2[] = "Whether 'tis nobler in the mind to suffer\n";
    char Ham3[] = "The slings and arrows of outrageous fortune,\n";
    char Ham4[] = "Or to take arms against a sea of troubles,\n";
    char Ham5[] = "And by opposing end them?\n";

    initscr();

    addstr(Ham1);
    addstr(Ham2);
    addstr(Ham3);
    addstr(Ham4);
    addstr(Ham5);
    refresh();
    getch();                /* wait for key press */

    move(1, 0);         /* move to the line to delete */
    deleteln();         /* Delete and backscroll */
    refresh();
    getch();                /* wait for key press */

    endwin();
    return 0;
}
