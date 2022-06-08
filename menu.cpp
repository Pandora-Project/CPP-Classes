#include <ncurses.h>
#include <string>
#include <bits/stdc++.h>
#include "kantor.cpp"
using namespace std;

json exchange_rate(string base, string symbols);
json exchange(string amount, string from_curr, string symbols);
json fluctuation(string start_date, string end_date, string base, string symbols);
json date_rate(string date, string base, string symbols = "");
string getstring();

string convertToString(char *a)
// converts char* to string
{
    string s(a);

    return s;
}

WINDOW *create_inputwin(int yMax, int xMax)
//creates input window, usefull after clearing screen
{
    WINDOW *inputwin = newwin(3, xMax - 10, yMax - 3, 5);
    box(inputwin, 0, 0);
    refresh();
    wrefresh(inputwin);
    return inputwin;
}

WINDOW *create_menuwin(int yMax, int xMax)
//creates menu window, usefull after clearing screen
{
    WINDOW *menuwin = newwin(7, xMax - 10, yMax - 10, 5);
    box(menuwin, 0, 0);
    refresh();
    wrefresh(menuwin);
    return menuwin;
}

void exchange_window(WINDOW *inputwin, int yMax, int xMax)
//handels user input when exchange option is chosen
{
    char amount[64], base_cur[3], symbols[3];
    string amount_s, base_cur_s, symbols_s;
    for (int i = 0; i < 3; i++)
    {
        echo();
        refresh();
        move(yMax - 3, 5);
        clrtobot();
        create_inputwin(yMax, xMax);
        wrefresh(inputwin);
        switch (i)
        {
        case 0:
            mvwprintw(inputwin, 0, 1, "Amount of currency: XXXXXXXXX");
            refresh();
            mvwgetnstr(inputwin, 1, 1, amount, sizeof amount);
            amount_s = convertToString(amount);
            mvprintw(0, 5, "Amount of currency: %s", amount);
            break;
        case 1:
            mvwprintw(inputwin, 0, 1, "Base currency: XXX");
            refresh();
            mvwgetnstr(inputwin, 1, 1, base_cur, sizeof base_cur);
            base_cur_s = convertToString(base_cur);
            mvprintw(1, 5, "Base currency: %s", base_cur);
            break;
        case 2:
            mvwprintw(inputwin, 0, 1, "Enter target currency: XXX");
            refresh();
            mvwgetnstr(inputwin, 1, 1, symbols, sizeof symbols);
            symbols_s = convertToString(symbols);
            mvprintw(2, 5, "Other currencies: %s", symbols);
            break;
        default:
            break;
        }
    }

    //print result dict
    move(4, 5);
    json arr = exchange(amount_s, base_cur_s, symbols_s);
    string rates = arr.dump();
    printw(rates.c_str());
    //wait for user input then turn off echo and refresh screen
    getch();
    noecho();
    refresh();
}

void exchange_rate_window(WINDOW *inputwin, int yMax, int xMax)
{
    char base[10], symbols[11];
    string base_s, symbols_s;
    for (int i = 0; i < 2; i++)
    {
        echo();
        refresh();
        move(yMax - 3, 5);
        clrtobot();
        create_inputwin(yMax, xMax);
        wrefresh(inputwin);
        switch (i)
        {
        case 0:
            mvwprintw(inputwin, 0, 1, "Enter base currency: XXX");
            refresh();
            mvwgetnstr(inputwin, 1, 1, base, sizeof base);
            base_s = convertToString(base);
            mvprintw(0, 5, "Base currency: %s", base);
            break;
        case 1:
            mvwprintw(inputwin, 0, 1, "Enter other currencies: XXX,XXX");
            refresh();
            mvwgetnstr(inputwin, 1, 1, symbols, sizeof symbols);
            symbols_s = convertToString(symbols);
            mvprintw(1, 5, "Other currencies: %s", symbols);
            break;
        default:
            break;
        }
    }
    move(4, 5);
    json arr = exchange_rate(base_s, symbols_s);
    string rates = arr.dump();
    printw(rates.c_str());
    getch();
    noecho();
    refresh();
}

