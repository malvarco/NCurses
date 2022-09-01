// Listing2e.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <curses.h>

int main(void)
{
    char ch;

    initscr();
    addstr("Type a few lines of text\n");
    addstr("Press ~ to quit\n");
    refresh();
    
    while ((ch = getch()) != '~');
    endwin();
    return 0;
}