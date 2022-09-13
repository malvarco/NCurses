#include <curses.h>
using namespace std;

int main(int argc, char* argv[])
{
    // Initialize the Screen
    // Set up memory and clear the Screen
    initscr();

    // Prints a string (const char *) to a window
    printw("Hello World!");

    // Refreshes the screen to match what's on memory
    refresh();

    // Wait for user input, returns int value of the key
    int c = getch();

    printw("%d", c);

    getch();

    endwin();
    // Deallocates memory and ends NCurses

    return 0;
}
