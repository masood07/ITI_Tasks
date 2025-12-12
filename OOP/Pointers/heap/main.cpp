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
    //two dim array of int dynamic
    int **p=new int*[3];
    if(p!=NULL)
    {
        for(int i=0;i<3;i++)
        {
            p[i]=new int[4];
        }
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<4;j++)
            {
                cout<<"p["<<i<<"]["<<j<<"]= ";
                cin>>p[i][j];
            }
        }
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<4;j++)
            {
                cout<<"p["<<i<<"]["<<j<<"]= "<<p[i][j]<<endl;
            }
        }
        for(int i=0;i<3;i++)
        {
            delete[] p[i];
        }
        delete p;
    }
    cout<<"----------------"<<endl;
    //array of dynamic
    int size;
    cout<<"Enter number of employees: ";
    cin>>size;
    emp* em=new emp[size];

    for(int i=0;i<size;i++)
    {
        em[i].id=-1;
    }
    char menu[4][20]={"new","display","delete_by_name","delete_by_id"};
    int cp=0;
    char ch;
    int flag=0;
    do
    {
        system("cls");
        for(int i=0;i<4;i++)
        {
            if(i==cp)
            textattr(0xf4);
            gotoxy(10,5+i);
            cout<<menu[i];
            textattr(0x07);
        }
        ch=getch();
        switch(ch)
        {
        case -32:
            ch=getch();
            switch(ch)
            {
                case 72:
                    cp--;
                    if(cp<0)
                    cp=3;
                    break;
                case 80:
                    cp++;
                    if(cp>3)
                        cp=0;
                    break;
            }
            break;
        case 13://enter
            //check the cursor position
            if(cp==0)//new
            {
                system("cls");
                int pos;
                cout<<"Enter the position"<<endl;
                cin>>pos;
                if(em[pos].id!=-1)
                {
                    char f;
                    cout<<"Do you want to override (y/n)?"<<endl;
                    f=getch();
                    cout<<f<<endl;
                    if(f=='y'||f=='Y')
                    {
                        cout<<"Enter id name salary: ";
                        cin>>em[pos].id>>em[pos].name>>em[pos].salary;
                    }
                }
                else
                {
                        cout<<"Enter id name salary: ";
                        cin>>em[pos].id>>em[pos].name>>em[pos].salary;
                }
            }
            else if(cp==1)//display
            {
                system("cls");
                for(int i=0;i<size;i++)
                {
                    cout<<"\nemployee["<<i<<"]\nid: "<<em[i].id<<"\nName: "<<em[i].name<<"\nSalary: "<<em[i].salary<<endl;
                    cout<<"--------------------------";
                }
                getch();
            }
            else if(cp==2)//delete by name
            {
                system("cls");
                cout<<"Enter the Name: ";
                char Na[20];
                cin>>Na;
                int fl=0;
                for(int i=0;i<size;i++)
                {
                    if(strcmpi(Na,em[i].name)==0)
                    {
                        fl=1;
                        em[i].id=-1;
                    }
                }
                if(fl==0)//not exist
                {
                    cout<<"Not exist\n";
                }
                getch();
            }
            else//delete by id
            {
                system("cls");
                cout<<"Enter id: ";
                int ide;
                cin>>ide;
                int fle=0;
                for(int i=0;i<size;i++)
                {
                    if(em[i].id==ide)
                    {
                        fle=1;
                        em[i].id=-1;
                    }
                }
                if(fle==0)
                {
                    cout<<"ID not exist\n";
                }
                getch();
            }
            break;
        case 27://esc
            system("cls");
            cout<<"Good bye"<<endl;
            flag=1;
        }
    }while(flag==0);


    return 0;
}


void textattr(int i)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}
void gotoxy( int column, int line )
{
  COORD coord;
  coord.X = column;
  coord.Y = line;
  SetConsoleCursorPosition(
    GetStdHandle( STD_OUTPUT_HANDLE ),
    coord
    );
}
