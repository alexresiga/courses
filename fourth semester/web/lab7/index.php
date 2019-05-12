<!DOCTYPE html>
<html>
<head>
<title>News</title>
<script src="http://code.jquery.com/jquery-3.3.1.min.js" integrity="sha256-FgpCb/KJQlLNfOu91ta32o/NMZxltwRo8QtmkMRdAu8=" crossorigin="anonymous"></script>
<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.css">
<link rel="stylesheet" href="style.css">
</head>
<body>
<div class="container-fluid">
    <div class="row">
        <h1 style="flex: 1 1 auto;text-align: center;">News Page</h1>
        <a href="login.php" class="btn btn-success pull-right">Edit articles</a>
    </div>
</div>
<div class="container-fluid">
    <div class="row">
        <div class="col-md-4">
            <form action="javascript: filterCategory();">
                <div class="form-group">
                    <label for="category">Filter by category </label>
                    <input type="text" name="category" id="category"/>
                    <input class="btn btn-outline-secondary" type="submit" value="Submit" id="butttonCategory" />
                </div>   
            </form>
            
        </div>
        <div class="col-md-6">
                <form  action="javascript: filterDate();">
                    <div class="form-group">
                            <label for="category">Filter by date </label>
                            <input type="date" name="start" id="start"/>
                            <input type="date" name="end" id="end"/>
                            <input class="btn btn-outline-secondary" type="submit" value="Submit" id="butttonDate" />
                    </div>       
                </form>
        </div>
        <div class="col-sm-2">
            <div id="clearButtonContainer">
                <input class="btn btn-outline-secondary pull-right" type="button" value="Clear" id="clearButton"/>
            </div>
        </div>
</div>
</div>
<div class="container-fluid">
    <div id="newsContainer" class="row"></div>
</div>
<script src="main.js"></script>
</body>
</html>