/* Pager functionality by Joseph Spinhour */
#include <curses.h>
#include <stdlib.h>


int main(int argc, char* argv[])
{
	int ch, prev, row, col;
	prev = EOF;

	FILE* fp;
	int y, x;
	errno_t err;

	
	if (argc != 2)
	{
		printf("Usage: %s <a c file name>\n", argv[0]);
		exit(1);
	}

	// fp = fopen(argv[1], "r"); /* Original C source MS VS complains FOPEN insecure use FOPEN_S instead
	err = fopen_s(&fp, argv[1], "r");
		
	if (err != NULL)
	{
		perror("Cannot open input file");
		exit(1);
	}
	
	
	
	initscr();									/* Start curses*/
	getmaxyx(stdscr, row, col);					/* Get boundaries xy */
	while ((ch = fgetc(fp)) != EOF)				/* read the file till EOF */
		{
		getyx(stdscr, y, x);					/* Get current cursor position */
		if (y == (row - 1))						/* Are we at the end of the screen */
		{
			printw("<-Press Any Key->");
			getch();
			clear();							/* Clearscreen */
			move(0, 0);							/* Start at the beginning of screen */
		}

		if (prev == '/' && ch == '*')			/* If it is / and * then only switch bold on */
		{
			attron(A_BOLD);						/* Cut bold on*/
			getyx(stdscr, y, x);				/* get current cursor position*/
			move(y, x - 1);						/* back one space*/
			printw("%c%c", '/', ch);			/* Actual printing */
		}
		else
			printw("%c", ch);
		refresh();
		if (prev == '*' && ch == '/')
			attroff(A_BOLD);					/* Switch it off once we got * and then/ */

		prev = ch;

		}
	endwin();                                   /* End curses mode */
	fclose(fp);
	return 0;
}



