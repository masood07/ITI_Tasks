#include <iostream>
#include <cstring>
using namespace std;
class employee
{
    int id;
    char* name=new char[50];
    int age;
    int salary;

    public:
        void set_id(int _id)
        {
            if(_id>0)
                id=_id;
            else
                id=0;
        }
        void set_name(char *_name)
        {
            if(_name==NULL||strlen(_name)==0)
                strcpy(name, "Unknown");
            else
                strcpy(name, _name);
        }
        void set_age(int _age)
        {
            if(_age<=60&&_age>=18)
                age=_age;
            else
                age=30;
        }
        void set_salary(int _salary)
        {
            if(_salary>6000)
            salary=_salary;
            else
            salary= 6000;
        }
        int get_id()
        {
            return id;
        }
        char* get_name()
        {
            return name;
        }
        int get_age()
        {
            return age;
        }
        int get_salary()
        {
            return salary;
        }
        //ctors
        employee(int _id,char* _name)
        {
            set_id(_id);
            set_name(_name);
            set_age(30);
            set_salary(6000);
            cout << "Employee #" << _id << " created (2-param constructor)" << endl;
        }
        employee(int _id,char* _name,int _age)
        {
            set_id(_id);
            set_name(_name);
            set_age(_age);
            set_salary(6000);
        cout << "Employee #" << _id << " created (3-param constructor)" << endl;
        }
        employee(int _id)
        {
            set_id(_id);
            set_name("");
            set_age(30);
            set_salary(6000);
            cout << "Employee #" << _id << " created (unparam constructor)" << endl;
        }
        employee(int _id,char* _name,int _age,int _salary)
        {
            set_id(_id);
            set_name(_name);
            set_age(_age);
            set_salary(_salary);
            cout << "Employee #" << _id << " created (4-param constructor)" << endl;
        }
        //desructor
        ~employee()
        {
            cout << "Employee #" << id << " destroyed" << endl;
            delete[] name;
        }
};
void myfun_byValue(employee e)//by value--> will call copy constructor and destructor when finished
{
    cout<<endl<<"id:"<<e.get_id()<<endl<<"name:"<<e.get_name()<<endl<<"age:"<<e.get_age()<<endl<<"salary:"<<e.get_salary()<<endl;
}
void myfun_byReference(employee& e)//by refrence--> alias to the object in main
{
    cout<<endl<<"id:"<<e.get_id()<<endl<<"name:"<<e.get_name()<<endl<<"age:"<<e.get_age()<<endl<<"salary:"<<e.get_salary()<<endl;
}
void myfun_byPointer(employee* e)//by value-->point to the object
{
    cout<<endl<<"id:"<<e->get_id()<<endl<<"name:"<<e->get_name()<<endl<<"age:"<<e->get_age()<<endl<<"salary:"<<e->get_salary()<<endl;
}

int main()
{
    employee emp1(101, (char*)"");
    employee emp2(102, (char*)"Bob Smith", 28);
    employee emp3(103, (char*)"Charlie Brown", 35, 8500);

    cout<<"\n-----------------\n";
    cout << "calling function with pass by value..." << endl;
    cout << "-->will create a copy of the object" << endl;
    myfun_byValue(emp1);
    cout << "\nFunction ended. Copy is destroyed here" << endl;
    cout<<"\n-----------------\n";

    cout << "calling function with pass by reference" << endl;
    cout << "No copy made working with original object" << endl;
    myfun_byReference(emp2);
    cout << "-->Function ended. No destructor called!" << endl;
    cout<<"\n-----------------\n";

    cout << "Calling function with pass by pointer" << endl;
    cout << "Passing address of object" << endl;
    myfun_byPointer(&emp3);
    cout << "Function ended. No destructor called" << endl;
    cout<<"\n-----------------\n";
    return 0;
}
