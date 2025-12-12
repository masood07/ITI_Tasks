#include <iostream>
#include <Windows.h>
#include "conio.h"
#define null -32

using namespace std;

void swap(int*x,int*y);
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
    //swap
    int x=10,y=20;
    swap(&x,&y);
    cout<<"x= "<<x<<" y= "<<y<<endl;
    cout<<"--------------------------"<<endl;
    //pointer to array of int
    int arr[5]={1,2,3,4,5};
    int *ptr=arr;
    for(int i=0;i<5;i++)
    {
        cout<<*(ptr+i)<<":"<<ptr[i]<<endl;
    }
    cout<<"\n--------------------------"<<endl;

    //pointer to array of struct
    emp ar[3];
    cout<<"Enter 3 employees information id name salary: \n";
    for(int i=0;i<3;i++)
    {
        cin>>ar[i].id>>ar[i].name>>ar[i].salary;
    }

    emp *pt=ar;
    for(int i=0;i<3;i++)
    {
        cout<<pt[i].id<<":"<<pt[i].name<<":"<<pt[i].salary<<endl;
    }

    cout<<"\n--------------------------"<<endl;
    //menu
    emp em[5];
    for(int i=0;i<5;i++)
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
                case 72://up
                    cp--;
                    if(cp<0)
                    cp=3;
                    break;
                case 80://down
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
                for(int i=0;i<5;i++)
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
                for(int i=0;i<5;i++)
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
                for(int i=0;i<5;i++)
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
            break;
        }
    }while(flag==0);
    return 0;
}

//swap function
void swap(int*x,int*y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
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
