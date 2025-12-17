// 1-Import the Employee class.
import {dept,Employee} from "./ModuleOne.js";

// 2- Create functions to: Add employee(s) to an array.
let emps=[];
function Add_employee(e){
emps.push(e);
}

// 3-Find employee by name.
function find(nam){
    for(i in emps)
    {
        if(emps[i].getFullName()===nam)
        {
            return emp[i];
        }
    }
}
// 4-Increase salary for an employee.
function inc_salary(nam, amount=20){
    for(i in emps)
    {
        if(emps[i].getFullName()===nam)
        {
            emp[i].salary+=amount;
        }
    }

}
export { emps, Add_employee, find, inc_salary, dept, Employee };

