<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "testdb";
// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);
// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}
echo "Connected successfully";
//displaying the contents
$sql = "desc department1";
if ($conn->query($sql) == TRUE) {
    echo "<br>";
    echo "connected to the table";
} else {
    echo "error";
}
//Displaying the contents
echo "<br>";
//insertion from html
$sname = $_POST['sname'];
$regno = $_POST['regno'];
$m1 = $_POST['m1'];
$m2 = $_POST['m2'];
$sql11 = "insert into department1 values('$sname',$regno,$m1,$m2)";
if ($conn->query($sql11) == TRUE) {
    echo "inserted";
} else {
    echo "error";
}
echo "<br>";
$sql1 = "select * from department1";
$result = $conn->query($sql1);
if ($result->num_rows > 0) {
    // output data of each row
    echo "<b>Sname Regno M1 M2</b><br>";
    while ($row = $result->fetch_assoc()) {
        echo $row["sname"] . " " . $row["regno"] . " " . $row["m1"] . " " . $row["m2"] . "<br>";
    }
} else {
    echo "empty table";
}
$conn->close();
?>
