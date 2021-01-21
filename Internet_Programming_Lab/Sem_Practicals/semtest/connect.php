<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "student";

$conn = new mysqli($servername, $username, $password, $dbname);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}
echo "Connected successfully";

$sql = "desc details";
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
$rollno = $_POST['rollno'];

$p_dob = $_POST['dob'];
$dob = date("Y-m-d", strtotime($p_dob));


$cgpa = $_POST['cgpa'];
$sql11 = "insert into details (sname,rollno,dob,cgpa) values('$sname','$rollno','$dob','$cgpa')";
if ($conn->query($sql11) == TRUE) {
    echo "inserted";
} else {
    echo "error";
}
echo "<br>";
$sql1 = "select * from details";
$result = $conn->query($sql1);
if ($result->num_rows > 0) {
    // output data of each row
    echo "<b>Sname      Regno      DOB        CGPA</b><br>";
    while ($row = $result->fetch_assoc()) {
        echo $row["sname"] . " " . $row["rollno"] . " " . $row["dob"] . " " . $row["cgpa"] . "<br>";
    }
} else {
    echo "empty table";
}
$conn->close();
?>
