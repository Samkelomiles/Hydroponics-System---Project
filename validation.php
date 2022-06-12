<?php
session_start();

$dbServername = "localhost";
$dbUsername = "root";
$dbPassword = "";
$dbName = "userregistration";

$conn = mysqli_connect($dbServername, $dbUsername, $dbPassword, $dbName);

$name = $_POST['user']; 
$pass = $_POST['password'];


$s="select * from usertable where name = '$name' && password = '$pass' "; 
$result = mysqli_query($conn, $s);
$num = mysqli_num_rows($result);

if($num == 1)
{   
    $_SESSION['username']=$name;
    header('location:index.php');
}
else{

header('location:login.php');

}