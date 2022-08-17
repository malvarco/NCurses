// Listingf.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// * Prefer getnstr() over getstr() which is safer

#include <curses.h>

int main(void)
{
    char first[24];
    char last[32];

    initscr();
    addstr("What is your first name? ");
    refresh();
    getstr(first);
    /* No need for refresh() with getstr() and getch() */

    addstr("What is your last name? ");
    refresh();
    getstr(last);

    printw("Pleased to meet you, %s %s!", first, last);
    refresh();
    getch();

    endwin();
    return 0;
}