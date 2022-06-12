<?php
$dbServername = "localhost";
$dbUsername = "root";
$dbPassword = "";
$dbName = "hydroponics";

$conn = mysqli_connect($dbServername, $dbUsername, $dbPassword, $dbName);

$api_key_value = "hmssystem";

$api_key = $humidity = $air_temp = $water_temp = $water_level = "";

//gettin data from ESP
if ($_SERVER["REQUEST_METHOD"] == "POST")
{
    $api_key = test_input($_POST["api_key"]);

    if($api_key == $api_key_value)
     {

        $humidity = test_input($_POST["humidity"]);
        $air_temp = test_input($_POST["air_temp"]);
        $water_temp = test_input($_POST["water_temp"]);
        $water_level = test_input($_POST["water_level"]);
        
        
        // Create connection
        $conn = new mysqli($dbServername, $dbUsername, $dbPassword, $dbName);
        // Check connection
        if ($conn->connect_error) {
            die("Connection failed: " . $conn->connect_error);
        } 
        
        $sql = "INSERT INTO sensor_log (humidity, air_temp, water_temp, water_level)
        VALUES ('" . $humidity . "', '" . $air_temp . "', '" . $water_temp . "', '" . $water_level . "')";
        
        if ($conn->query($sql) === TRUE) {
            echo "New record created successfully";
        } 
        else {
            echo "Error: " . $sql . "<br>" . $conn->error;
        }
    
        $conn->close();
    }
    else {
        echo "Wrong API Key provided.";
    }


}
else {
  
    echo "No data posted with HTTP POST.";
}

function test_input($data) {
    $data = trim($data);
    $data = stripslashes($data);
    $data = htmlspecialchars($data);
    return $data;
}
