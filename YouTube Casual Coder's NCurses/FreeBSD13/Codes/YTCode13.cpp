
/*
* Ncurses Tutorial 13 - Detecting Ctrl+ [key] combinations Attributes/Colors
* Bit modified by me
*/

#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

#define ctrl(a) ('a' & 0x1F)		// Added later in video

int main(int argc, char** argv)
{
	// Start ncurses
	initscr();
	noecho();
	char ch;
	while (ch = getch())
	{
		mvprintw(1, 0, "KEY NAME : %s - 0x%02x\n", keyname(ch), ch);
		// if (ch == ('a' & 0x1F))		//  Original source, later modified in video
		if (ch == ctrl(a))			// Added later in video
		{
			mvprintw(0, 0, "Detected Ctrl + a");
		}
		else {
			mvprintw(0, 0, "                  ");
		};

	}

	endwin();
	return 0;
}
