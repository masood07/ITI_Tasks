#include <iostream>

using namespace std;
template<class t>
void Swap(t& x,t& y)
{
    t temp=x;
    x=y;
    y=temp;
}

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
    Swap<int>(x,y);
    cout<<"after swaping:\nx= "<<x<<"\ny= "<<y;
    cout<<endl<<endl;


    float x1=0.3,y1=0.4;
    cout<<"before swaping:\nx= "<<x1<<"\ny= "<<y1<<endl;
    Swap<float>(x1,y1);
    cout<<"after swaping:\nx= "<<x1<<"\ny= "<<y1;
    return 0;
}


