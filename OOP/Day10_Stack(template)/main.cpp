#include <iostream>

using namespace std;
template<class t>
class Stack
{
    int tos;
    int size;
    t *arr;
public:
    Stack(int _size=5)
    {
        size=_size;
        arr=new t[size];
        tos=-1;
        cout<<"Stack Ctor"<<endl;
    }
    Stack(Stack& s)
    {
        size=s.size;
        arr=new t[size];
        tos=s.tos;
        for(int i=0;i<=tos;i++)
            arr[i]=s.arr[i];
        cout<<"COPY CTOR"<<endl;
    }
    void push(t val)
    {
        if(tos<size-1)
        {
            tos++;
            arr[tos]=val;
        }
        else
            cout<<"Stack is full"<<endl;
    }
    bool pop(t& ret)
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
    t top()
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
        delete[] arr;
    }

};

int main()
{
    int size;
    cout<<"Enter size of stack:";
    cin>>size;
    Stack<int>s(size);

    cout<<"Pushing values 10,20,30"<<endl;
    s.push(10);
    s.push(20);
    s.push(30);
    int ret;
    s.pop(ret);
    cout<<ret;
    cout<<endl<<endl;

    char ret1;
    Stack<char>s1(5);
    s1.push(')');
    s1.push('(');
    s1.push('[');
    s1.push(']');
    s1.pop(ret1);
    cout<<ret1<<endl<<endl;

    return 0;
}
