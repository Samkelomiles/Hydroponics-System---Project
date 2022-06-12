<?php
session_start();
header('location:login.php');

$dbServername = "localhost";
$dbUsername = "root";
$dbPassword = "";
$dbName = "userregistration";

$conn = mysqli_connect($dbServername, $dbUsername, $dbPassword, $dbName);

$name = $_POST['user']; 
$pass = $_POST['password'];


$s="select * from usertable where name = '$name' "; 
$result = mysqli_query($conn, $s);
$num = mysqli_num_rows($result);

if($num == 1)
{
    echo" Usename Already Taken";
}
else{

$reg= "insert into usertable(name, password) values ('$name', '$pass')"; 
mysqli_query($conn, $reg); 
echo" Registration Successful";

}