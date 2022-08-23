
/*
* The curs_set() function is how NCursers controls the cursor. The value
* of n can be 0, 2, or 2:
* 0 makes the cursor invisible
* 1 sets the cursor to normal mode
* 2 sets the cursor to a very visible mode
* Listing 14-1: cursset.c
*/

#include <curses.h>

int main()
{
    initscr();

    /* first, turn the cursor off */
    curs_set(0);
    addstr(" <- The cursor has been turned off");
    move(0, 0);
    refresh();
    getch();

    /* second, turn the cursor on */
    curs_set(1);
    addstr("\n <- The cursor now on");
    move(1, 0);
    refresh();
    getch();

    /* third, turn the cursor very on */
    curs_set(2);
    addstr("\n <- The cursor is now very on");
    move(2, 0);
    refresh();
    getch();

    endwin();
    return 0;
}
