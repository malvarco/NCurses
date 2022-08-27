
/*
My absolute personal version.
It highlights values with keyboard and mouse.
It exits when "Exit" option is chosen with both.
This is very different from original example.
*/

#include <curses.h>
#include <cstring>

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
void report_choice(int mouse_x, int mouse_y, int* p_choice);

int main()
{
    int c, choice = 0;
    WINDOW* menu_win;
    MEVENT event;

    int highlight = 1;

    bool whileflag = TRUE;

    // my fixes * Show highlit variable number
    char  highl_to_str[200];    // *

    /* Initialize curses */
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

    mousemask(ALL_MOUSE_EVENTS, NULL);
    while (whileflag) {
        c = wgetch(menu_win);
        switch (c)
        {
        case KEY_MOUSE:
            if (getmouse(&event) == OK)
            {
                mvprintw(23, 0, "Mouse event detected");

                {   // When the user clicks left mouse button
                    if (event.bstate & BUTTON1_CLICKED)
                    {
                        report_choice(event.x + 1, event.y + 1, &choice);
                        highlight = choice;
                        break;
                    }
                }
            }
        case KEY_UP:
            mvprintw(22, 0, "                  ");
            mvprintw(23, 0, "                       ");
            if (highlight == 1)
                highlight = n_choices;
            else
                --highlight;
            break;
        case KEY_DOWN:
            mvprintw(22, 0, "                  ");
            mvprintw(23, 0, "                       ");
            if (highlight == n_choices)
                highlight = 1;
            else
                ++highlight;
            break;
        case 10:
            mvprintw(22, 0, "                  ");
            mvprintw(23, 0, "                       ");
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
        //sprintf_s(highl_to_str, 200, "%d", highlight);
        sprintf(highl_to_str, "%d", highlight);
        mvprintw(24, 0, highl_to_str);
        //mvprintw(24, 0, highlight);
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

/* Report the choice according to mouse position */
void report_choice(int mouse_x, int mouse_y, int* p_choice)
{
    int i, j, choice;
    i = startx + 2;
    j = starty + 3;

    for (choice = 0; choice < n_choices; ++choice)
    {
        if (mouse_y == j + choice && mouse_x >= i && mouse_x <= i + strlen(choices[choice]))
        {
            *p_choice = choice + 1;
            break;

        }
    }
}
