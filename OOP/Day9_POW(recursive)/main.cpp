#include <iostream>

using namespace std;
int pow(int x,int y)//x^3= x*x^2==>x*x^1==>x*x^0(1)
{
    if(y==0)
        return 1;
    else
        return x*pow(x,y-1);
}
int main()
{
    int base,exp;
    cout<<"enter base value:";
    cin>>base;
    do
    {
        cout<<"enter positive exponent value:";
        cin>>exp;
    }while(exp<0);
    cout<<pow(base,exp);
    return 0;
}
