
/*
* Ncurses Tutorial 10 - Input Modes
*/

#include <curses.h>
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	// Start ncurses
	initscr();
	noecho();

	// Input modes
	// cbreak();				// Don't send input to buffer, so input is faster
	// halfdelay(5);			// Delay of 1/10 second for input, so rest of program is not interrupted
	// nodelay(stdscr, true);	// Doesn't wait for input at all
	timeout(500);				// Wait for input


	int c;
	while ((c= getch())!='x')
	{
		printw("%d\n", c);
	}

	endwin();
	// End ncurses

	return 0;
}
