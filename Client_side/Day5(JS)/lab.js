// Write a JavaScript code to remove duplicate items from an array. 

var arr=[3,1,2,4,3,5,1];
        var arrnew=[];
        arrnew.push(arr[0]);
        for(i=1;i<arr.length;i++)
        {
            flag=true;
            for(j=0;j<arrnew.length;j++)
            {
                if(arr[i]==arrnew[j])
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
            {
                arrnew.push(arr[i]);
            }
        }
//-----------------------------------------------------------------

// Sort them ascending 

arrnew.sort(
    function(a,b){
        return a-b;
    }
)
//-----------------------------------------------------------------
// Filter numbers larger than 50 
//a 
var arr2=[60,20,50,80,90];
var res=arr2.filter(
    function(elem)
    {
        if(elem>50)
            return true;
    }
)
//b
var hand_made_res=[];
for(i in arr2)
{
    if(arr2[i]>50)
        hand_made_res.push(arr2[i]);
}

//-------------------------------------------------------------------
//Display Max and Min Numbers 
//a- User defined function
var max=arr2[0];
var min=arr2[0]; 
for(i in arr2)
{
    if(arr2[i]>max)
        max=arr2[i];
    if(arr2[i]<min)
        min=arr2[i];
}

//using spread operator
max1=Math.max(...arr2);
min1=Math.min(...arr2);

//using sort
arr2.sort()
max3=arr2[arr2.length-1];
min3=arr2[0];


//---------------------------------------------------------------------
//Write a JavaScript function to Compute the sum and product of an array of integers  (Use eval)  

function sumall(arr3)
{
    summation=eval(arr3.join('+'));
    product=eval(arr3.join('*'));
    console.log(summation+' '+product);
}
sumall([3,1,4,5,2])

//--------------------------------------
//args
function sumallarg()
{
    var sum=0;
    var pro=1;
    for(i=0;i<arguments.length;i++){
        sum+=arguments[i];
        pro*=arguments[i];
    }
    console.log(sum+' '+pro);
}
//------------------------------------------
var user=prompt("enter string");
var newstr = "";
var word;
function capital(user){
if(isNaN(parseInt()))
{
    var words=user.split(' ');
    for(var i=0;i<words.length;i++)
    {
        word = words[i][0].toUpperCase();
        word+=words[i].slice(1);
        newstr+=word;
        newstr+=' ';
    }
    newstr.trim();
    return newstr;
}
}
capital(user);

//---------------------------------------------
var usr=prompt("enter string");
var newstr='';
var words=usr.split(' ');
newstr=words[0];
for(i=1;i<words.length;i++)
{
    if(words[i].length>newstr.length)
        newstr=words[i];

}
