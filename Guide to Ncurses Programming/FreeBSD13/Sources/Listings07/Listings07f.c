
/*
* Even so, the point is that turning text-echoing off and on is something
* programmers desire, as shown in Listing 7-6. NCurses is happy to oblige.
* Listing 7-6: whoru.c
*/

#include <curses.h>

int main(void)
{
    char name[46];
    char password[9];

    initscr();

    mvprintw(3, 10, "Enter your name: ");
    refresh();
    getnstr(name, 45);
    mvprintw(5, 6, "Enter your password: ");
    refresh();

    noecho(); // Turn display off not in original source
    getnstr(password, 8);

    endwin();
    return 0;
}
