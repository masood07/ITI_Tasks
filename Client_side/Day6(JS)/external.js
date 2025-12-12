var str="welcome to js";
var words=str.split("");
var i=0;
var neww=window.open("","","width=200px,height=200px");
var seti=setInterval(() => {
    neww.document.write(words[i++]);
    if(i==words.length)
    {
        clearInterval(seti);
        neww.close();
    } 
}, 1000);

//-------------------------------------------------------------------

for(var x=0;x<=20;x++)
{
    setTimeout(()=>{
        document.writeln(`<table style="border: 2px solid red;">
        <tr>
            <td style="border: 2px solid red;">${x}</td>
        </tr>
    </table>`);
    },1000);
    
    
}

//---------------------------------------------------------------------------------

var x=0;
setInterval(function(){
    ++x;
    document.title=x;
    document.writeln(`<table style="border: 2px solid red;">
         <tr>
             <td style="border: 2px solid red;">${x}</td>
         </tr>
     </table>`);
     

}, 1000);


//----------------------------------------------------------------------------------

var students = [
  { name: "Ali", age: 20, Crs: "CS" },
  { name: "Sara", age: 22, Crs: "Math" },
  { name: "Omar", age: 19, Crs: "Physics" },
  { name: "Laila", age: 21, Crs: "CS" },
  { name: "Hassan", age: 23, Crs: "Engineering" },
  { name: "Mona", age: 20, Crs: "Biology" },
  { name: "Kareem", age: 24, Crs: "Math" },
  { name: "Noor", age: 18, Crs: "CS" }
];
document.writeln(`<h1 style="border: 2px solid blue; text-align: center;">students</h1>`);
for(i in students)
{
    document.writeln(`<table style="border: 2px solid red; margin:0px auto; width:200px; height:200px;">
          <tr>
              <th style="border: 2px solid black;">${students[i].name}</th>
          </tr>
      </table>`);
}
document.writeln('<hr>');

//------------------------------------------------------------------------------------
var usr=prompt("enter the name u want to know the details");
usr.trim();

if(isNaN(parseInt(usr)))
{
    var flag=false;
    for(i in students)
    {
        if(students[i].name==usr)
        {
            flag=true;
            document.writeln(`<table style="border: 2px solid red; margin:0px auto; width: 200px; height: 200px;">
          <tr>
              <th style="border: 2px solid black;">Name</th>
              <td style="border: 2px solid black;">${students[i].name}</td>
          </tr>
          <tr>
              <th style="border: 2px solid black;">Age</th>
              <td style="border: 2px solid black;">${students[i].age}</td>
          </tr>
          <tr>
              <th style="border: 2px solid black;">Crs</th>
              <td style="border: 2px solid black;">${students[i].Crs}</td>
          </tr>
      </table>`);
        }
    }
    if(flag)
          document.writeln(`<table style="border: 2px solid red; margin:0px auto; width:200px; height:200px;">
          <tr>
              <th style="border: 2px solid black;">no student</th>
              <td style="border: 2px solid black;">0</td>
          </tr>
      </table>`);
}
document.writeln('<hr>');
//---------------------------------------------------------------------------
//Find how many students are in the array(count Students).
 document.writeln(`<table style="border: 2px solid red; margin:0px auto; width: 200px; height: 200px;">
          <tr>
              <th style="border: 2px solid black;">Number Of Students</th>
              <td>${students.length}</td>
            </tr>
            </table>`);

document.writeln('<hr>');
//---------------------------------------------------------------------------
//get all students who are in cs
document.writeln(`<h1 style="border: 2px solid blue; text-align: center;">CS Students</h1>`);
for(i in students)
{
    if(students[i].Crs=='CS')
    {
       document.writeln(`<table style="border: 2px solid red; margin:0px auto; width:200px; height:200px;">
          <tr>
              <th style="border: 2px solid black;">${students[i].name}</th>
          </tr>
      </table>`);   
    }
}
document.writeln('<hr>');
//----------------------------------------------------------------------------
//5-Find youngest student
var age;
var index;
for(i in students)
{
    if(i==0)
        {
            age=students[i].age;
            index=i;
        }
    else{
            if(students[i].age<age)
            {
                age=students[i].age;
                index=i;
            }
        }    
}
document.writeln(`<table style="border: 2px solid red; margin:0px auto; width: 200px; height: 200px;">
          <tr>
              <th style="border: 2px solid black;">Name</th>
              <td style="border: 2px solid black;">${students[i].name}</td>
          </tr>
          <tr>
              <th style="border: 2px solid black;">Age</th>
              <td style="border: 2px solid black;">${students[i].age}</td>
          </tr>
          <tr>
              <th style="border: 2px solid black;">Crs</th>
              <td style="border: 2px solid black;">${students[i].Crs}</td>
          </tr>
      </table>`);

