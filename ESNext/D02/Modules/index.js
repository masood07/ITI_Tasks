// 1- Import everything from both modules.
import * as mymod from "./ModuleTwo.js";
import {dept,Employee} from "./ModuleOne.js";

// 2-Create a few employees, store them in an array.
emp1 = new Employee("tarek", "masood", 30, 5000);
emp2 = new Employee("osama", "elazab", 28, 5500);
mymod.Add_employee(emp1);
mymod.Add_employee(emp2);
mymod.inc_salary("tarek masood", 500);
// 3-Print all employees’ info on Document not console.
mymod.emps.forEach(emp => {
    console.log(`Full Name: ${emp.getFullName()}`);
    console.log(`First Name: ${emp.fname}`);
    console.log(`Last Name: ${emp.lname}`);
    console.log(`Age: ${emp.age}`);
    console.log(`Salary: ${emp.salary.toLocaleString()}`);
    console.log("----------------------------");
});