#include <iostream>

using namespace std;
class Stack
{
    int tos;
    int size;
    int *arr;
    static int count;
public:
    static int getCount()
    {
        return count;
    }
    Stack(int _size)
    {
        count++;
        size=_size;
        arr=new int[size];
        tos=-1;
        cout<<"Stack Ctor"<<endl;
    }
    Stack(Stack& s)
    {
        count++;
        size=s.size;
        arr=new int[size];
        tos=s.tos;
        for(int i=0;i<=tos;i++)
            arr[i]=s.arr[i];
        cout<<"COPY CTOR"<<endl;
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
    bool pop(int& ret)
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
    //assignment
    Stack&operator=(Stack&s)
    {
        size=s.size;
        tos=s.tos;
        delete[]arr;
        arr=new int[size];
        for(int i=0;i<=tos;i++)
            arr[i]=s.arr[i];
        return *this;
    }
    // + operator (append)
    Stack operator+(Stack&s)
    {
        //10,20,100,200 tos1=1 tos2=1 sizeof s3=tos1+1+tos2+1
        int nSize=tos+1+s.tos+1;
        Stack res(nSize);
        for(int i=0;i<=tos;i++)
            {
                res.tos++;
                res.arr[i]=arr[i];
            }
        for(int i=0;i<=s.tos;i++)
            {
                res.tos++;
                res.arr[res.tos]=s.arr[i];
            }
            return res;
    }
    ~Stack()
    {
        count--;
        cout<<"Stack destructor"<<endl;
        delete[] arr;
    }
    friend void stack_byvalue(Stack s);
    friend void stack_byref(Stack& s);
    friend void stack_byaddress(Stack* s);
};
void stack_byvalue(Stack s1)//->call copy ctor
{
    cout<<"Pop all by value"<<endl;
    int ret;
    while(s1.pop(ret))//-->pop from the copy stack
        cout<<"Popped: "<<ret<<endl;
    cout<<"original stack unchanged"<<endl;
}
void stack_byref(Stack& s1)
{
    cout<<"Pop all by reference"<<endl;
    int ret;
    while(s1.pop(ret))//-->pop from the original stack
        cout<<"Popped: "<<ret<<endl;

    cout<<"original stack empty"<<endl;
}
void stack_byaddress(Stack* s1)
{
    cout<<"Pop all by address"<<endl;
    int ret;
    while(s1->pop(ret))//-->pop from the original stack
        cout<<"Popped: "<<ret<<endl;

    cout<<"original stack empty"<<endl;
}
int Stack::count=0;
int main()
{
    Stack s1(5),s2(6);
    cout<<Stack::getCount()<<endl;
    s1.push(5);
    s1.push(6);
    stack_byvalue(s1);
    cout<<Stack::getCount()<<endl;

    s2=s1;
    stack_byref(s2);
    Stack s3(2);
    s3.push(10);
    s3.push(20);
    cout<<endl;

    Stack s4(3);
    s4.push(100);
    s4.push(200);
    Stack s5=s3+s4;
    stack_byref(s5);
    return 0;
}
