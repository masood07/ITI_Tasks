$(document).ready(function(){
    let images = $("#images img");
    let Index = 0;
    images.click(function(){
        var src=$(this).attr("src");
        $("#light-img").attr("src",src);
        $("#container").show();
    });

    $("#next").click(function(){
        Index++;
        if (Index>=images.length){
            Index=0;
        }
        $("#light-img").attr("src",images[Index].src);
    });
    
    $("#prev").click(function () {
        Index--;
        if (Index<0) {
            Index=images.length-1;
        }
        $("#light-img").attr("src",images[Index].src);
    });

    $("#container").click(function (e) {
        if (e.target.id==="container") {
            $(this).hide();
        }
    });
});

