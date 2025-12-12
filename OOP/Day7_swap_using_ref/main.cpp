#include <iostream>

using namespace std;

void swap(int& x,int &y);

int main()
{
    int x,y;
    cout<<"Enter two numbers to swap:\nx= ";
    cin>>x;
    cout<<"y= ";
    cin>>y;
    cout<<"\n-----------------\n";
    cout<<"before swaping:\nx= "<<x<<"\ny= "<<y;
    cout<<"\n-----------------\n";
    swap(x,y);
    cout<<"after swaping:\nx= "<<x<<"\ny= "<<y;
    return 0;
}

void swap(int& x,int &y)
{
    int temp=x;
    x=y;
    y=temp;
}
