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

addEventListener("load",function(){
    tb=document.getElementsByTagName('table')[0];
    for(i in students)
    {
        tr=document.createElement('tr');
        td1=document.createElement('td');
        td2=document.createElement('td');
        td3=document.createElement('td');
        tr.appendChild(td1);
        tr.appendChild(td2);
        tr.appendChild(td3);
        tb.appendChild(tr);
        td1.innerText=students[i].name;
        td2.innerText=students[i].age;
        td3.innerText=students[i].Crs;   
    }
    //----------------------------------------------------------
    usr=document.getElementById('username');
    tb1=document.getElementsByTagName('table')[1];
    tds=tb1.getElementsByTagName('tr')[1].getElementsByTagName('td');
    
    //--------------------------------------------------------------
    //search for student
    search=document.getElementById('search');
    non=document.getElementById('non');
    search.addEventListener('click',function(){
    uname=usr.value;
    flag=false;
    for(i in students)
    {
      if(uname===students[i].name)
      {
        flag=true;
        tds[0].innerText=students[i].name;
        tds[1].innerText=students[i].age;
        tds[2].innerText=students[i].Crs;
      }
    }
    if(!flag)
    {
      
      non.innerText='student not exist';
      non.style.color='red';
    }

    })
     //------------------------------------------------------------------------
     //sort
    dropd=document.getElementById('dropdown');
    sortbut=document.getElementById('sort');
    
    sortbut.addEventListener('click',function(){
      if(dropd.value==='name')
      {
        students.sort(function(a,b){return a.name>b.name});
      }
      else if(dropd.value==='age')
      {
        students.sort(function(a,b){return a.age-b.age});
      }

      tb2=document.getElementsByTagName('table')[2];
      tr=document.createElement('tr');
        td1=document.createElement('td');
        td2=document.createElement('td');
        td3=document.createElement('td');
        tr.appendChild(td1);
        tr.appendChild(td2);
        tr.appendChild(td3);
        tb2.appendChild(tr);
    for(i in students)
    {
        tr=document.createElement('tr');
        td1=document.createElement('td');
        td2=document.createElement('td');
        td3=document.createElement('td');
        tr.appendChild(td1);
        tr.appendChild(td2);
        tr.appendChild(td3);
        tb2.appendChild(tr);
        td1.innerText=students[i].name;
        td2.innerText=students[i].age;
        td3.innerText=students[i].Crs;   
    }

    })

    
})