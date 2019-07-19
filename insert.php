<?php
$dbHost = 'localhost';
$dbUsername = 'root';
$dbPassword = '';
$dbName = 'temprecord';
$db = new mysqli($dbHost, $dbUsername, $dbPassword, $dbName);
$temp = mysqli_real_escape_string($db,$_REQUEST['temp']);
$insert = "INSERT INTO `temprecord`.`temp` (`id`, `temperature`) VALUES (NULL, '$temp')";
if($db->connect_error){
    die("Mysql connection error" . $db->connect_error);
}
if(mysqli_query($db,$insert)){
    echo "New record created successfully";
}else{
    echo "Error: " . $insert . "<br>" . mysqli_error($db);
}
$db->close();
?>
