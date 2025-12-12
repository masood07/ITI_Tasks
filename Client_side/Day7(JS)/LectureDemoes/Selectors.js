  var mydiv=document.getElementById("example")// example

  //selection using tagName 
  document.getElementsByTagName("p")// return collection 
    document.getElementsByTagName("ul")// return collection containing 1 elm 
      document.getElementsByTagName("ul")[0]// return elm >> ul

      // selection using class
      document.getElementsByClassName("bGrey")// collection
      document.getElementsByClassName("bGrey")[1]// table

      // selection using Name 
      document.getElementsByName("hoppy")// return nodeList >> 3 check boxes 
      document.getElementsByName("hoppy")[0]// first Checkbox 


      // querySelector , QuerySelectorAll 
      document.querySelector("#list2")
     var pobj= document.querySelector("p")
     var psobj= document.querySelectorAll("p")
    tbl=document.getElementsByTagName("table")[0]

    tr1=tbl.getElementsByTagName("tr")[0]
    td2=tr1.getElementsByTagName("td")[1]

    tbl.children[0].children[0].children[1]
    td2.innerText="PD"
      td2.textContent="Ai"
     td2.innerHTML="<a href='http://www.google.com'> Gooogle</a>"
      td2.style.backgroundColor="red"
      td2.style.cssText=`
         font:bold 20px tahoma;
         color:red;
         background-color:lightyellow
      `


        //  tbl.getAttribute("class")//bgrey
        //  tbl.getAttribute("align")//null
        //  tbl.setAttribute("align","center")
         tbl.classList// return classes tbl
        tbl.classList.add("pd")
   
           
  checks=document.getElementsByName("hoppy")

  checks[1].checked
checks[1].checked=true


txt.value

imgs=document.querySelectorAll("img")

for(i=0;i<imgs.length;i++){
   // imgs[i].style.border="6px dashed blue"
imgs[i].addEventListener("mouseover",function(){
    this.style.border="6px dashed blue"
})

}

// Create Elm 
liobj=document.createElement("li")
liobj.innerText="PD Track ITI Mansoura Branch"

liobj.style.backgroundColor="lightgreen"
ul=document.querySelector("ul")
ul.appendChild(liobj)














     




