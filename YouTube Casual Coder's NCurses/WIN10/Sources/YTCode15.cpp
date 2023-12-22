/*
* Ncurses Tutorial 15 - Changing Attributes with chgat
*/

#include <curses.h>

using namespace std;

int main(int argc, char** argv)
{
	// Start ncurses
	initscr();
	if (has_colors() == FALSE)
	{
		return -1;
	}
	start_color();
	// Define 2 color_pairs
	init_pair(1, COLOR_WHITE, COLOR_BLUE);
	init_pair(2, COLOR_WHITE, COLOR_RED);

	//  int chgat(int n, attr_t attr, short color, const void *opts)
	// chgat, mvchgat, wchgat, mvwchgat

	// chgat(5, A_STANDOUT, 0, NULL);
	move(0, 5);
	// chgat(-1, A_STANDOUT, 0, NULL);
	printw("Hello");
	mvchgat(0, 5, 5, A_NORMAL, 1, NULL);
	
	getch();
	endwin();
	
	return 0;
}