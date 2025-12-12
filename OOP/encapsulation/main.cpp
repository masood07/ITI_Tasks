#include <iostream>

using namespace std;
class emp{
private:
    int id;
    char* name;
    int age;
    int salary;
public:
    int get_id()
    {
        return id;
    }
    void set_id(int emp_id)
    {
        id=emp_id;
    }
    char* get_name()
    {
        return name;
    }
    void set_name(char* emp_name)
    {
         name=emp_name;
    }
    int get_age()
    {
        return age;
    }
    void set_age(int emp_age)
    {
        age=emp_age;
    }
    int get_salary()
    {
        return salary;
    }
    void set_salary(int emp_salary)
    {
        salary=emp_salary;
    }
    void print()
    {

        cout<<"id= "<<id<<"\nname= "<<name<<"\nage= "<<age<<"\nsalary="<<salary<<endl;
    }
};

void print_emp(emp e)
{
    cout<<"printing from standalone function\n";
    cout<<"id= "<<e.get_id()<<"\nname= "<<e.get_name()<<"\nage= "<<e.get_age()<<"\nsalary="<<e.get_salary()<<endl;
}
int main()
{
    emp e1;
    cout<<"enter id:"<<endl;
    e1.set_id(1);
    cout<<"enter name"<<endl;
    e1.set_name("tarek");
    cout<<"enter age"<<endl;
    e1.set_age(22);
    cout<<"enter salary"<<endl;
    e1.set_salary(1000);

    e1.print();
    cout<<"-----------------";
    print_emp(e1);
    return 0;
}
