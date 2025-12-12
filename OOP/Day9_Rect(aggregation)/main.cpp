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
    point* ul;
    point* lr;
public:
    void set_UL(int _x,int _y)
    {
        ul->set_point(_x,_y);
    }
    void set_LR(int _x,int _y)
    {
        lr->set_point(_x,_y);
    }
    void set_UL(point* p)
    {
        ul=p;
    }
    void set_LR(point* p)
    {
        lr=p;
    }
    point* get_UL()
    {
        return ul;
    }
    point* get_LR()
    {
        return lr;
    }
    int get_area()
    {
        //height*width
        if(ul&&lr){
        int height=ul->get_y()-lr->get_y();
        int width=lr->get_x()-ul->get_x();
        return height*width;
        }
        return 0;
    }
    int get_perimeter()
    {
        //)height+width)*2
        if(ul&&lr){
        int height=ul->get_y()-lr->get_y();
        int width=lr->get_x()-ul->get_x();
        return (height+width)*2;
        }
        return 0;
    }
    rectangle()
    {
        ul=NULL;
        lr=NULL;
        cout<<"Rectangle pramless-ctor"<<endl;
    }
    rectangle(point* p1,point* p2)
    {
        ul=p1;
        lr=p2;
        cout<<"Rectangle 2 param ctor"<<endl;
    }
    rectangle(rectangle& r)
    {
        cout << "Rectangle copy_ctor" << endl;
    }
    void print()
    {
        cout<<"Rectangle points"<<endl;
        if(ul)
        {
            cout<<"Upper left point: ";
            ul->print();
        }
        if(lr)
        {
            cout<<"Lower right point: ";
            lr->print();
        }
    }
    ~rectangle()
    {
        cout<<"Rectangle destructor"<<endl;
    }
};

int main()
{
    int x1,y1,x2,y2;
    cout<<"enter triangle points\nenter upper left point\nx : ";
    cin>>x1;
    cout<<"y: ";
    cin>>y1;
    cout<<"enter lower right point\nx: ";
    cin>>x2;
    cout<<"y: ";
    cin>>y2;
    point* p1=new point(x1,y1);
    point* p2=new point(x2,y2);
    rectangle r2(p1,p2);
    r2.print();
    cout<<"perimeter= "<<r2.get_perimeter()<<endl;

    delete p1;
    delete p2;
    return 0;
}
