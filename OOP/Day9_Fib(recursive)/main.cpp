#include <iostream>

using namespace std;
int fib(int x)
{
    if(x==1||x==0)
        return x;
    else
    return fib(x-1)+fib(x-2);
}
int main()
{
    int val;
    do
    {
        cout<<"enter positive value to evaluate fibonacci:"<<endl;
        cin>>val;
    }while(val<0);
    cout<<fib(val);
    return 0;
}
