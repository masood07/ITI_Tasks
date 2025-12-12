#include <iostream>

using namespace std;

void grade(int degree)
{
    if(degree>=90&&degree<=100)
        cout<<"Excellent";

    else if(degree>=80)
        cout<<"Very Good";

    else if(degree>=70)
        cout<<"Good";

    else if(degree>=60)
        cout<<"Pass";

    else
        cout<<"fail";
}
