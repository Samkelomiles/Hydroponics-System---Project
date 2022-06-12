<!DOCTYPE html>

<html>
<head>
    <meta http-equiv="refresh" content="5" >
    <link rel="stylesheet" type="text/css" href="style.css" media="screen"/>
    <link href='https://unpkg.com/boxicons@2.1.1/css/boxicons.min.css' rel='stylesheet'>

	<title> Hydroponics </title>

</head>

<body>

    <h1>Hydroponic Monitoring System</h1>
                    <a href="logout.php" style="text-align: left">
                        <i class='bx bx-log-out icon' ></i>
                        <span class="text nav-text">Logout&nbsp&nbsp</span>
                    </a>
                    
<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "hydroponics";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);
// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

$sql = "SELECT id, humidity, air_temp, water_temp, water_level, reading_time FROM sensor_log ORDER BY id DESC"; /*select items to display from the sensordata table in the data base*/

echo '<table cellspacing="4" cellpadding="4">
      <tr> 
        <th>ID</th> 
        <th>Date $ Time</th> 
        <th>Humidity &#37;</thh> 
        <th>Air Temp &deg;C</th> 
        <th>Water Temp &deg;C</th> 
        <th>Water level &#37;</th>
      </tr>';
 
if ($result = $conn->query($sql)) {
    while ($row = $result->fetch_assoc()) {
        $row_id = $row["id"];
        $row_reading_time = $row["reading_time"];
        $row_humidity = $row["humidity"];
        $row_aTemp = $row["air_temp"];
        $row_wTemp = $row["water_temp"];
        $row_wlevel = $row["water_level"]; 
        
        //$row_value3 = $row["value3"]; 
        
        // Uncomment to set timezone to - 1 hour (you can change 1 to any number)
       // $row_reading_time = date("Y-m-d H:i:s", strtotime("$row_reading_time - 1 hours"));
      
        // Uncomment to set timezone to + 4 hours (you can change 4 to any number)
        //$row_reading_time = date("Y-m-d H:i:s", strtotime("$row_reading_time + 4 hours"));
      
        echo '<tr> 
                <td>' . $row_id . '</td> 
                <td>' . $row_reading_time . '</td> 
                <td>' . $row_humidity . '</td> 
                <td>' . $row_aTemp . '</td> 
                <td>' . $row_wTemp . '</td> 
                <td>' . $row_wlevel . '</td>
                 
                
              </tr>';
    }
    $result->free();
}

$conn->close();
?> 
</table>

</body>
</html>

	</body>
</html>