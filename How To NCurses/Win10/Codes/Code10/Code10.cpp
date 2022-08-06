/*
My version with some serious changes.
It shows highlight values all the time and final choice.
It exits when "Exit" option is chosen.
This is very different from original example.
*/

#include <stdio.h>
#include <curses.h>

#define WIDTH 30
#define HEIGHT 10

int startx = 0;
int starty = 0;




const char* choices[] = {                       /* Added 'const' to 'char* choices' to stop Visual Studio complaints */
                        "Choice 1",
                        "Choice 2",
                        "Choice 3",
                        "Choice 4",
                        "Exit",
};
int n_choices = sizeof(choices) / sizeof(char*);
void print_menu(WINDOW* menu_win, int highlight);

int main()
{
    WINDOW* menu_win;
    int highlight = 1;
    int choice = 0;
    int c;
    bool whileflag = TRUE;

    // my fixes * Show highlit variable number
    char  highl_to_str[200];    // *





    initscr();
    clear();
    noecho();
    cbreak();               /* Line buffering disabled. pass on everything */
    startx = (80 - WIDTH) / 2;
    starty = (24 - HEIGHT) / 2;

    menu_win = newwin(HEIGHT, WIDTH, starty, startx);
    keypad(menu_win, TRUE);
    mvprintw(0, 0, "Use arrow keys to go up and down, Press enter to select a choice");
    refresh();
    print_menu(menu_win, highlight);
    while (whileflag) {
        c = wgetch(menu_win);
        switch (c) {
        case KEY_UP:
            if (highlight == 1)
                highlight = n_choices;
            else
                --highlight;
            break;
        case KEY_DOWN:
            if (highlight == n_choices)
                highlight = 1;
            else
                ++highlight;
            break;
        case 10:
            choice = highlight;
            break;
        default:
            mvprintw(24, 0, "Character pressed is = %3d Hopefully it can be printed as %c", c, c);
            refresh();
            break;
        }
        print_menu(menu_win, highlight);
        if (choice == 5) /* User did a choice come out of the inifinite loop */
        {
            whileflag = FALSE;
            break;
        }

        if (choice > 0) {
            mvprintw(23, 0, "You chose choice %d with choice string %s\n", choice, choices[choice - 1]);
        }

        // Format and print various data:
        sprintf_s(highl_to_str, 200, "%d", highlight);
        mvprintw(24, 0, highl_to_str);
        clrtoeol();
        refresh();
    }
    endwin();
    return 0;
}

void print_menu(WINDOW* menu_win, int highlight)
{
    int x, y, i;
    x = 2;
    y = 2;
    box(menu_win, 0, 0);
    for (int i = 0; i < n_choices; ++i) {
        if (highlight == i + 1) /* High light the present choice */
        {
            wattron(menu_win, A_REVERSE);
            mvwprintw(menu_win, y, x, "%s", choices[i]);
            wattroff(menu_win, A_REVERSE);
        }
        else
            mvwprintw(menu_win, y, x, "%s", choices[i]);
        ++y;
    }
    wrefresh(menu_win);
}


