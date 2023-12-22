/*
* Example 3
* Simple printw 
*/

#include <curses.h>			/* ncurses.h includes stdio.h */
#include <string.h>

int main()
{
	char mesg[] = "Just a string";			/* message to be appeared on the screen */
	int row, col;							/* to store the number of rows and */

	initscr();						/* start curses mode */
	getmaxyx(stdscr, row, col);		/* get the number of rows and columns */
	mvprintw(row / 2, (col - strlen(mesg)) / 2, "%s", mesg);
									/* print the message at the center of the screen */
	mvprintw(row - 2, 0, "This screen has %d rows and %d columns\n", row, col);
	printw("Try resizing your window (if possible) and then run this program again");
	refresh();
	getch();
	endwin();

	return 0;
}