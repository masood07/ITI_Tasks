#include <iostream>
#define pi 3.14
using namespace std;
class point
{
    int x;
    int y;
public:
    point(int _x,int _y)
    {
        setX(_x);
        setY(_y);
        cout<<"Point 2param ctor"<<endl;
    }
    point(int _x)
    {
        setX(_x);
        setY(_x);
        cout<<"Point 1param ctor"<<endl;
    }
    point(point& p)
    {
        x=p.x;
        y=p.y;
    }
    void setX(int _x)
    {
        if(_x>=0)
            x=_x;
        else
            cout<<"Invalid value of x"<<endl;
    }
    void setY(int _y)
    {
        if(_y>=0)
            y=_y;
        else
            cout<<"Invalid value of y"<<endl;
    }
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
    void print()
    {
        cout<<'('<<x<<','<<y<<')'<<endl;
    }
    ~point()
    {
        cout<<"Point destructor ("<<x<<','<<y<<')'<<endl;
    }
};
class shape
{
protected:
    int dim1;
    int dim2;
public:
    virtual float area()=0;
    int getDim1()
    {
        return dim1;
    }
    int getDim2()
    {
        return dim2;
    }
    virtual void print()=0;

};
class rectangle:public shape
{
    point ul;
    point lr;
public:
    rectangle(int x1,int y1,int x2,int y2):ul(x1,y1),lr(x2,y2)
    {
        dim1=abs(x2-x1);
        dim2=abs(y2-y1);
        cout<<"Rectangle 4param ctor"<<endl;
    }
    rectangle(point &_ul,point &_lr):ul(_ul),lr(_lr)
    {
        dim1=abs(lr.getX()-ul.getX());
        dim2=abs(lr.getY()-ul.getY());
        cout<<"Rectangle 2param ctor"<<endl;
    }
    float area()
    {
        return dim1*dim2;
    }
    void print()
    {
        cout<<"UpperLeft point: ("<<ul.getX()<<','<<ul.getY()<<')'<<endl;
        cout<<"LowerRight point: ("<<lr.getX()<<','<<lr.getY()<<')'<<endl;
        cout<<"Height: "<<dim1<<", Width: "<<dim2<<endl;
        cout<<"Area: "<<area()<<endl;
    }
};
class triangle:public shape
{
    point p1;
    point p2;
    point p3;
public:
    triangle(int x1,int y1,int x2,int y2,int x3,int y3):p1(x1,y1),p2(x2,y2),p3(x3,y3)
    {
        dim1=abs(p2.getX()-p1.getX());
        dim2=abs(p3.getY()-p1.getY());
        cout<<"Triangle 6param ctor"<<endl;
    }
    triangle(point &_p1,point &_p2,point &_p3):p1(_p1),p2(_p2),p3(_p3)
    {
        dim1=abs(p2.getX()-p1.getX());
        dim2=abs(p3.getY()-p1.getY());
        cout<<"Triangle 3param ctor"<<endl;
    }
    float area()
    {
        return 0.5*dim1*dim2;
    }
    void print()
    {
        cout<<"Point 1: ("<<p1.getX()<<','<<p1.getY()<<')'<<endl;
        cout<<"Point 2: ("<<p2.getX()<<','<<p2.getY()<<')'<<endl;
        cout<<"Point 3: ("<<p3.getX()<<','<<p3.getY()<<')'<<endl;
        cout<<"Base: "<<dim1<<", Height: "<<dim2<<endl;
        cout<<"Area: "<<area()<<endl;
    }
    ~triangle()
    {
        cout<<"triangle destructor"<<endl;
    }
};
class square:public rectangle
{
public:
    square(int x1,int y1,int length):rectangle(x1,y1,x1+length,y1+length)
    {
        cout<<"Square 3param ctor"<<endl;
    }
    square(point &_ul,int length):rectangle(_ul.getX(),_ul.getY(),_ul.getX()+length,_ul.getY()+length)
    {
        cout<<"Square 2param ctor"<<endl;
    }
};
class circle:public shape
{
    point center;
public:
    circle(int cx,int cy,int rad):center(cx,cy)
    {
        dim1=dim2=rad;
        cout<<"Circle 3param ctor"<<endl;
    }
    circle(point &_c,int rad):center(_c)
    {
        dim1=dim2=rad;
        cout<<"Circle 2param ctor"<<endl;
    }
    float area()
    {
        return pi*dim1*dim1;
    }
    void print()
    {
        cout<<"Center: ("<<center.getX()<<','<<center.getY()<<')'<<endl;
        cout<<"Radius: "<<dim1<<endl;
        cout<<"Area: "<<area()<<endl;
    }
};
void PrintDataAddress(shape* s)
{
    s->print();
}
void PrintDataReference(shape& s)
{
    s.print();
}
int main()
{
    point p1(0,0);
    point p2(10,0);
    point p3(5,8);
    triangle tri(p1,p2,p3);
    tri.print();
    cout<<endl<<endl;

    point c1(5,5);
    circle cir(c1,7);
    PrintDataAddress(&cir);
    cout<<endl<<endl;

    rectangle rec(0,0,4,6);
    PrintDataReference(rec);
    cout<<endl<<endl;

    square sq(0,0,5);
    sq.print();
    return 0;
}
