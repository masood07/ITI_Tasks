#include <iostream>

using namespace std;

class complex{
int real;
int img;
public:
    int get_real()
    {
        return real;
    }
    void set_real(int _real)
    {
        if(_real >= -1000 && _real <= 1000)
            real = _real;
        else
            real = 0;
    }
    int get_img()
    {
        return img;
    }
    void set_img(int _img)
    {
        if(_img >= -1000 && _img <= 1000)
            img = _img;
        else
            img = 0;
    }
    //CTORS
    /*complex(int _real=0,int _img=0)
    {
        set_real(_real);
        set_img(_img);
        cout<<endl<<"CTOR"<<endl;
    }*/
    complex(int _real,int _img)
    {
        set_real(_real);
        set_img(_img);
        cout<<endl<<"CTOR"<<endl;
    }
    complex(int _real)
    {
        set_real(_real);
        set_img(0);
        cout<<endl<<"CTOR"<<endl;
    }
    complex()
    {
        set_real(0);
        set_img(0);
        cout<<endl<<"CTOR"<<endl;
    }
    void print()//mem function
    {
        if(img>0)
            cout<<endl<<real<<"+"<<img<<"j"<<endl;
        else if(img<0)
            cout<<endl<<real<<img<<"j"<<endl;
        else
            cout<<endl<<real<<endl;
    }
    ~complex()
    {
        cout<<endl<<"destructor\n";
    }
    friend void friend_print(complex c);
};
void friend_print(complex c);

int main()
{
    complex c1(5),c2(4,3),c3;
    friend_print(c1);
    c2.print();
    c2.set_real(3);
    cout<<c2.get_real();
    cout<<endl<<"---------------------"<<endl;
    cout<<"enter complex number:\nreal=";
    int real;
    cin>>real;
    c3.set_real(real);
    cout<<"img=";
    int img;
    cin>>img;
    c3.set_img(img);
    cout<<"---------------------"<<endl;
    c3.print();

    return 0;
}

void friend_print(complex c)
{
    if(c.img>=0)
            cout<<c.real<<"+"<<c.img<<"j"<<endl;
        else
            cout<<c.real<<c.img<<endl;
}
