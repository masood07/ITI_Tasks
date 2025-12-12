#include <iostream>

using namespace std;

bool Prime_Or_Not(int num);
void grade(int degree);
int Sum_Of_Five();
void Number_Of_Words_Chars();
int factorial(int num);
int power(int a,int b);
void Reverse(int num);
void Binary(int num);
void Menu();
void Magic_Box(int size);

int main() {
    int size;
    do
    {
        cout<<"Enter size of box:";
        cin>>size;
    }while(size%2==0);

    Magic_Box(size);

    return 0;
}
