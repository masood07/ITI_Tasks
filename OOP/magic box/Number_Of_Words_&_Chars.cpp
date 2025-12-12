#include <iostream>
#include "conio.h"

using namespace std;

void Number_Of_Words_Chars()
{
    int words=0,chars=0;
    char c;
    cout<<"Enter your statement: ";
    do
    {
        c=getche();
        if(c==' ')
            words++;
        else
        {
            if(c!='\n' && c!='\r')
                chars++;
        }
    }while(c!='\n' && c!='\r');
    cout<<"\nNumber of words= "<<++words<<endl<<"Number of characters= "<<chars;
}
