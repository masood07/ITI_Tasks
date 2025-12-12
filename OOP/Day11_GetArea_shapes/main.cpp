#include <iostream>
#define pi 3.14
using namespace std;

class shape
{
protected:
    int dim1;
    int dim2;
public:
    shape()
    {
        dim1=dim2=1;
        cout<<"Shape ctor pramless ctor"<<endl;
    }
    shape(int _x)
    {
        setDim1(_x);
        dim2=dim1;
    }
    shape(int _x,int _y)
    {
        setDim1(_x);
        setDim2(_y);
    }
    virtual float area()=0;
    //setters
    virtual void setDim1(int _x)
    {
        if(_x>0)
            dim1=_x;
        else
            cout<<"invalid dimension"<<endl;
    }
    virtual void setDim2(int _y)
    {
        if(_y>0)
            dim2=_y;
        else
            cout<<"invalid dimension"<<endl;
    }

};
class rectangle:public shape
{
public:
    rectangle(int _x,int _y):shape(_x,_y)
    {
        cout<<"Rectangle 2param ctor"<<endl;
    }
    float area()
    {
        return dim1*dim2;
    }
};
class triangle:public shape
{
public:
    triangle(int _x,int _y):shape(_x,_y)
    {
        cout<<"triangle 2param ctor"<<endl;
    }
    float area()
    {
        return 0.5*dim1*dim2;
    }
};
class square:public rectangle
{
public:
    square(int _x):rectangle(_x,_x)
    {
        cout<<"Square 1param ctor"<<endl;
    }
    void setDim1(int _x)
    {
        if(_x>0)
            dim1=dim2=_x;
        else
            cout<<"invalid dimension"<<endl;
    }
    void setDim2(int _x)
    {
        if(_x>0)
            dim2=dim1=_x;
        else
            cout<<"invalid dimension"<<endl;
    }
};
class circle:public shape
{
public:
    circle(int _x)
    {
        setDim1(_x);
        dim2=dim1;
    }
    void setDim1(int _x)
    {
        if(_x>0)
            dim1=dim2=_x;
        else
            cout<<"Invalid dimension"<<endl;
    }
    void setDim2(int _x)
    {
        if(_x>0)
            dim2=dim1=_x;
        else
            cout<<"Invalid dimension"<<endl;
    }
    float area()
    {
        return pi*dim1*dim2;
    }
};
void AreaAddress(shape* s)
{
    cout<<s->area();
}
void AreaReference(shape& s)
{
    cout<<s.area();
}
int main()
{
    rectangle r(10,20);
    triangle t(10,20);
    AreaAddress(&r);
    cout<<endl<<endl;

    AreaAddress(&t);
    cout<<endl<<endl;

    square s(5);
    AreaAddress(&s);
    cout<<endl<<endl;

    s.setDim1(10);
    AreaAddress(&s);
    cout<<endl<<endl;

    shape* sh=&s;
    sh->setDim1(5);
    AreaReference(s);
    cout<<endl<<endl;

    rectangle* re=&s;
    re->setDim1(25);
    AreaReference(s);
    cout<<endl<<endl;

    shape* ss=&s;
    ss->setDim1(2);
    cout<<ss->area();
    cout<<endl<<endl;

    shape* arr[4];
    arr[0]=new rectangle(10,20);
    arr[1]=new triangle(10,20);
    arr[2]=new square(10);
    arr[3]=new circle(5);
    for(int i=0;i<4;i++)
    {
        AreaAddress(arr[i]);
        cout<<endl;
    }
    return 0;
}
