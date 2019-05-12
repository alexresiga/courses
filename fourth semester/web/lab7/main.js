//POPULATE WITH NEWS ON PAGE LOAD
$(function() {
    getAllNews();
});

function populate(response) {
    $('#newsContainer').empty();
    response = JSON.parse(response);
    for(i = 0; i< response.length; ++i) {
        $('#newsContainer').append('<div class="col-md-6"><div class="myCard"><div class="card-header"><h4>' + response[i][1] +'</h4><i>'+ response[i][4]+ '<br>'+ response[i][2] +'</i></div>' + '<hr><div class="card-body">'+ response[i][3] + '<br><hr>'+ response[i][5] +'</div><br></div></div>');
    }
}

function getAllNews() {
    $.ajax({
        url: "http://localhost/lab7/getNews.php",
        type: "GET"
    }).then(function (response) {
        populate(response);
    }, function (errorData) {
        console.log(errorData);
    });
}


function filterCategory() {
    var category = $('#category').val();
    if (category === '') {    
        return;
    }
    $.ajax({
        url: "http://localhost/lab7/filterCategory.php",
        type: "POST",
        data: JSON.stringify({category: category})
    }).then( function (response) {
        populate(response);
    }, function (errorData) {
        console.log(errorData);
    });
}

function filterDate() {
    var start = $('#start').val();
    var end = $('#end').val();
    if (start  === '' || end  === '') {    
        return;
    }
    $.ajax({
        url: "http://localhost/lab7/filterDate.php",
        type: "POST",
        data: JSON.stringify({start: start, end: end})
    }).then( function(response){
        populate(response);
    }, function (errorData) {
        console.log(errorData);
    });
}

$('#clearButton').on('click', function() {
    $('#start').val("");
    $('#end').val("");
    $('#category').val("");
    getAllNews();
    
})