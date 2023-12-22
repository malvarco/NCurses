
/*
* NCurses doesn’t scroll a window by default.
* Listing 10-4: scroller.c
*/

#include <curses.h>


#define FILENAME "gettysburg.txt"

int main()
{
    FILE* text;
    WINDOW* lister;
    int maxy, maxx, ch;
    int timer;              // Added by me, not in original

    initscr();
    getmaxyx(stdscr, maxy, maxx);

    /* create window lister */
    lister = newwin(maxy, maxx / 2, 0, maxx / 4);
    if (lister == NULL)
    {
        addstr("unable to create window\n");
        refresh();
        getch();
        endwin();
        return(1);
    }

    scrollok(lister, TRUE);         /* Not in original. Added later in book as example. */

    /* open the file */
     text = fopen(FILENAME, "r");


    if (text == NULL)  // Original source

    {
        addstr("unable to open file\n");
        refresh();
        getch();
        endwin();
        return(2);
    }

    /* display the file's contents */
    timer = 0;      // Added by me not in original
    do
    {
        ch = fgetc(text);
        waddch(lister, ch);
        wrefresh(lister);
        if((timer % 30) == 0) napms(50); // Added pause by me, not in original
        timer++;                        // Added pause by me, not in original
    } while (ch != EOF);
    fclose(text);
    // getch(); // Commented by me, not commented in original

    endwin();
    return 0;
}
