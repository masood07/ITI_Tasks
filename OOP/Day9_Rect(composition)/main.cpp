#include <iostream>

using namespace std;
class point
{
    int x;
    int y;
public:
    void set_x(int _x)
    {
        if(_x<0)
            {
                cout<<"X coordinate can't be negative x point will be zero"<<endl;
                x=0;
            }
        else
            x=_x;
    }
    int get_x()
    {
        return x;
    }
    void set_y(int _y)
    {
        if(_y<0)
            {
                cout<<"Y coordinate can't be negative y point will be zero"<<endl;
                y=0;
            }
        else
            y=_y;
    }
    int get_y()
    {
        return y;
    }
    void set_point(int _x,int _y)
    {
        set_x(_x);
        set_y(_y);
    }
    void get_point(int& _x,int& _y)
    {
        _x=get_x();
        _y=get_y();
    }
    point(int _x,int _y)
    {
        set_x(_x);
        set_y(_y);
        cout<<"Point 2param_ctor ("<<x<<","<<y<<")"<<endl;
    }
    point(int _x)
    {
        set_x(_x);
        set_y(_x);
        cout<<"Point 1param_ctor ("<<x<<","<<y<<")"<<endl;
    }
    point()
    {
        y=x=0;
        cout<<"Point paramless_ctor ("<<x<<","<<y<<")"<<endl;
    }
    point(point& p)
    {
        x = p.x;
        y = p.y;
        cout << "Point copy_ctor ("<<x<<","<<y<<")"<<endl;
    }
    void print()
    {
        cout<<"("<<x<<","<<y<<")"<<endl;
    }
    ~point()
    {
        cout<<"Point destructor ("<<x<<","<<y<<")"<<endl;
    }
};
class rectangle
{
    point ul;
    point lr;
public:
    void set_UL(int _x,int _y)
    {
        ul.set_point(_x,_y);
    }
    void set_LR(int _x,int _y)
    {
        lr.set_point(_x,_y);
    }
    void set_UL(point p)
    {
        ul=p;
    }
    void set_LR(point p)
    {
        lr=p;
    }
    point get_UL()
    {
        return ul;
    }
    point get_LR()
    {
        return lr;
    }
    int get_area()
    {
        //height*width
        int height=ul.get_y()-lr.get_y();
        int width=lr.get_x()-ul.get_x();
        return height*width;
    }
    int get_perimeter()
    {
        //(height+width)*2
        int height=ul.get_y()-lr.get_y();
        int width=lr.get_x()-ul.get_x();
        return (height+width)*2;
    }
    rectangle():ul(10,30)
    {
        cout<<"Rectangle pramless-ctor"<<endl;
    }
    rectangle(int x1,int y1,int x2,int y2):ul(x1,y1),lr(x2,y2)
    {
        cout<<"Rectangle 4 param ctor"<<endl;
    }
    rectangle(rectangle& r)
    {
        cout << "Rectangle copy_ctor" << endl;
    }
    void print()
    {
        cout<<"Rectangle points"<<endl;
        cout<<"Upper left point: ";
        ul.print();
        cout<<"Lower right point: ";
        lr.print();
    }
    ~rectangle()
    {
        cout<<"Rectangle destructor"<<endl;
    }
};

int main()
{
    point p;
    p.print();

    point p2(5, 10);
    p2.print();

    point p3(-5, -10);
    p3.print();


    int x1,y1,x2,y2;
    cout<<"enter triangle points\nenter upper left point\nx : ";
    cin>>x1;
    cout<<"y: ";
    cin>>y1;
    cout<<"enter lower right point\nx: ";
    cin>>x2;
    cout<<"y: ";
    cin>>y2;
    rectangle r1(x1,y1,x2,y2);
    r1.print();
    cout<<"area: "<<r1.get_area()<<endl;
    cout<<"perimeter: "<<r1.get_perimeter()<<endl;

    rectangle r2;
    r2.print();
    r2.set_UL(5, 25);
    r2.set_LR(15, 10);
    r2.print();
    cout<<"Area: "<<r2.get_area()<< endl;

    point p4 = p2;
    p4.print();

    rectangle r3 = r1;
    r3.print();



    return 0;
}
