/*
* Program reads that window back in from disk and displays it on the screen.
*Listing 14-10: DISKWIN.C
*/

#include <curses.h>
#include <stdlib.h>

#define FILENAME "window.dat"

// void bomb(char* message); // original source
void bomb(const char* message); // added 'const' to 'char *'

int main()
{
    FILE* wfile;
    WINDOW* win;
    int r;
    errno_t err;                                // added to fix insecure fopen()

    initscr();
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLUE);

    addstr("Press Enter to read the window from disk:\n");
    refresh();
    getch();
        
    /* open the file */
   // wfile = fopen(FILENAME, "r");         // original source
    err = fopen_s(&wfile, FILENAME, "r");   // fopen_s() instead of fopen()
    // if (wfile == NULL)                   // original source
    if (err != NULL)
        bomb("Error creating file\n");

    /* write the window's data */
    win = getwin(wfile);
    if (win == NULL)
        bomb("Unable to read/create window\n");
    fclose(wfile);
    wrefresh(win);
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