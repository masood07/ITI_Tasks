var students = [
  {id:0 ,name: "Ali", age: 20, Crs: "CS" },
  {id:1 ,name: "Sara", age: 22, Crs: "Math" },
  {id:2 ,name: "Omar", age: 19, Crs: "Physics" },
  {id:3 ,name: "Laila", age: 21, Crs: "CS" },
  {id:4 ,name: "Hassan", age: 23, Crs: "Engineering" },
  {id:5 ,name: "Mona", age: 20, Crs: "Biology" },
  {id:6 ,name: "Kareem", age: 24, Crs: "Math" },
  {id:7 ,name: "Noor", age: 18, Crs: "CS" }
];
addEventListener("load",function(){
img=this.document.createElement('img');
prev=this.document.createElement('input');
after=this.document.createElement('input');
slideshow=this.document.createElement('input');
stop=this.document.createElement('input');
this.document.body.appendChild(img);
this.document.body.appendChild(prev);
this.document.body.appendChild(after);
this.document.body.appendChild(slideshow);
this.document.body.appendChild(stop);

img.style.cssText=`width:200px; height:200px; display:block`;

prev.type="button";
after.type="button";
slideshow.type="button";
stop.type="button";
prev.value="prev";
after.value="after";
slideshow.value="slideshow";
stop.value="stop";
img.src="Images/1.png";
var count=1;
prev.addEventListener("click",function(){
    count--;
    if(count<=0)
        count=6;
    img.src=`Images/${count}.png`;
})

after.addEventListener("click",function(){
    count++;
    if(count==7)
        count=1;
    img.src=`Images/${count}.png`;
})

slideshow.addEventListener("click",function(){
    interval=setInterval(function(){
        count++;
        if(count==7)
            count=1;
        img.src=`Images/${count}.png`;
    }, 1000);
    
})

stop.addEventListener("click",function(){
    clearInterval(interval);
})


//-------------------------------------------------------------------------------------------------------------
sele=this.document.getElementsByTagName("select")[0];
tds=this.document.getElementsByTagName("table")[0].getElementsByTagName("tr")[1].getElementsByTagName("td");
sele.addEventListener("change",function(){
    id=sele.value;
    tds[0].innerText=students[id].id;
    tds[1].innerText=students[id].name;
    tds[2].innerText=students[id].age;
    tds[3].innerText=students[id].crs;

})

})
//--------------------------------------------------------------------------------------------------------------
for(i in students)
{
    if(i%2)//odd
    console.log(`%c id=${students[i].id} name=${students[i].name} age=${students[i].age} crs=${students[i].crs}`,'color:red');
    else//even
    console.log(`%c id=${students[i].id} name=${students[i].name} age=${students[i].age} crs=${students[i].crs}`,'color:blue');

}
//-----------------------------------------------------------------------------------------------------------------