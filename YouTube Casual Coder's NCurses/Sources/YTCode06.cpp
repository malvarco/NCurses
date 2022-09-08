/*
* Ncurses Tutorial 6 - Working with User Input
* (Very much modified by me)
*/

#include <curses.h>
#include <string>

using namespace std;

void start_ncurses(bool useRaw, bool useNoecho);
void printMenu(WINDOW* menu, string choices[], int size, int highlight);

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
	WINDOW* inputwin = newwin(3, xMax - 12, yMax - 5, 5);
	box(inputwin, 0, 0);
	refresh();
	wrefresh(inputwin);

	keypad(inputwin, true);

	int c = wgetch(inputwin);
	switch (c)
	{
	case KEY_UP:
		mvwprintw(inputwin, 1, 1, "You pressed Up");
		break;
	case KEY_DOWN:
		mvwprintw(inputwin, 1, 1, "You pressed Down");
		break;
	case KEY_LEFT:
		mvwprintw(inputwin, 1, 1, "You pressed Left");
		break;
	case KEY_RIGHT:
		mvwprintw(inputwin, 1, 1, "You pressed Right");
		break;
	case 10:
		mvwprintw(inputwin, 1, 1, "You pressed Enter");
		break;
	default:
		mvwprintw(inputwin, 1, 1, "You pressed %c", c);
		break;
	}
	wrefresh(inputwin);
		
	// make sure program waits before exiting
	getch();
	endwin();
	/* NCURSES END*/
	return 0;
}