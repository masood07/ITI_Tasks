addEventListener("load",function(){
//a-find all images in page by two ways
imgs=document.querySelectorAll("img");
imgs2=document.getElementsByTagName("img");

//b-find all options for city drop down list
 city=this.document.getElementsByName("City")[0];
 opts=city.getElementsByTagName("option");

 //c- find all rows for second table in page
 tb=this.document.getElementsByTagName("table")[1];
 trs=tb.getElementsByTagName("tr");

 //d- find all elements that contain class name "fontBlue"
 fb=this.document.getElementsByClassName("fontBlue");

 //----------------------------------------------------------------
 //a- get first anchor inside the second table then change
 //it's href 

 an=tb.getElementsByTagName("a")[0];
 an.setAttribute("href","training.com");

 //b- find last image and change its borders to : solid pink 2px
    ltimg=imgs[imgs.length-1];
    ltimg.style.cssText=`border: solid pink 2px;`;

//c- create js to find all chechboxes (checked) and alert their value
    ch=this.document.getElementById("UserData").querySelectorAll('input[type="checkbox"]');
    for(i=0;i<ch.length;i++)
    {
        if(ch[i].checked)
        {
            this.alert(ch[i].value);
        }
    }

//----------------------------------------------------------------------







})