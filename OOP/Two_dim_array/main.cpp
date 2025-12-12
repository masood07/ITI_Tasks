#include <iostream>
#define cols 4
#define rows 3
using namespace std;

int main()
{
    //insert 2d array
    int a[rows][cols];
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            cout<<"a["<<i<<"]"<<"["<<j<<"]= ";
            cin>>a[i][j];
        }
    }

    cout<<"------------------"<<endl;

    //print 2d array
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"------------------"<<endl;

    //sum of each row
    int sum=0;
    for(int i=0;i<rows;i++)
    {
        sum=0;
        for(int j=0;j<cols;j++)
        {
            cout<<a[i][j]<<" ";
            sum+=a[i][j];
        }
        cout<<": "<<sum<<endl;
    }

    cout<<"------------------"<<endl;

    //avg of each col

    for(int i=0;i<cols;i++)
    {
        sum=0;
        for(int j=0;j<rows;j++)
        {
            cout<<a[j][i]<<" ";
            sum+=a[j][i];
        }
        cout<<": "<<sum/rows<<endl;
    }

    cout<<"------------------"<<endl;
    return 0;
}