void fluctuation_window(WINDOW *inputwin, int yMax, int xMax)
{
    char start_date[10], end_date[10], base[3], symbols[11];
    string start_date_s, end_date_s, base_s, symbols_s;

    for (int i = 0; i < 4; i++)
    {
        echo();
        refresh();
        move(yMax - 3, 5);
        clrtobot();

        create_inputwin(yMax, xMax);
        wrefresh(inputwin);
        switch (i)
        {
        case 0:
            mvwprintw(inputwin, 0, 1, "Enter start date: yyyy-mm-dd");
            refresh();
            mvwgetnstr(inputwin, 1, 1, start_date, sizeof start_date);
            start_date_s = convertToString(start_date);
            mvprintw(0, 5, "Start date: %s", start_date);
            break;
        case 1:
            mvwprintw(inputwin, 0, 1, "Enter end date: yyyy-mm-dd");
            refresh();
            mvwgetnstr(inputwin, 1, 1, end_date, sizeof end_date);
            end_date_s = convertToString(end_date);
            mvprintw(1, 5, "End date: %s", end_date);
            break;
        case 2:
            mvwprintw(inputwin, 0, 1, "Enter base currency: XXX");
            refresh();
            mvwgetnstr(inputwin, 1, 1, base, sizeof base);
            base_s = convertToString(base);
            mvprintw(2, 5, "Base currency: %s", base);
            break;
        case 3:
            mvwprintw(inputwin, 0, 1, "Enter other currencies: XXX,XXX,XXX");
            refresh();
            mvwgetnstr(inputwin, 1, 1, symbols, sizeof symbols);
            symbols_s = convertToString(symbols);
            mvprintw(3, 5, "Other currencies: %s", symbols);
            break;
        default:
            break;
        }
        refresh();
    }
    move(4, 5);
    json arr = fluctuation(start_date_s, end_date_s, base_s, symbols_s);
    string rates = arr.dump();
    printw(rates.c_str());
    getch();
    noecho();
    refresh();
}

void date_rate_window(WINDOW *inputwin, int yMax, int xMax)
{
    char date[10], base[3], symbols[11];
    string date_s, base_s, symbols_s;

    for (int i = 0; i < 3; i++)
    {
        echo();
        refresh();
        move(yMax - 3, 5);
        clrtobot();

        create_inputwin(yMax, xMax);
        wrefresh(inputwin);
        switch (i)
        {
        case 0:
            mvwprintw(inputwin, 0, 1, "Enter date: yyyy-mm-dd");
            refresh();
            mvwgetnstr(inputwin, 1, 1, date, sizeof date);
            date_s = convertToString(date);
            mvprintw(0, 5, "Start date: %s", date);
            break;
        case 1:
            mvwprintw(inputwin, 0, 1, "Enter base currency: XXX");
            refresh();
            mvwgetnstr(inputwin, 1, 1, base, sizeof base);
            base_s = convertToString(base);
            mvprintw(1, 5, "End date: %s", base);
            break;

        case 2:
            mvwprintw(inputwin, 0, 1, "Enter target currency: XXX");
            refresh();
            mvwgetnstr(inputwin, 1, 1, symbols, sizeof symbols);
            symbols_s = convertToString(symbols);
            mvprintw(2, 5, "Base currency: %s", symbols);
            break;

        default:
            break;
        }
        refresh();
    }
    move(4, 5);
    json arr = date_rate(date_s, base_s, symbols_s);
    string rates = arr.dump();
    printw(rates.c_str());
    getch();
    noecho();
    refresh();
}

int main(int argc, char **argv)
{
    // Ncurses start
    initscr();
    noecho();
    cbreak();

    // Screen size
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

//Label for menu recursion, program quits whe
Menu:
    erase();
    WINDOW *menuwin = create_menuwin(yMax, xMax);
    WINDOW *inputwin = create_inputwin(yMax, xMax);

    // keypad init
    keypad(menuwin, true);
    string choices[5] = {"Exchange rate", "Exchange", "Fluctuation", "Date rate", "Quit"};
    int choice;
    int highlight = 0;
    while (1)
    {
        for (int i = 0; i < 6; i++)
        {
            if (i == highlight)
                wattron(menuwin, A_REVERSE);
            mvwprintw(menuwin, i + 1, 1, choices[i].c_str());
            wattroff(menuwin, A_REVERSE);
        }
        choice = wgetch(menuwin);

        switch (choice)
        {
        case KEY_UP:
            highlight--;
            if (highlight == -1)
                highlight = 0;
            break;
        case KEY_DOWN:
            highlight++;
            if (highlight == 5)
                highlight = 4;
            break;
        default:
            break;
        }
        if (choice == 10)
            break;
    }

    switch (highlight)
    {
    case 0:
        exchange_rate_window(inputwin, yMax, xMax);
        break;
    case 1:
        exchange_window(inputwin, yMax, xMax);
        break;
    case 2:
        fluctuation_window(inputwin, yMax, xMax);
        break;
    case 3:
        date_rate_window(inputwin, yMax, xMax);
        break;
    case 4:
        endwin();
        return 0;
    default:
        break;
    }
    //going back to first menu page after sucessfull operation
    goto Menu;
}