
/*
* Ncurses Tutorial 9 - Refreshing: "When" and "Why"
*/

#include <curses.h>


using namespace std;

int main(int argc, char** argv)
{
	// Initializes ncurses
	initscr();

	WINDOW* win = newwin(10, 30, 0, 0);
	box(win, 0, 0);
	refresh();		// refresh screen, but not window
	// wrefresh(win);	// refresh window demo

	wgetch(win);			// refresh window demo, makes wrefresh redundant
	getch();

	getch();
	endwin();

	// End ncurses

	return 0;
}
