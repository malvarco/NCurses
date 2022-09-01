// Listing3d.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <curses.h>
#include <stdlib.h>

// void bomb(int r); // In original source, but not needed.

int main(void)
{
    initscr();
    start_color();

    init_pair(1, COLOR_BLACK, COLOR_RED);
    init_pair(2, COLOR_BLUE, COLOR_BLACK);
    attrset(COLOR_PAIR(1));
    addstr("My name is Mr. Black!\n");
    attrset(COLOR_PAIR(2));
    addstr("My name is Mr. Blue!\n");
    attrset(COLOR_PAIR(1));
    addstr("How do you do?\n");
    attrset(COLOR_PAIR(2));
    addstr("How do I do ");
    attron(A_BOLD);
    addstr("what");
    attroff(A_BOLD);
    addch('?');

    refresh();
    getch();

    endwin();
    return 0;
}
