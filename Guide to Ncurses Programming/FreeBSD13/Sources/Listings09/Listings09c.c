
/*
*  A subwindow is considered a real window in nearly every sense, it’s
* possible for a subwindow to have a subwindow of its own. You simply
* name the subwindow’s variable as the win in the subwin() function.
* Listing 9-3: kid3.c
*/

#include <curses.h>

int main(void)
{
    WINDOW* grandpa,* father, * boy;
    int maxx, maxy;

    initscr();

    start_color();                      /* remember to check for errors! */
    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    init_pair(2, COLOR_RED, COLOR_YELLOW);
    init_pair(3, COLOR_CYAN, COLOR_GREEN);

    getmaxyx(stdscr, maxy, maxx);

    /* create windows - remeber to check for errors! */
    grandpa = newwin(maxy - 4, maxx - 10, 2, 5);
    father = subwin(grandpa, maxy - 8, maxx - 20, 4, 10);
    boy = subwin(father, maxy - 16, maxx - 40, 8, 20);

    /* color windows and splash some text */
    wbkgd(grandpa, COLOR_PAIR(1));
    waddstr(grandpa, "Granpa");
    wbkgd(father, COLOR_PAIR(2));
    waddstr(father, "Father");
    wbkgd(boy, COLOR_PAIR(3));
    waddstr(boy, "Boy");
    wrefresh(grandpa);
    getch();

    endwin();
    return 0;
}
