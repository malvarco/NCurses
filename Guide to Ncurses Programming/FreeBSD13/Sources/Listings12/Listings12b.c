
/*
* the index line is protected from being overwritten and the
* standard screen size is decreased by one line accordingly.
* Listing 12-2: softies2.c
*/

#include <curses.h>

#define LMAX   12
#define CENTER  1

int main()
{
    // char label_text[LMAX][6] = {"Help", "File", "Edit", "Frmt", // Original source produces error
     char label_text[LMAX][7] = { "Help", "File", "Edit", "Frmt",  // Changed 6 to 7 solved error
        "Find", "Block", "Ins", "Del", "View", "Switch", "Win", "Help" };
    int label;

    slk_init(3);
    initscr();

    slk_restore();          // Added later in book as example

    for (label = 0; label < LMAX; label++)
        slk_set(label + 1, label_text[label], CENTER);
    slk_refresh();

    getch();

    endwin();
    return 0;
}