document.writeln('<hr>');
//---------------------------------------------------------------------------------------------------------
//6- Sort Students by age
students.sort(function(a,b){
return a.age-b.age;
})
for(i in students)
    {
            document.writeln(`<table style="border: 2px solid red; margin:0px auto; width: 200px; height: 200px;">
          <tr>
              <th style="border: 2px solid black;">Name</th>
              <td style="border: 2px solid black;">${students[i].name}</td>
          </tr>
          <tr>
              <th style="border: 2px solid black;">Age</th>
              <td style="border: 2px solid black;">${students[i].age}</td>
          </tr>
          <tr>
              <th style="border: 2px solid black;">Crs</th>
              <td style="border: 2px solid black;">${students[i].Crs}</td>
          </tr>
      </table>`);
    }

//------------------------------------------------------------------------------------------------------------
//7-Create a new array with only student names.
var student=[];
for(i in students)
{
    student.push(students[i].name);
}
//----------------------------------------------------------------------
//8-Check if all students are above age  18 and return true or false 
var aboveeight=students.every(function(elem){
    return elem.age>18;
})
//-----------------------------------------------------------------------
//9-return Students Who Have the Same Crs
var subject=[students[0].Crs];
for(var i=1;i<students.length;i++)
{
    if(!subject.includes(students[i].crs))
        subject.push(students[i])
}
document.writeln('<hr>');
//-----------------------------------------------------------------------
//10-Calculate the average age of all students.
var sum=0;
for(i=0;i<students.length;i++)
{
    sum+=students[i].age;
}
document.writeln(`<table style="border: 2px solid red; margin:0px auto; width: 200px; height: 200px;">
          <tr>
              <th style="border: 2px solid black;">avg age Of Students</th>
              <td>${sum/students.length}</td>
            </tr>
            </table>`);
document.writeln('<hr>');
//------------------------------------------------------------------------
//11-Sort and Find top 3 oldest students
students.sort(function(a,b){return b.age-a.age})
for(i=0;i<3;i++)
{
    document.writeln(`<table style="border: 2px solid red; margin:0px auto; width: 200px; height: 200px;">
          <tr>
              <th style="border: 2px solid black;">${students[i].name}</th>
              <td>${students[i].age}</td>
            </tr>
            </table>`);
}
document.writeln('<hr>');
//-------------------------------------------------------------------------
//12-Find if there are students with the same name.
names=[students[0].name];
for(i=1;i<students.length;i++)
{
    if(names.includes(students[i].name))
    {
        names.push(students[i].name);
    }
}
for(j=0;j<names.length;j++){
for(i=0;i<students.length;i++)
{
    if(students[i].name==names[j]){
    document.writeln(`<table style="border: 2px solid red; margin:0px auto; width: 200px; height: 200px;">
          <tr>
              <th style="border: 2px solid black;">Name</th>
              <td style="border: 2px solid black;">${students[i].name}</td>
          </tr>
          <tr>
              <th style="border: 2px solid black;">Age</th>
              <td style="border: 2px solid black;">${students[i].age}</td>
          </tr>
          <tr>
              <th style="border: 2px solid black;">Crs</th>
              <td style="border: 2px solid black;">${students[i].Crs}</td>
          </tr>
      </table>`);}
}}
document.writeln('<hr>');
//--------------------------------------------------------------------------
//13-Reverse the array without using .reverse().
revstd=[];
for(i=students.length-1;i>=0;i--)
{
    revstd.push(students[i].name);
}
//-------------------------------------------------------------------------
//14-Add a new property email for each student in the format: name.toLowerCase+"@iti.com"
students.forEach(function(student) {
  student.email = student.name.toLowerCase() + "@iti.com";
});
for(i in students)
    {
            document.writeln(`<table style="border: 2px solid red; margin:0px auto; width: 200px; height: 200px;">
          <tr>
              <th style="border: 2px solid black;">Name</th>
              <td style="border: 2px solid black;">${students[i].name}</td>
          </tr>
          <tr>
              <th style="border: 2px solid black;">Age</th>
              <td style="border: 2px solid black;">${students[i].age}</td>
          </tr>
          <tr>
              <th style="border: 2px solid black;">Crs</th>
              <td style="border: 2px solid black;">${students[i].Crs}</td>
          </tr>
          <tr>
              <th style="border: 2px solid black;">Email</th>
              <td style="border: 2px solid black;">${students[i].email}</td>
          </tr>
          
      </table>`);
    }