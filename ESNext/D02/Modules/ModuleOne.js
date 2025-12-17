// 1-Create a class Employee with properties: firstName, lastName, age, salary.
// 2-Add a method to class  getFullName() that returns "FirstName LastName".
class Employee{
    constructor(_fname,_lname,_age,_salary){
    this.fname=_fname;
    this.lname=_lname;
    this.age=_age;
    this.salary=_salary;}
    getFullName(){
        return this.fname+this.lname;
    }
}

// 3- out class Export an array departments with some department names (["IT","HR","Finance","Sales"]).
dept=["IT","HR","Finance","Sales"]
export {dept,Employee};