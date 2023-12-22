
/*
* Ncurses Tutorial 16 - Clear Routines (clrtoeol, clrtobot, erase, clear)
*/

#include <curses.h>

using namespace std;

int main(int argc, char** argv)
{
	// Start ncurses
	initscr();
	noecho();
	// I like to refresh stdsct at the start
	// tends to fix some unexpected display side effects
	refresh();

	/*** Tutorial Code ***/
	printw("Hello world!");
	mvprintw(1, 0, "Hello world!");
	move(0, 1);
	getch();
	clrtoeol();		// wclrtoeol(WINDOW *);
	getch();

	mvprintw(2, 0, "Everything below this should get cleared");
	mvprintw(3, 0, "Everything below this should get cleared");
	mvprintw(6, 0, "Everything below this should get cleared");
	mvprintw(10, 0, "Everything below this should get cleared");
	move(2, 5);
	getch();
	clrtobot();		// wclrtobot(WINDOW *);
	getch();

	printw("Hello world");
	mvprintw(5, 5, "Hello world");
	mvprintw(10, 30, "Hello world");
	getch();
	erase();		// werase(WINDOW *);
	getch();

	clear();		// wclear(WINDOW *);

	// Make sure to pause before exiting
	getch();
	endwin();

	return 0;
}
