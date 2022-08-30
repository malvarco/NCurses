/*
* YTCode02.cpp : Basics of Windows (WINDOW*, newwing, box, refresh, wrefresh, wprintw mvwprintw)
*/

#include <curses.h>
using namespace std;

int main(int argc, char* argv[])
{
    // Initialize the Screen
    // Set up memory and clear the Screen
    initscr();
    int height, width, start_y, start_x;
    height = 10;
    width = 20;
    start_y = start_x = 10;
    WINDOW* win = newwin(height, width, start_y, start_x);
    refresh();

    box(win, 0, 0);
    // wprintw(win, "This is my box");
    mvwprintw(win, 1, 1, "This is my box");

    wrefresh(win);
    // Wait for user input, returns int value of the key 
    int c = getch();
    
    endwin();
    // Deallocates memory and ends NCurses 

    return 0;
}
