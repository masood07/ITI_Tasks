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
template<class t>
void create(t* arr,int idx)
{
    int _id,_age,_grade;
    char _name[20];
    cout<<"Enter ID: ";
    cin>>arr[idx].setID(_id);
    cout<<"Enter Name: ";
    cin>>arr[idx].setName(_name);
    cout<<"Enter age: ";
    cin>>arr[idx].setAge(_age);
}
void update()
int main()
{
    student Sarr[5];
    employee Earr[5];
    instructor Iarr[5];
    int S=0,E=0,I=0;
    int ch;
    cout<<"enter number to create(1),update(2),delete(3),sortbyID(4): ";
    switch(ch)
    {
       case 1://create
            int ch1;
            cout<<"enter number to create student(1),employee(2),instructor(3): ";
            switch(ch1)
            {
                case 1://student
                    if(S>4)
                        cout<<"No room for student"<<endl;
                    else
                        {
                            int _grade;
                            create(Sarr,S);
                            cout<<"Enter grade: ";
                            cin>>_grade;
                            Sarr[S].setGrade(_grade);
                            S++;
                        }
                    break;

                case 2://employee
                    if(E>4)
                        cout<<"No room for employee"<<endl;
                    else
                        {
                            int _salary;
                            create(Earr,E);
                            cout<<"Enter Salary: ";
                            cin>>_salary;
                            Earr
                            [E].setSalary(_salary);
                        }
                    break;
                case 3://instructor
                    if(I>4)
                        cout<<"No room for instructor"<<endl;
                    else
                        {
                            int _salary;
                            char _subject[20];
                            create(Iarr,I);
                            cout<<"Enter Salary: ";
                            cin>>_salary;
                            Iarr[I].setSalary(_salary);
                            cout<<"Enter Subject: ";
                            cin>>_subject;
                            Iarr[I].setSubject(_subject);
                            I++;
                        }
                    break;
            }
            break;
        case 2://update
            int ch2;
            cout<<"Enter number to Update student(1),employee(2),instructor(3): ";
            cin>>ch2;
            cout<<"Enter number to update id(1),name(2),age(3)";
            switch(ch2)
            {
                case 1://student
                    int ch3;
                    cout<<",grade(4)";
                    switch(ch3)
                    {

                    }
                    break;
                case 2://employee
                    cout<<",salary(4)";
                    int ch4;
                    switch(ch4)
                    {

                    }
                    break;
                case 3://instructor
                    cout<<",salary(4),subject(5)";
                    int ch5
                    switch(ch5)
                    {

                    }
                    break;
            }

    }
    return 0;
}
