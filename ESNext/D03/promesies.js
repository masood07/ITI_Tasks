addEventListener('load', () => {
    const products = [
  { id: 1, name: "Laptop", price: 30000, stock: 5 },
  { id: 2, name: "Phone", price: 15000, stock: 0 },
  { id: 3, name: "Headphone", price: 2000, stock: 10 },
  { id: 4, name: "Keyboard", price: 1000, stock: 3 }
];
// Suppose you have this array of objects 
// use promises to do these requirments 
// 1- Get all products (simulate API) ... use promise + setTimeout to return products after 2 seconds 
function getProducts() {
    return new Promise((res) => {
        setTimeout(() => {
            res(products);
        },2000);
    });
}
//2- Filter available products (stock > 0) using then 
getProducts().then((allProducts) => {
    const availableProducts = allProducts.filter((product)=>product.stock>0);
    console.log("Available Products:",availableProducts);});

//3- Calculate total price
getProducts().then((allProducts) => {
    const totalPrice = allProducts.reduce((total,product)=>total+product.price,0);
    console.log("Total Price of All Products:",totalPrice);
});

//4- Apply discount 10% ( reject if total < 5000 )
getProducts().then((allProducts) => {
    const totalPrice=allProducts.reduce((acc, product)=>acc+product.price,0);
    if (totalPrice<5000) {
        return Promise.reject("Total price is less than 5000, cannot apply discount.");
    }
    const discountedPrice=totalPrice*0.9;
    console.log("Discounted Price (10% off):",discountedPrice);
}).catch((error) => {
    console.log(error);});

//===============================================================================================
// You are given two arrays: one represents users and the other represents posts.
// Each post belongs to a specific user.
const users = [
  { id: 1, name: "Ali" },
  { id: 2, name: "Sara" }
];

const posts = [
  { id: 1, userId: 1, title: "JS Basics" },
  { id: 2, userId: 1, title: "Async Await" },
  { id: 3, userId: 2, title: "HTML Tips" }
];

// Your task is to write an async function that simulates fetching data from an API using async / await.
//1- Create an async function called showUserPost(userId, postId).
// 1- Create an async function called showUserPost(userId, postId).

// 2- The function should:

// - Accept userId and postId as parameters.

// - Simulate an API delay using await and setTimeout.

// - Search for the user with the given userId.

// - If the user does not exist, throw an error.

// - Search for the post with the given postId that belongs to the given user.

// 3- If the post does not exist or does not belong to the user, throw an error.

// - If both user and post are found:

// Print the user name.

// Print the post title.
async function showUserPost(userId,postId) {
    await new Promise((resolve)=>setTimeout(resolve, 2000));
    const user=users.find(u=>u.id===userId);
    if(!user){
        throw new Error("User not found");
    }
    const post=posts.find(p=>p.id===postId && p.userId === userId);
    if(!post){
        throw new Error("Post not found");
    }
    console.log("User Name:",user.name);
    console.log("Post Title:",post.title);
}

showUserPost(3,2)
    .then(()=>console.log("Done"))
    .catch((error)=>console.log(error.message));

showUserPost(1,1)
    .then(()=>console.log("Done"))
    .catch((error)=>console.log(error.message));
});