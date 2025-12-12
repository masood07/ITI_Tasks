#include <iostream>
#define size 5
using namespace std;

int main()
{
    int a[size];
    //insert from user
    for(int i=0;i<size;i++)
    {
        cout<<"a["<<i<<"]= ";
        cin>>a[i];
    }
    cout<<"------------------"<<endl;

    //print array
    for(int i=0;i<size;i++)
    {
        cout<<"a["<<i<<"]= "<<a[i]<<endl;
    }

    cout<<"------------------"<<endl;

    //find the max value
    int max=a[0];
    for(int i=1;i<size;i++)
    {
        if(a[i]>max)
        max=a[i];
    }
    cout<<"Max value is: "<<max<<endl;

    cout<<"------------------"<<endl;

    //find the min value
    int min=a[0];
    for(int i=1;i<size;i++)
    {
        if(a[i]<min)
        min=a[i];
    }
    cout<<"min value is: "<<min<<endl;

    cout<<"------------------"<<endl;

    //sum of the elements of the array
    int sum=0;
    for(int i=0;i<size;i++)
    {
        sum+=a[i];
    }
    cout<<"Summation of the elements= "<<sum<<endl;

    cout<<"------------------"<<endl;

    //search for value using linear search
    int value;
    bool flag=0;
    cout<<"Plz enter the value u want to search: ";
    cin>>value;
    for(int i=0;i<size;i++)
    {
        if(value==a[i])
            {
                flag=1;
                cout<<"The value exist in index: "<<i<<endl;
            }
    }
    if(flag==0)
        cout<<"The value not exist in the array"<<endl;


    cout<<"------------------"<<endl;

    //Sorting array using bubble sort
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-i-1;j++)
            if(a[j]>a[j+1])
            {
                int swap=a[j+1];
                a[j+1]=a[j];
                a[j]=swap;
            }
    }

    //print sorted array

    for(int i=0;i<size;i++)
    {
        cout<<"a["<<i<<"]= "<<a[i]<<endl;
    }

    cout<<"------------------"<<endl;
    return 0;
}
