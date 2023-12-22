
// Listing3c.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <curses.h>
#include <stdlib.h>

// void bomb(char* msg);           // Original source causes error
 void bomb(const char* msg);         // Added 'const' to 'char*' to fix error

int main(void)
{
    initscr();

    /* first test for color ability of the terminal */
    if (!has_colors())
        bomb("Terminal cannot do colors\n");

    /* next attempt to initialize curses colors */
    if (start_color() != OK)
        bomb("Unable to start colors.\n");

    /* colors are okay; continue */
    printw("Colors have been propertly initialized.\n");
    printw("Congratulations!\n");
    printw("NCurses reports that you can use %d colors, \n", COLORS);
    printw("and %d color pairs.", COLOR_PAIRS);

    refresh();
    getch();

    endwin();
    return 0;
}

// void bomb(char* msg) // Original source causes error
void bomb(const char* msg)
{
    endwin();
    puts(msg);
    exit(1);
}
