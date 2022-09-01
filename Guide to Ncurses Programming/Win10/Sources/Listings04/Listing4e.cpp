// Listing 4-5 ctitle.c

#include <curses.h>
#include <string.h>

// void center(int row, char* title);       // Original source
void center(int row, const char* title);    // 'const' added

int main(void)
{
    initscr();
    
    center(1, "Penguin Soccer Finals");
    center(5, "Cattle Dung Samples from Temecula");
    center(7, "Catatonic Theater");
    center(9, "Why Do Ions Hate Each Other?");
    getch();

    endwin();
    return 0;
}

// void center(int row, char *title) // Original source
void center(int row, const char* title)   // 'const' added
{
    int len, indent, y, width;

    getmaxyx(stdscr, y, width);         /* get screen width */

    len    = strlen(title);         /* get title's length */
    indent = width - len;               /* substract it from screen width */
    indent /= 2;                        /* divide result into two */

    mvaddstr(row, indent, title);
    refresh();
};
