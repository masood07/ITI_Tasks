#include <iostream>

using namespace std;

int Sum_Of_Five()
{
    int num,sum=0;

    for(int i=0;i<5;i++)
    {
        cout<<"Plz enter the "<<i+1<<" number:";
        cin>>num;
        sum+=num;
        cout<<endl;
    }

    return sum;
}
