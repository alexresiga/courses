<?php 
if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    require_once "config.php";

    $requestBody = file_get_contents('php://input');
    $requestBodyObj = json_decode($requestBody, true);
    $category = '%'.$requestBodyObj["category"].'%';
    

    $sql = "SELECT * FROM news WHERE category like ?";

    if ($stmt = $mysqli->prepare($sql)) {
        
        $stmt->bind_param("s", $category);
        

        if ($stmt->execute()) {
            

            $result = $stmt->bind_result($id, $title, $producer, $content, $date, $category);
            $rows = array();
            $i = 0;
            while($val = $stmt->fetch()) {
                $rows[$i][0] = $id;
                $rows[$i][1] = $title;
                $rows[$i][2] = $producer;
                $rows[$i][3] = $content;
                $rows[$i][4] = $date;
                $rows[$i][5] = $category;
                $i++;
            }
            echo json_encode($rows);
        }
        $stmt->close();
    }
    $mysqli->close();
}

?>
