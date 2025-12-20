$(document).ready(function() {
    $('button').click(function() {
        var task = $('#inp').val();
        if(task) {
            $('#taskList').append('<tr><td>' + task + '</td><td><button class="deleteBtn">Delete</button></td></tr>');
             $('#inp').val('');
        }
    });

    $('#taskList').on('click', '.deleteBtn', function() {
        $(this).closest('tr').remove();
    });
});