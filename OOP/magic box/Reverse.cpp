#include <iostream>

using namespace std;

void Reverse(int num)
{
    while(num!=0)
    {
        cout<<num%10;
        num/=10;
    }
}
