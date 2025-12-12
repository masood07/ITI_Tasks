addEventListener("load",function(){
    function createFun(){
    alert("Elm Created")
}

// saveBtn.onclick=saveFun;
// function saveFun(){
//     alert("Data Saved")
// }

saveBtn.onclick=function (){
    alert("Data Saved")
}


// DeleteBtn.onclick=deleteFun;

// function deleteFun(){
//     document.title="Elm Deleted"
// }

DeleteBtn.onclick=function(){
    document.body.style.backgroundColor="magenta";
}


// DeleteBtn.addEventListener("click",deleteFun)
DeleteBtn.addEventListener("click",function(){
     document.title="Elm Deleted"
})


example.addEventListener("mouseover",function(e){
     // console.log("mouseover");
      //console.log(this);
     // console.log(e)
    //   console.log(e.type)
    //   console.log(e.target)
    //   console.log(e.x)

})// mouseover

example.addEventListener("mousemove",function(e){
      //console.log("mousemove")
    this.innerHTML="<h1 align='center'> <font color='red'>"+e.x+" : "+e.y+"</font></h1>"

})// mousemove


example.addEventListener("mouseout",function(){
    //  console.log("mouseout")

})// mouseout

//keydown 
// txt.addEventListener("keydown",function(){
//    resultlbl.innerText=this.value

// })


//keyup 

// txt.addEventListener("keyup",function(){
//    resultlbl.innerText=this.value;
//    resultlbl.style.cssText=`
//    color:red;
//    background-color:cyan;
//    font:bold 20px teko
//    `

// })

//keypress

txt.addEventListener("keypress",function(){
   resultlbl.innerText=this.value;
   resultlbl.style.cssText=`
   color:white;
   background-color:gray;
   font:bold 20px teko
   `

})



//example.innerText="PD"
//example.innerHTML="<h1 align='center'>PD</h1>"
//example.textContent="iti";



myselect.addEventListener("change",function(){
resultlbl.innerText=this.value;
   resultlbl.style.cssText=`
   color:red;
   background-color:gray;
   font:bold 25px agness
   `

})

})//load




