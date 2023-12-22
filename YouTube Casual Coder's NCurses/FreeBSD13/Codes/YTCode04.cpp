
/*
* YTCode04.cpp : Basics of Windows (WINDOW*, newwing, box, refresh, wrefresh, wprintw mvwprintw)
*/

#include <curses.h>

int main(int argc, char** argv)
{
	/* NCURSES START */
	// start_ncurses(true, true);		// Original source
	initscr();							// Added by me


	/*
	* A_NORMAL
	* A_STANDOUT
	* A_REVERSE
	* A_BLINK
	* A_DIM
	* A_BOLD
	* A_PROTECT
	* A_INVIS
	* A_ALTCHARSET
	* A_CHARTEXT
	*/

	/* All this block below added by me */
//	attron(A_NORMAL);
//	attron(A_STANDOUT);
//	attron(A_REVERSE);
//	attron(A_BLINK);
//	attron(A_DIM);
//	attron(A_BOLD);
//	attron(A_PROTECT);
//	attron(A_INVIS);
//	attron(A_ALTCHARSET);
//	attron(A_CHARTEXT);

	if (!has_colors())
	{
		printw("Terminal does not support color");
		getch();
		return -1;
	}
	start_color();

	init_pair(1, COLOR_CYAN, COLOR_WHITE);

	if (can_change_color())
	{
		printw("It can change color\n");
		init_color(COLOR_WHITE, 225, 233, 220);
	}

	attron(COLOR_PAIR(1));

	printw("This is some text");

	attroff(COLOR_PAIR(1));

	/* All this block below added by me */
//	attroff(A_NORMAL);
	attroff(A_STANDOUT);
//	attroff(A_REVERSE);
//	attroff(A_BLINK);
//	attroff(A_DIM);
//	attroff(A_BOLD);
//	attroff(A_PROTECT);
//	attroff(A_INVIS);
//	attroff(A_ALTCHARSET);
//	attroff(A_CHARTEXT);

	/*
	* COLOR_PAIR(n)
	* COLOR_BLACK	0
	* COLOR_RED		1
	* COLOR_GREEN	2
	* COLOR_YELLOW	3
	* COLOR_BLUE	4
	* COLOR_MAGENTA 5
	* COLOR_CYAN	6
	* COLOR_WHITE	7
	*/
	getch();

	endwin();

}
