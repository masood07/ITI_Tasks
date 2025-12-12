#include <iostream>
#include "conio.h"
using namespace std;

void Menu()
{
    char choice;
    do
    {
        system("cls");
        cout<<"n for new item\nd for display\ne for exit\n";
        choice=getch();
        switch(choice)
        {
            case 'n':
            case 'N':
                cout<<"insert new item\n";
                getch();
                break;
            case 'd':
            case 'D':
                cout<<"display items\n";
                getch();
                break;
        }

    }while(choice!='e'&&choice!='E');
    system("cls");
    cout<<"EXIT";
}
