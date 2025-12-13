addEventListener('load',()=>{
    let carts=[];
    if(JSON.parse(localStorage.getItem("cart")).length>0){
        carts=JSON.parse(localStorage.getItem("cart"));
    }
    else{
        let p=document.createElement('p');
        p.innerText="No items in cart";
        document.body.appendChild(p);
        p.style.cssText="font-size:20px; font-weight:bolder; text-align:center; margin-top:20px;";
    }
   
    let container=document.createElement('div');
    container.id="container";
    document.body.appendChild(container);
    let tot=document.createElement('p');
    document.body.appendChild(tot);
    //calculate total
    let total=0;
    if(carts.length>0){
    for(let i in carts){
        total+=carts[i].price;
    }
    tot.innerText='Total: $'+total;
    tot.id='total';
    tot.style.cssText="font-size:20px; font-weight:bolder; text-align:center; margin-top:20px;";
 }
for(let i=0; i < carts.length; i++){
    let itemId = carts[i].id;        
    let itemPrice = carts[i].price;
    let product=document.createElement('div');
    let img=document.createElement('img');
    img.src=carts[i].image;
    let p1=document.createElement('p');
    p1.innerText=carts[i].title;
    p1.style.fontWeight='bolder';
    p1.style.fontSize='17px';
    let p2=document.createElement('p');
    p2.innerText='$'+carts[i].price+' x';
    p2.style.fontSize='16px';
    p2.className='price';
    let rem=document.createElement('input');
    rem.type='submit';
    rem.value='Remove';
    let neg=document.createElement('input');
    neg.type='submit';
    neg.value='-';
    neg.className ='neg';
    let counter=document.createElement('span');
    counter.className='counter';
    counter.innerText=carts[i].count;
    let pos=document.createElement('input');
    pos.type='submit';
    pos.value='+';
    pos.className ='pos';
    let div2=document.createElement('div');
    let sub=document.createElement('p');
    sub.innerText='Subtotal: $'+counter.innerText*carts[i].price;
    sub.className='sub';
    div2.appendChild(p2);
    div2.appendChild(neg);
    div2.appendChild(counter);
    div2.appendChild(pos);
    rem.className ='but';
    neg.addEventListener('click',()=>{
        if(carts[i].count>1){
            carts[i].count--;
            counter.innerText=carts[i].count;
            //after updating count update local storage
            window.localStorage.setItem("cart",JSON.stringify(carts));
            sub.innerText='Subtotal: $'+counter.innerText*itemPrice;
            total-=itemPrice;
            tot.innerText='Total: $'+total;
        }});
    pos.addEventListener('click',()=>{
        carts[i].count++;
        counter.innerText=carts[i].count;
        //after updating count update local storage
        window.localStorage.setItem("cart",JSON.stringify(carts));
        sub.innerText='Subtotal: $'+parseInt(counter.innerText)*itemPrice;
        total+=itemPrice;
        tot.innerText='Total: $'+total;
        });
    rem.addEventListener('click',(e)=>{
        total-=parseInt(counter.innerText)*itemPrice;
        e.target.parentElement.remove();
        tot.innerText='Total: $'+total;
        RemFromLocal(itemId);
    });

    product.appendChild(img);
    product.appendChild(p1);
    product.appendChild(div2);
    product.appendChild(sub);
    product.appendChild(rem);
    container.appendChild(product); 
}
 function RemFromLocal(id){
    carts = carts.filter((elm)=>{return elm.id!=id}); 
    window.localStorage.setItem("cart",JSON.stringify(carts));
 }
      
});