/*
* Ncurses Tutorial 8 - Basic Top-Down Player Movement
*/

#include <curses.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include "player.h"

using namespace std;

int main(int argc, char** argv)
{
	/* NCURSES START */
	initscr();
	noecho();
	cbreak();

	// get screen size
	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);

	// Create a window for out input
	WINDOW* playwin = newwin(20, 50, (yMax/2)-10, 10);
	box(playwin, 0, 0);
	refresh();
	wrefresh(playwin);

	Player* p = new Player(playwin, 1, 1, '@');
	do {
		p->display();
		wrefresh(playwin);
	} while (p->getmv() != 'x');

	// make sure program waits before exiting
	getch();
	endwin();
	/* NCURSES END*/
	return 0;
}