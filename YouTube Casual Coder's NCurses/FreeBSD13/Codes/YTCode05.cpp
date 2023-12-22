
/*
* Ncurses Tutorial 5 - Getting Information about the Terminal
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

	int y, x, yBeg, xBeg, yMax, xMax;

	WINDOW* win = newwin(10, 20, 10, 10);

	getyx(stdscr, y, x);
	getbegyx(stdscr,yBeg, xBeg);
	getmaxyx(stdscr,yMax,xMax);

	printw("getyx y = %d\n", y);
	printw("getyx x = % d\n", x);
	printw("getbegyx yBeg = % d\n", yBeg);
	printw("getbegyx xBeg = % d\n", xBeg);
	printw("getbegyx yMax = % d\n", yMax);
	printw("getbegyx xMax = % d\n", xMax);

	mvprintw(yMax / 2, xMax / 2, "hello");
	getbegyx(win, yBeg, xBeg);

	printw("\ngetbegyx window win yBeg = % d\n", yBeg);
	printw("getbegyx window win xBeg = % d\n", xBeg);

	// make sure program waits before exiting
	getch();
	endwin();
	/* NCURSES END*/
	return 0;
}
