/*
* Ncurses Tutorial 12.2 Practical example - 'chtype' (In-depth), & Extracting Attributes/Colors
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <curses.h>
#include <iostream>
#include <string>
#include <bitset>

#define A_ATTRS (A_ATTRIBUTES ^ A_COLOR)

void setupColorPairs() {
	// srand(time(NULL));		// Original source
	srand((unsigned) time(NULL));
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_CYAN, COLOR_BLACK);
	init_pair(7, COLOR_WHITE, COLOR_BLACK);
}

attr_t getRandomColor(int max_color_index) {
	int color_pair_index = rand() % max_color_index * 1;
	attr_t random_color = COLOR_PAIR(color_pair_index);
	return random_color;
}

using namespace std;

int main(int argc, char** argv)
{
	// Start ncurses
	initscr();
	noecho();
	curs_set(0);

	// Start and configure color pairs
	if (has_colors() == FALSE) {
		endwin();
		printf("Color can't be used.");
		return -1;
	}
	start_color();
	setupColorPairs();

	// Create our windows and make stdscr aware of this
	WINDOW* output_win = newwin(1, 1, 5, 5);
	WINDOW* status_win = newwin(1, 50, 0, 0);
	refresh();
	wrefresh(output_win);
	wrefresh(status_win);

	// Declares some variables that need to be kept between loops
	bool reverse_on = false;
	char input = ' ';

	while (input != 'x')
	{
		// Display a random color every interaction
		// mvwaddch(output_win, 0, 0, '@' | getRandomColor(7));
		mvwaddch(output_win, 0, 0, '@' | getRandomColor(7) | A_UNDERLINE);
	
		// Holds our "status" message
		string status = "";

		// Refresh output_wint without outputting
		wnoutrefresh(output_win);

		// Capture the characater from the screen (redundant on purpose)
		chtype ch = mvwinch(output_win, 0, 0);

		// Code to detect specific color
		attr_t color = ch & A_COLOR;
		if (color == COLOR_PAIR(4))
			status = "Found color pair 4";
		// End

		// Code to detect specific attribute
		attr_t reversed = ch & A_ATTRS;

		/*
		if (reversed == A_REVERSE)
			status += " [ REVERSE]";
		*/
		if (reversed == (A_REVERSE | A_UNDERLINE))
			status += " [ REVERSE AND UNDERLINE]";
		// End
		
		// Erase any previous message and display new message
		werase(status_win);
		mvwprintw(status_win, 0, 1, status.c_str());
		// Refresh status_win without outputting
		wnoutrefresh(status_win);

		// Update and display all windows
		doupdate();

		// Wait for input before continuing
		input = tolower(getch());

		// If user pressed 'r', apply the reverse attribute on the next input
		if (input == 'r') {
			if (reverse_on) {
				wattrset(output_win, A_NORMAL);
				reverse_on = false;
			} else {
				wattrset(output_win, A_REVERSE);
				reverse_on = true;
			}
			}
		}

	endwin();
	return 0;
}