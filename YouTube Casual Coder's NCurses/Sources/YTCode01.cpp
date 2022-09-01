// YTCode01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <curses.h>
using namespace std;

int main(int argc, char* argv[])
{
    // Initialize the Screen
    // Set up memory and clear the Screen
    initscr();

    int x, y;
    x = y = 10;

    // Move the cursor to the specified location
    move(y, x);

    // Prints a string (const char *) to a window 
    printw("Hello World!");

    // Refreshes the screen to match what's on memory
    refresh();

    // Wait for user input, returns int value of the key 
    int c = getch();
    refresh();

    // Clear the screen
    clear();

    /*
    *  This is replaced by mvprintw(...)
    *  move(0, 0);
    *  printw("%d", c);
    */

    mvprintw(0, 0, "%d", c);
    refresh();

    getch();

    endwin();
    // Deallocates memory and ends NCurses 

    return 0;
}
