#include <iostream>

using namespace std;

void Binary(int num)
{
    for(int i=32;i>=0;i--)
    {
        cout<<((num&(1<<i))>>i);
    }
}
