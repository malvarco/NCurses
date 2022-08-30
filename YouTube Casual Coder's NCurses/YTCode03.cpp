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
   
    // cbreak();    // Commented out to show raw() below
    raw();
    noecho();

    int height, width, start_y, start_x;
    height = 10;
    width = 20;
    start_y = start_x = 10;
    WINDOW* win = newwin(height, width, start_y, start_x);
    refresh();

    // box(win, 0, 0);      // Line border commented out to show below
    char c = 'g';           // Workaround to Ascii codes
    box(win, (int) c, 103);       // Terrible border of g's and h's

    int left, right, top, bottom, tlc, trc, blc, brc;
    left = right = 103;
    top = bottom = 104;
    c = '+';
    tlc = trc = blc = brc = (int) c;

    wborder(win, left, right, top, bottom, tlc, trc, blc, brc);
    // wprintw(win, "This is my box");
    mvwprintw(win,1, 1, "This is my box");

    wrefresh(win);
    // Wait for user input, returns int value of the key 
    getch();
    getch();

    endwin();
    // Deallocates memory and ends NCurses 

    return 0;
}
