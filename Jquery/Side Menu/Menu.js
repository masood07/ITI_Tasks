$(document).ready(function(){
    $("#sideMenu").hover(function(){
        // Mouse enter
        $(this).removeClass("closeSide").addClass("openSide");
        $("#item1, #item2").removeClass("closeitem").addClass("openitem");
    }, function(){
        // Mouse leave
        $(this).removeClass("openSide").addClass("closeSide");
        $("#item1, #item2").removeClass("openitem").addClass("closeitem");
    });
   
    $("#item1").click(function(){
        $("#hello").toggle();
    });
     $("#item2").click(function(){
        $("#bye").toggle();
    });

});