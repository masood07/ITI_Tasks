addEventListener("load",function(){
  // selectors 
    prevbtn=document.querySelector("#prev")
    nextbtn=document.querySelector("#next")
    imgobj=document.getElementsByTagName("img")[0]
   counter=1;
    // Events 
    nextbtn.addEventListener("click",function(){
        counter++;
        if(counter==7)
            counter=1
        imgobj.src=`assets/Images/${counter}.png`
    })// next


     prevbtn.addEventListener("click",function(){
        counter--;
        if(counter==0)
            counter=6
        imgobj.src=`assets/Images/${counter}.png`
    })
})//load