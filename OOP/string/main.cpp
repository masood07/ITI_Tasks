#include <iostream>
#include "string.h"
using namespace std;

int main()
{
    //two string from user,concat in another var

    char fname[10],lname[10],name[20];
    cout<<"Enter your first and second name: ";
    cin>>fname>>lname;
    strcpy(name,fname);
    strcat(name," ");
    strcat(name,lname);
    cout<<name<<endl;

    cout<<"------------------"<<endl;

    //names of 3 students and print them
    char std[3][10];
    for(int i=0;i<3;i++)
    {
        cout<<"Enter the "<<i<<" name: ";
        cin>>std[i];
    }

    for(int i=0;i<3;i++)
    {
        cout<<"std["<<i<<"]: "<<std[i]<<endl;
    }

    cout<<"------------------"<<endl;

    //insert string and convert chars from capital to small and vice versa
    cout<<"Enter your first name"<<endl;
    cin>>fname;
    int i=0;
    while(fname[i]!='\0')
    {
        if(fname[i]>='a'&&fname[i]<='z')
        {
            fname[i]-=('a'-'A');
        }
        else if(fname[i]>='A'&&fname[i]<='Z')
            {
            fname[i]+=('a'-'A');
        }
        i++;
    }
    cout<<fname<<endl;

    cout<<"------------------"<<endl;
    return 0;
}
