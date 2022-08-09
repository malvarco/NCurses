// Listing3f.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <curses.h>

int main(void)
{
    initscr();

    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    bkgd(COLOR_PAIR(1));
    // bkgd('.');                       // Alternative line, dots instead
    // bkgd(COLOR_PAIR(1) | '.');       // Alt. line, mix colors and dots.

    addstr("So this is what a color screen looks like?\n");

    refresh();
    getch();

    endwin();
    return 0;
}
