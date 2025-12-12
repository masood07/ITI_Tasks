#include <iostream>
#include <Windows.h>
#include "conio.h"
#define null -32
using namespace std;
void textattr(int i);
void gotoxy( int column, int line );

struct emp
{
    int id;
    char name[20];
    int salary;
};

int main()
{
    //line editor
    int cpe = 0;
    int idx = 0;
    char che;
    bool fl = 0;
    char str[50] = {0};

    system("cls");

    do
    {
        gotoxy(0, 0);
        for(int i = 0; i < idx; i++)
        {
            if(i == cpe)
                textattr(0x0F);
            else
                textattr(0x84);
            cout << str[i];
        }
        if(cpe == idx)
        {
            textattr(0x0F);
            cout << " ";
        }
        textattr(0x84);
        cout << "    ";

        che = getch();
        if(che == -32)  // extended
        {
            che = getch();
        }

        switch(che)
        {
            case 75:  // LEFT
                cpe--;
                if(cpe < 0)
                    cpe = 0;
                break;

            case 77:  // RIGHT
                cpe++;
                if(cpe > idx)
                    cpe = idx;
                break;

            case 80:  // DOWN
                if(cpe < idx && str[cpe] >= 'A' && str[cpe] <= 'Z')
                    str[cpe] += ('a' - 'A');
                break;

            case 72:  // UP  - to uppercase
                if(cpe < idx && str[cpe] >= 'a' && str[cpe] <= 'z')  // fixed!
                    str[cpe] -= ('a' - 'A');
                break;

            case 27:  // ESC
                system("cls");
                cout << "Good bye" << endl;
                fl = 1;
                break;

            default:  // regular characters
                if(che >= 32 && che <= 126)
                {
                    // Insert at cursor position
                    for(int i = idx; i > cpe; i--)
                        str[i] = str[i - 1];
                    str[cpe] = che;
                    idx++;
                    cpe++;
                }
                break;
        }

    } while(fl == 0);

    return 0;
}

void textattr(int i)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}

void gotoxy(int column, int line)
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
