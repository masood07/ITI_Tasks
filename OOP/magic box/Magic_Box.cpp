#include <iostream>
#include <windows.h>
#include "math.h"
using namespace std;

void gotoxy(int column, int line)
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE),
        coord
    );
}

void Magic_Box(int size)
{
    system("cls");
    int col=ceil(size/2.0), row=0;
    gotoxy(col*4, row);
    cout<<1;

    for(int i=2; i<=size*size; i++){
        if((i-1)%size!=0)
        {
            if(col-1<0)
                col=size+(col-1);
            else
                col--;

            if(row-1<0)
                row=size+(row-1);
            else
                row--;

            gotoxy(col*4, row);
            cout<<i;
        }
        else
        {
            gotoxy(col*4, ++row);
            cout<<i;
        }
    }
}
