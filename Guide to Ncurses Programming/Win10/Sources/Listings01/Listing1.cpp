// Listing1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <curses.h>


int main(void)
{
    initscr();
    addstr("Goodbye, cruel C programming!");
    refresh();
    getch();

    endwin();
    return 0;
}