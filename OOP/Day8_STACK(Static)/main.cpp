#include <iostream>

using namespace std;

class Stack
{
    int tos;
    int size;
    int arr[4];
public:
    Stack()
    {
        tos=-1;
        size=4;
        cout<<"Stack Ctor"<<endl;
    }
    void push(int val)
    {
        if(tos<size-1)
        {
            tos++;
            arr[tos]=val;
        }
        else
            cout<<"Stack is full"<<endl;

    }
    bool pop(int &ret)
    {
        if(tos>-1)
        {
            ret=arr[tos];
            tos--;
            return 1;
        }
        else
        {
            cout<<"Stack is empty"<<endl;
            return 0;
        }
    }
    int top()
    {
        if(tos==-1)
            cout<<"Stack is empty"<<endl;
        else
            return arr[tos];
    }
    bool isempty()
    {
        return (tos==-1);
    }
    ~Stack()
    {
        cout<<"Stack destructor"<<endl;
    }
};

int main()
{
    Stack s;
    if(s.isempty())
        cout<<"stack is empty"<<endl;
    cout<<"Pushing 5 numbers 10,50,10,50,10"<<endl;
    s.push(10);
    s.push(50);
    s.push(10);
    s.push(50);
    s.push(10);
    cout<<"Top of stack= "<<s.top()<<endl;
    int ret;
    while(s.pop(ret))
        cout<<"Popped: "<<ret<<endl;

    return 0;
}
