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
class triangle
{
    point* p1;
    point* p2;
    point* p3;
public:
    //setters
    void set_p1(int _x,int _y)
    {
        p1->set_point(_x,_y);
    }
    void set_p1(point* p)
    {
        p1=p;
    }
    void set_p2(int _x,int _y)
    {
        p2->set_point(_x,_y);
    }
    void set_p2(point* p)
    {
        p2=p;
    }
    void set_p3(int _x,int _y)
    {
        p3->set_point(_x,_y);
    }
    void set_p3(point* p)
    {
        p3=p;
    }
    //getters
    point* get_p1()
    {
        return p1;
    }
    point* get_p2()
    {
        return p2;
    }
    point* get_p3()
    {
        return p3;
    }
    //ctors
    triangle()
    {
        p1=NULL;
        p2=NULL;
        p3=NULL;
        cout<<"Triangle paramless-ctor"<<endl;
    }
    triangle(point* _p1,point* _p2,point* _p3)
    {
        p1=_p1;
        p2=_p2;
        p3=_p3;
        cout<<"Triangle 3param ctor"<<endl;
    }
    void print()
    {
        cout<<"Triangle Points:"<<endl;
        if(p1){
        cout<<"Point 1: ";
        p1->print();
        }
        if(p2){
        cout<<"Point 2: ";
        p2->print();
        }
        if(p3){
        cout<<"Point 3: ";
        p3->print();
        }
    }

    ~triangle()
    {
        cout<<"Triangle destructor"<<endl;
    }
};
int main()
{
        int x1,y1,x2,y2,x3,y3;
    cout<<"enter triangle points:"<<endl;
    cout<<"point1\nx: ";
    cin>>x1;
    cout<<"y: ";
    cin>>y1;
    cout<<"point2\nx: ";
    cin>>x2;
    cout<<"y: ";
    cin>>y2;
    cout<<"point3\nx: ";
    cin>>x3;
    cout<<"y: ";
    cin>>y3;
    point* p1=new point(x1,y1);
    point* p2=new point(x2,y2);
    point* p3=new point(x3,y3);
    triangle t1(p1,p2,p3);
    t1.print();
    delete p1;
    delete p2;
    delete p3;
    return 0;
}
