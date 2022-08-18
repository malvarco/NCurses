/*
*  prefresh() uses zero as a base.
* Listing 11-2: paddy1.c
*/

#include <curses.h>
#include <stdlib.h>

#define FILENAME "gettysburg.txt"
#define TALL 24
#define WIDE 19
#define SPACER 5

// void bomb(char* message); // Original source, needs 'const'
void bomb(const char* message);        // Added 'const' to 'char*'

int main()
{
    WINDOW* p;
    FILE *f;
    int ch;
    errno_t err;            // Added by me for fopen_s() compatibility

    initscr();

    /* create a new pad */
    p = newpad(200, WIDE + 1);
    if (p == NULL)
        bomb("Unable to create new pad\n");
    
    /* open the file */
   // f = fopen(FILENAME, "r");  // Original source, error in WIN10
    err = fopen_s(&f, FILENAME, "r");
    // if (f == NULL) // In original source, fopen() error in WIN10
    if (err != NULL)  // Added by me for fopen_s() compat.
        bomb("Unable to open file\n");

    /* display file's contents on the pad */
    while ((ch = fgetc(f)) != EOF)
        waddch(p, ch);
    fclose(f);

    /* display the pad's contents on the screen */
    prefresh(p, 0,      0, 0,                 0, TALL - 1, WIDE);
    prefresh(p, TALL,   0, 0,     WIDE + SPACER, TALL - 1, WIDE*2 + SPACER);
    prefresh(p, TALL*2, 0, 0, WIDE*2 + SPACER*2, TALL - 1, WIDE * 3 + SPACER*2);
    wgetch(p);
        
    endwin();
    return (0);
}

// void bomb(char* message) // Original source, needs 'const' for WIN10
void bomb(const char* message)      // Added 'const' to 'char*' for WIN10
{
    addstr(message);
    refresh();
    getch();
    endwin();
    exit(1);
}
