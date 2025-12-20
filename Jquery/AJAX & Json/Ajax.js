$.get("https://jsonplaceholder.typicode.com/posts", function(data) {
    console.log(data);
    for (let i = 0; i < data.length; i++) {
       var div = $("<div></div>").html("<h2>" + data[i].title + "</h2><p>" + data[i].body + "</p>").css({
           border: "1px solid black",
           margin: "10px",
           padding: "10px",
       });
       $("body").append(div);
    }
});