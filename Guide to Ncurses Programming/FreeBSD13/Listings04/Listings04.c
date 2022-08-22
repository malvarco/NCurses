
// Listing4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <curses.h>

int main(void)
{
    int x, y;
    initscr();

    getmaxyx(stdscr, y, x);
    printw("Window size is %d rows, %d columns.\n", y, x);

    refresh();
    getch();
    endwin();
    return 0;
}

