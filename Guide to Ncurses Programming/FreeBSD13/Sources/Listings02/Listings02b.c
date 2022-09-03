
// Listing2b.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <curses.h>

int main(void)
{
    char text1[] = "Oh give me a clone!\n";
    char text2[] = "Yes a clone of my own!";

    initscr();
    addstr(text1);       /* add the first string */
    addstr(text2);       /* add the second string */
    refresh();          /* display the result */
    getch();            /* wait */

    endwin();
    return 0;
}
