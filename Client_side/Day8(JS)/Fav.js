addEventListener('load',()=>{
    let favs=[];

    if(JSON.parse(localStorage.getItem("fav")).length>0){
        favs=JSON.parse(localStorage.getItem("fav"));
    }
    else{
        let p=document.createElement('p');
        p.innerText="No favourites added";
        document.body.appendChild(p);
        p.style.cssText="font-size:20px; font-weight:bolder; text-align:center; margin-top:20px;";
    }

    let container=document.createElement('div');
    container.id="container";
    document.body.appendChild(container);

for(let i=0; i < favs.length; i++){
    let itemId = favs[i].id;     
       
    let product=document.createElement('div');
    let img=document.createElement('img');
    img.src=favs[i].image;
    let p1=document.createElement('p');
    p1.innerText=favs[i].title;
    p1.style.fontWeight='bolder';
    p1.style.fontSize='17px';
    let p2=document.createElement('p');
    p2.innerText=favs[i].price+'$';
    p2.style.fontSize='16px';
    let rem=document.createElement('input');
    rem.type='submit';
    rem.value='Remove'
    rem.className ='but';

    rem.addEventListener('click',(e)=>{
        e.target.parentElement.remove();
        RemFromLocal(itemId);
    });

    product.appendChild(img);
    product.appendChild(p1);
    product.appendChild(p2);
    product.appendChild(rem);
    container.appendChild(product);
    
}
   function RemFromLocal(id){
    favs = favs.filter((elm)=>{return elm.id!=id}); 
    window.localStorage.setItem("fav",JSON.stringify(favs));
 }     
});