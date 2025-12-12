#include <iostream>

using namespace std;

int main()
{
    char c;
    int ascii;
    cout<<"plz enter character:";
    cin>>c;
    ascii=c;
    cout<<endl<<c<<" ascii is= "<<ascii;
    cout<<endl<<ascii<<" is the ascii of character: "<<c;
    cout<<"\n--------------------------------------------";

    int a,b;
    cout<<"\nplz enter two numbers:";
    cin>>a>>b;
    cout<<"\naddition= "<<a+b<<"\nsubtraction= "<<a-b<<"\nmul= "<<a*b<<"\ndiv= "<<a/b<<endl;

    cout<<"\n--------------------------------------------";
    cout<<"\nplz enter a SMALL character to convert it into CAPITAL character:";
    cin>>c;
    cout<<endl<<(char)(c-('a'-'A'));
    cout<<"\nplz enter a CAPITAL character to convert it into SMALL character:";
    cin>>c;
    cout<<endl<<(char)(c+('a'-'A'));
    return 0;
}
