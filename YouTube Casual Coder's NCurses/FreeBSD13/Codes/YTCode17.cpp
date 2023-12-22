
/*
* Ncurses Tutorial 17 - Output/Refresh Options - clearok, scrollok, leaveok, immedok (curs_outopts)
*/

#include <curses.h>

using namespace std;

int main(int argc, char** argv)
{
	// Start ncurses
	initscr();
	noecho();
	refresh();

	// idlok(WINDOW *, bool);
	// idcok(WINDOW *, bool);

	// clearok(WINDOW *, bool);
	// immedok(WINDOW *, bool);
	// leaveok(WINDOW *, bool);
	// scrollok(WINDOW *, bool);

	WINDOW* win = newwin(5, 8, 10, 10);
	box(win, 0, 0);

	/*
	leaveok(win, true);
	wmove(win, 1, 2);
	wgetch(win);
	*/

	/*
	immedok(win, true);
	waddch(win, 'a');
	*/

	scrollok(win,true);
	int counter = 0;
	while (true)
	{
		chtype ch = (counter % 10) + '0';
		waddch(win, ch);
		wrefresh(win);
		counter++;
	}


	// clearok(win, true);

	// Make sure to pause before exiting
	getch();
	endwin();

	return 0;
}
