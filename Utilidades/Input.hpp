#ifndef INPUT_HPP
#define INPUT_HPP

#include <string>
#include <curses.h>

std::string inputTecladoStr()
{
    cbreak();
    noecho(); 
    char buffer[100];
    int ch = 0, i = 0;
    while ((ch = getch()) != '\n') 
    {
        if (ch == KEY_BACKSPACE || ch == 127) 
        {
            if (i > 0) {
                buffer[--i] = '\0'; 
                printw("\b \b");
                refresh();
            }
        } 
        else if (i < 100 - 1) 
        {
            buffer[i++] = (char) ch;
            printw("%c", ch);
            refresh();
        }
    }
    buffer[i] = '\0';
    return std::string(buffer);
}

int inputTecladoInt()
{
    cbreak();
    noecho(); 
    char buffer[100];
    int ch = 0, i = 0;
    while ((ch = getch()) != '\n') 
    {
        if (ch == KEY_BACKSPACE || ch == 127) 
        {
            if (i > 0) {
                buffer[--i] = '\0'; 
                printw("\b \b");
                refresh();
            }
        } 
        else if (i < 100 - 1 && (ch >= 48 && ch <= 57)) 
        {
            buffer[i++] = (char) ch;
            printw("%c", ch);
            refresh();
        }
    }
    buffer[i] = '\0';
    return atoi(buffer);
}

#endif // !INPUT_HPP