/*
* Ncurses Tutorial 14.2 - Creating a MenuBar (part 2)
* 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <curses.h>
#include "menu1.h"

using namespace std;

int main(int argc, char** argv)
{
	// Start ncurses
	initscr();
	noecho();
	curs_set(0);

	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);


	WINDOW* win = newwin(yMax/2, xMax/2, yMax/4, xMax/4);
	box(win,0,0);

	Menu menus[4] = {
		Menu("Terminal", 't'),
		Menu("Edit", 'e'),
		Menu("Options", 'o'),
		Menu("View", 'v')
	};

	MenuBar menubar = MenuBar(win, menus, 4);
	menubar.draw();

	// Menubar/Menu: initializations
	
	char ch;
	while (ch = wgetch(win))
	{
		menubar.handleTrigger(ch);
		menubar.draw();
	}
	
	endwin();
	return 0;
}