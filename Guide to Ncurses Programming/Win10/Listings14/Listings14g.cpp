/*
* scr_dump() function performs what old timers refer to as a screen dump.
* The inelegant term dump simply means to transfer a chunk of data (often raw
* data) from one device to another.
* Listing 14-7: dump.c
*/

#include <curses.h>
#include <stdlib.h>
#include <time.h>

#define FILENAME "windump"

int main()
{
    // char word[7];        // Original source
    char word[8];           // Error fix
    int x, w, r;

   // srandom((unsigned)time(NULL));      /* seed randomizer ORIGINAL SOURCE */
    srand((unsigned)time(NULL));      /* fix seed randomizer */

    word[7] = '\0';
    initscr();

    /* Fill most of the screen with random 6-char words */
    for ( x = 0; x < 200; x++)
    {
        for (w = 0; w < 6; w++)
            //word[w] = (random() % 26) + 'a'; // Original source
            word[w] = (rand() % 26) + 'a';      // Fix source
        printw("%s\t", word);
    }
    addch('\n');
    addstr("Press Enter to write this screen to disk\n");
    refresh();
    getch();

    /* write the window to disk */
    r = scr_dump(FILENAME);
    if (r == ERR)
        addstr("Error writing window to disk\n");
    else
        addstr("File written; press Enter to quit\n");
    refresh();
    getch();

    endwin();
    return 0;
}