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
$sql = "desc department";
if ($conn->query($sql) == TRUE) {
    echo "<br>";
    echo "connected to the table";
} else {
    echo "error";
}
//Displaying the contents
echo "<br>";
//insertion from html
$dname = $_POST['dname'];
$dnumber = $_POST['dnumber'];
$mgrssn = $_POST['mgrssn'];
$mgrstartdate = $_POST['mgrstartdate'];
$sql11 = "insert into department values('$dname',$dnumber,$mgrssn,'$mgrstartdate')";
if ($conn->query($sql11) == TRUE) {
    echo "inserted";
} else {
    echo "error";
}
echo "<br>";
$sql1 = "select * from department";
$result = $conn->query($sql1);
if ($result->num_rows > 0) {
    // output data of each row
    echo "<b>DName Dno Mgrssn mgrstartstate</b><br>";
    while ($row = $result->fetch_assoc()) {
        echo $row["dname"] . " " . $row["dnumber"] . " " . $row["mgrssn"] . " " . $row["mgrstartdate"] . "<br>";
    }
} else {
    echo "empty table";
}
$conn->close();
?>
