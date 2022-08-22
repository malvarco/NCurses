/*
* Listing 14-9: windisk.c
*/

#include <curses.h>
#include <stdlib.h>

#define FILENAME "window.dat"

// void bomb(char* message); // original source
 void bomb( const char* message); // added 'const' to 'char *'


int main()
{
    FILE* wfile;
    WINDOW* win;
    int r;
    errno_t err;                                // added to fix insecure fopen()

    initscr();
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLUE);

    addstr("Creating new window\n");
    refresh();

    /* Create the window */
    win = newwin(5, 20, 7, 30);
    if (win == NULL)
        bomb("Unable to create window\n");
    wbkgd(win, COLOR_PAIR(1));
    mvwaddstr(win, 1, 2, "This program was \n");
    mvwaddstr(win, 2, 5, "created by\n");
    mvwaddstr(win, 3, 5, "Dan Gookin\n");           /* put your name here */
    wrefresh(win);
    getch();

    /* open the file */
   // wfile = fopen(FILENAME, "w");         // original source
    err = fopen_s(&wfile, FILENAME, "w");   // fopen_s() instead of fopen()

    // if (wfile == NULL)                   // original source
    if (err != NULL)
        bomb("Error creating file\n");

    /* write the window's data */
    r = putwin(win, wfile);
    if (r == ERR)
        addstr("Error putting window to disk\n");
    else
        addstr("Window put to disk\n");
    fclose(wfile);
    refresh();
    getch();

    endwin();
    return 0;
}

// void bomb(char* message)             // original source
void bomb(const char* message)          // added 'const'
{
    addstr(message);
    refresh();
    getch();
    endwin();
    exit(1);
}