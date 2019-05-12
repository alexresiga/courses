<?php

session_start();
 

if(!isset($_SESSION["loggedin"]) || $_SESSION["loggedin"] !== true){
    header("location: login.php");
    exit;
}

require_once "config.php";
 

$title = $producer = $content = $date = $category = "";
$title_err = $producer_err = $content_err = $date_err = $category_err = "";

if($_SERVER["REQUEST_METHOD"] == "POST"){
    
    

    // Validate title
    $input_title = trim($_POST["title"]);
    if(empty($input_title)){
        $title_err = "Please enter a title.";     
    } else{
        $title = $input_title;
    }

    // Validate producer
    $input_producer = trim($_POST["producer"]);
    if(empty($input_producer)){
        $producer_err = "Please enter a producer.";     
    } else{
        $producer = $input_producer;
    }

    // Validate date
    $input_date = trim($_POST["date"]);
    if(empty($input_date)){
        $date_err = "Please enter a date.";     
    } else{
        $date = $input_date;
    }

    // Validate content
    $input_content = trim($_POST["content"]);
    if(empty($input_content)){
        $content_err = "Please enter some content.";     
    } else{
        $content = $input_content;
    }

    // Validate category
    $input_category = trim($_POST["category"]);
    if(empty($input_category)){
        $category_err = "Please enter a category.";     
    } else{
        $category = $input_category;
    }

    if( empty($title_err) && empty($producer_err) && empty($content_err) && empty($date_err) && empty($category_err) ){

        $sql = "INSERT INTO news (title, producer, content, date, category) VALUES (?, ?, ?, ?, ?)";
 
        if($stmt = $mysqli->prepare($sql)){

            $stmt->bind_param("sssss", $param_title, $param_producer, $param_content, $param_date, $param_category);
            
            // Set parameters
            $param_title = $title;
            $param_producer = $producer;
            $param_content = $content;
            $param_date  = $date;
            $param_category = $category;
            

            if($stmt->execute()){
                header("location: admin.php");
                exit();
            } else{
                echo "Something went wrong. Please try again later.";
            }
        }
        $stmt->close();
    }
    $mysqli->close();
}
?>
 
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Create Record</title>
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.css">
    <style type="text/css">
        .wrapper{
            width: 500px;
            margin: 0 auto;
        }
    </style>
</head>
<body>
    <div class="wrapper">
        <div class="container-fluid">
            <div class="row">
                <div class="col-md-12">
                    <div class="page-header">
                        <h2>Create Record</h2>
                    </div>
                    
                    <form action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?>" method="post">
                        <div class="form-group <?php echo (!empty($title_err)) ? 'has-error' : ''; ?>">
                            <label>Title</label>
                            <input type="text" name="title" class="form-control" value="<?php echo $title; ?>">
                            <span class="help-block"><?php echo $title_err;?></span>
                        </div>
                        <div class=" form-group <?php echo (!empty($producer_err)) ? 'has-error' : ''; ?>">
                            <label>Producer</label>
                            <input type="text" name="producer" class="form-control" value="<?php echo $producer; ?>">
                            <span class="help-block"><?php echo $producer_err;?></span>
                        </div>
                        <div class="form-group <?php echo (!empty($content_err)) ? 'has-error' : ''; ?>">
                            <label>Content</label>
                            <textarea name="content" class="form-control"><?php echo $content; ?></textarea>
                            <span class="help-block"><?php echo $content_err;?></span>
                        </div>
                        <div class="form-group <?php echo (!empty($date_err)) ? 'has-error' : ''; ?>"">
                            <label>Date</label>
                            <input type="date" name="date" class="form-control" value="<?php echo $date; ?>">
                            <span class="help-block"><?php echo $date_err;?></span>
                        </div>
                        <div class="form-group <?php echo (!empty($category_err)) ? 'has-error' : ''; ?>">
                            <label>Category</label>
                            <input type="text" name="category" class="form-control" value="<?php echo $category; ?>">
                            <span class="help-block"><?php echo $category_err;?></span>
                        </div>
                        <input type="submit" class="btn btn-primary" value="Submit">
                        <a href="admin.php" class="btn btn-default">Cancel</a>
                    </form>
                </div>
            </div>        
        </div>
    </div>
</body>
</html>