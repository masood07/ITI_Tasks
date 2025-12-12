#include <iostream>
using namespace std;
int gcd ( int a , int b )
{
    /*three base cases and recursive gcd(a,b)==gcd(a-b,b)*/
    if(a==1||b==1)
        return 1;
    else if(a==0||b==0)
        return 0;
    else if(a==b)
        return a;
    if(a>b)
        return gcd(a-b,b);
    else
        return gcd(a,b-a);
}
class fraction
{
    int num;
    int den;
    void simplify()
    {
        int g=gcd(abs(num),abs(den));
        num/=g;
        den/=g;
    }
public:
    fraction(int n=0,int d=1)
    {
        setNum(n);
        setDen(d);
        simplify();
    }
    void setNum(int n)
    {
        num=n;
    }
    void setDen(int d)
    {
        if(d==0)
        {
            cout<<"Denominator cannot be zero"<<endl;
            den=1;
        }
        else if(d<0)
        {
            num=-num;
            den=-d;
        }
        else
        {
            den=d;
        }
    }
    int getNum()
    {
        return num;
    }
    int getDen()
    {
        return den;
    }
    //fraction+fraction
    fraction operator+(fraction&f)
    {
        fraction res(num*f.den+f.num*den,den*f.den);
        return res;
    }
    //fraction+int
    fraction operator+(int val)
    {
        fraction f(val,1);
        return *this+f;
    }
    //COMPARE ==
    bool operator==(fraction f)
    {
        return (num==f.num)&&(den==f.den);
    }
    // !=
    bool operator!=(fraction f)
    {
        return !(*this==f);
    }
    //  >
    bool operator>(fraction f)
    {
        //a/b>c/d --> a*d>c*b
        return(num*f.den)>(f.num*den);
    }
    bool operator<(fraction f)
    {
        return(num*f.den)<(f.num*den);
    }
    //prefix
    fraction& operator++()
    {
        //1-->den/den
        num+=den;
        simplify();
        return *this;
    }
    //postfix
    fraction operator++(int)
    {
        fraction temp=*this;
        num+=den;
        simplify();
        return temp;
    }
    explicit operator float()
    {
        return ((float)num/den);
    }
    void display()
    {
        if(den==1)
        {
            cout<<num;
        }
        else
        {
            cout<<num<<"/"<<den;
        }
    }
    //int+fraction
    friend fraction operator+(int val,fraction& f);
};
fraction operator+(int val,fraction& f)
{
    fraction v(val,1);
    return f+v;
}
int main()
{
    fraction a(3,4);
    fraction b(5,6);
    fraction c=a+b;
    c.display();
    cout<<endl<<endl;

    c=a+2;
    c.display();
    cout<<endl<<endl;

    c=3+a;
    c.display();
    cout<<endl<<endl;

    c=a;
    (a==b)?cout<<"a=b":cout<<"a!=b";
    cout<<endl;
    (a!=b)?cout<<"a!=b":cout<<"a=b";
    cout<<endl;
    (c==a)?cout<<"c=a":cout<<"c!=a";
    cout<<endl;
    (a>b)?cout<<"a>b":cout<<"a<b";
    cout<<endl;
    (a<b)?cout<<"a<b":cout<<"a>b";
    cout<<endl;

    fraction d(1,4);
    ++d;
    d.display();

    cout<<endl<<endl;
    fraction e(1,4);
    d=e++;
    cout<<"d:";
    d.display();
    cout<<endl;
    cout<<"e:";
    e.display();
    cout<<endl;

    cout<<endl<<endl;
    float f=(float)e;
    cout<<f;
    return 0;
}
