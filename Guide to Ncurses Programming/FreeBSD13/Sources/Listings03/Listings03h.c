
// Listing3h.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <curses.h>

int main(void)
{
    initscr();

    addstr("Attention!\n");
    beep();
    refresh();
    getch();
    addstr("I said, ATTENTION!\n");
    flash();
    refresh();
    getch();
    endwin();
    return 0;
}
