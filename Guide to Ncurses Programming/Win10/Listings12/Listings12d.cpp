/*
* When the program needs to change a label, simply reissue 
* slk_set() function for that label, along with the new text and adding 
* slk_refresh().
Listing 12-4: duck.c
*/

#include <curses.h>

#define LMAX   8
#define CENTER  1

int main()
{
    char label_text[LMAX][8] = { "Duck", "Duck", "Duck", "Duck",
        "Duck", "Duck", "Duck", "Duck" };

    int label;

    slk_init(1);
    initscr();

    for (label = 0; label < LMAX; label++)
        slk_set(label + 1, label_text[label], CENTER);
    slk_refresh();
    getch();

    // slk_set(7, "Goose!", CENTER);    // Original source
    slk_set(7, "", CENTER);             // Added later in book to show removing.
    slk_refresh();
    getch();

    endwin();
    return 0;
}

