
/*
* Ncurses Tutorial 11 - Storing Attribute Data (attr_t & chtype)
*/

#include <stdlib.h>
#include <curses.h>

using namespace std;

int main(int argc, char** argv)
{
	// Start ncurses
	initscr();
	if (has_colors() == FALSE) { endwin(); printf("Color can't be used."); exit; }
	start_color();

	// Define 2 color_pairs
	init_pair(1, COLOR_YELLOW, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);

	attr_t emphasis = A_REVERSE | COLOR_PAIR(2);
	attron(emphasis);
	mvaddch(5, 5, 'a');
	mvaddch(5, 6, 'b');
	mvaddch(5, 7, 'c');
	attroff(emphasis);

	attron(A_REVERSE | COLOR_PAIR(2));
	mvaddch(7, 5, 'a');
	mvaddch(7, 6, 'b');
	mvaddch(7, 7, 'c');
	attroff(A_REVERSE | COLOR_PAIR(2));

	chtype c = '@' | A_REVERSE | COLOR_PAIR(1); // chtype int specifically for storing attribs

	mvaddch(9, 5, c);

	//wait for input, then exit
	getch();
	endwin();

	return 0;
}
