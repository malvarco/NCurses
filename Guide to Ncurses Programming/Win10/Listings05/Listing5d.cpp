// Listing 5.4 marquee1.c

#include <curses.h>
#include <string.h>

int main(void)
{
    char text[] = "Stock Market Swells! DOW tops 15,000!";
    char* t;
    int len;

    initscr();

    len = strlen(text);
    t = text;               /* initialize pointer */
    while (len)
    {
        move(5, 5);                 /* always insert at the same spot */
        insch(*(t + len - 1));      /* work through string backwards */
        refresh();
        napms(100);                 /* .1 sec delay */
        len--;
    }
    getch();

    endwin();
    return 0;
}
