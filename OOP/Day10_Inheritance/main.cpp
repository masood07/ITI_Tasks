#include <iostream>
#include "string.h"
using namespace std;
class person
{
protected:
    int id;
    char* name;
    int age;
public:
    person()
    {
        name=new char[20];
        strcpy(name,"anonymous");
        id=0;
        cout<<"Person paramless ctor\n";
    }
    person(int _id,char* _name)
    {
        name=new char[20];
        setID(_id);
        setName(_name);
        age=6;
        cout<<"Person 2param ctor\n";
    }
    person(int _id,char* _name,int _age)
    {
        name=new char[20];
        setID(_id);
        setName(_name);
        setAge(_age);
        cout<<"Person 3param ctor\n";
    }
    void setID(int _id)
    {
        if(_id>0)
            id=_id;
        else
            cout<<"Invalid id"<<endl;
    }
    void setName(char* _name)
    {
        strcpy(name,_name);
    }
    void setAge(int _age)
    {
        if(_age>0)
            age=_age;
        else
            cout<<"\n invalid age for person"<<endl;
    }
    int getID()
    {
        return id;
    }
    int getAge()
    {
        return age;
    }
    char* getName()
    {
        return name;
    }
    void print()
    {
       cout<<"ID: "<<id<<" Name: "<<name<<" age: "<<age;
    }
    ~person()
    {
        delete[] name;
        cout<<"Person destruct with id: "<<id<<" Name: "<<name<<endl;
    }
};
class student:public person
{
    int grade;
public:
    student()
    {
        cout<<"Student paramless ctor\n"<<endl;
    }
    student(int _id,char* _name):person(_id,_name,20)
    {
        grade=1;
        cout<<"Student 2param ctor\n";
    }
    student(int _id,char* _name,int _age):person(_id,_name,_age)
    {
        grade=1;
        setAge(_age);
        cout<<"Student 3param ctor\n";
    }
    student(int _id,char* _name,int _age,int _grade):person(_id,_name,_age)
    {
        setAge(_age);
        setGrade(_grade);
        cout<<"Student 4param ctor\n";
    }
    void setAge(int _age)
    {
        if(_age<=20)
            age=_age;
        else
            cout<<"\n invalid age for student"<<endl;
    }

    void setGrade(int _grade)
    {
        if(grade>0)
            grade=_grade;
        else
            grade=0;
    }
    int getGrade()
    {
        return grade;
    }
    void print()
    {
        person::print();
        cout<<" Grade: "<<grade;
    }
    ~student()
    {
        cout<<"Student destructor id: "<<id<<" name: "<<name<<endl;
    }
};
class employee:public person
{
    float salary;
public:
    employee()
    {
        cout<<"Eployee paramless ctor\n";
    }
    employee(int _id,char* _name):person(_id,_name,30)
    {
        salary=3000;
        cout<<"Employee 2param ctor\n";
    }
    employee(int _id,char* _name,int _age):person(_id,_name,_age)
    {
        setAge(_age);
        salary=3000;
        cout<<"Employee 3param ctor\n";
    }
    employee(int _id,char* _name,int _age,int _salary):person(_id,_name,_age)
    {
        setAge(_age);
        salary=_salary;
        cout<<"Employee 4param ctor\n";
    }
    void setAge(int _age)
    {
        if(_age>=30)
            age=_age;
        else
            cout<<"\n invalid age for employee"<<endl;
    }
    void setSalary(float _salary)
    {
        salary=_salary;
    }
    float getSalary()
    {
        return salary;
    }
    void print()
    {
        person::print();
        cout<<" Salary: "<<salary;
    }
    ~employee()
    {
        cout<<"Employee destructor id: "<<id<<" Name: "<<name<<endl;
    }
};
class instructor:public employee
{
    char *subject;
public:
    instructor()
    {
        subject=new char[20];
        strcpy(subject,"Unkown");
        cout<<"Instructor pramless ctor\n";
    }
    instructor(int _id,char* _name):employee(_id,_name,35)
    {
        subject=new char[20];
        strcpy(subject,"Unkown");
        cout<<"Instructor 2param ctor\n";
    }
    instructor(int _id,char* _name,int _age):employee(_id,_name,_age)
    {
        subject=new char[20];
        strcpy(subject,"Unkown");
        setAge(_age);
        cout<<"Instructor 3param ctor\n";
    }
    instructor(int _id,char* _name,int _age,int _salary):employee(_id,_name,_age,_salary)
    {
        subject=new char[20];
        strcpy(subject,"Unkown");
        setAge(_age);
        cout<<"Instructor 4param ctor\n";
    }
    instructor(int _id,char* _name,int _age,int _salary,char* _subject):employee(_id,_name,_age,_salary)
    {
        subject=new char[20];
        strcpy(subject,_subject);
        setAge(_age);

        cout<<"Instructor 5param ctor\n";
    }
    void setSubject(char* _subject)
    {
        strcpy(subject,_subject);
    }
    char*getSubject()
    {
        return subject;
    }
    void print()
    {
        employee::print();
        cout<<" Subject: "<<subject;
    }
    ~instructor()
    {
        cout<<"Instructor destructor ID: "<<id<<" Name: "<<name;
        delete[] subject;
    }
};
int main()
{
    person p(1,"tarek");
    p.print();
    cout<<endl<<endl;

    person p1(2,"mostafa",23);
    p1.print();
    cout<<endl<<endl;

    employee e;
    e.setID(1000);
    e.setAge(50);
    e.setSalary(10000);
    e.setName("Mohamed");
    e.print();
    cout<<endl<<endl;

    employee e1(2000,"ahmed");
    e1.print();
    cout<<endl<<endl;

    employee e2(3000,"tarek",29);
    e2.print();
    cout<<endl<<endl;

    employee e3(4000,"tarek",35);
    e3.print();
    cout<<endl<<endl;

    student s(5000,"lmar",25);
    s.print();
    cout<<endl<<endl;

    instructor i;
    i.setID(3001);
    i.setName("Dr Hassan");
    i.setAge(45);
    i.setSalary(12000.0);
    i.setSubject("Data Structures");
    i.print();
    cout<<endl<<endl;

    instructor i1(3002,"Dr fatma",40,11500,"Algorithms");
    i1.print();
    cout<<endl<<endl;
    return 0;
}
