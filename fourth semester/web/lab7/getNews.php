<?php 
require_once "config.php";

$sql = "SELECT * from news";
if ($result = $mysqli->query($sql)) {
    $rows = array();
    while($row = $result->fetch_array()) {
        $rows[] = $row;
    }

    echo json_encode($rows);

    $mysqli->close();
} 
?>