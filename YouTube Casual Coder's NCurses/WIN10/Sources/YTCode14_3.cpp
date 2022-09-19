/*
* Ncurses Tutorial 14.3 - Creating a MenuBar (part 3)
* 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <curses.h>
#include "menu.h"

using namespace std;

int main(int argc, char** argv)
{
	// Start ncurses
	initscr();
	noecho();
	curs_set(0);

	// [4] Start color, and create a color pair
	if (!has_colors())
	{
		return -1;
	}
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLUE);

	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);

	WINDOW* win = newwin(yMax/2, xMax/2, yMax/4, xMax/4);
	box(win,0,0);

	// [5] Create some string arrays to act as "menu items"
	string menu1[] = { "New", "Open", "Save", "Exit" };
	string menu2[] = { "Copy", "Cut", "Paste" };
	string menu3[] = { "Sidebar", "Terminal" };
	Menu menus[3] = {
		Menu("File", 'f',menu1,4),
		Menu("Edit", 'e',menu2,3),
		Menu("View", 'v',menu3,2),
	};

	MenuBar menubar = MenuBar(win, menus, 3);
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