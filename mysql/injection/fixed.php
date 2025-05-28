<?php

require_once( "connect.php" );

$username = htmlspecialchars_decode( $_GET['username'] );
$password = htmlspecialchars_decode( $_GET['password'] );

$query = "SELECT `userId`, `username`, `password` FROM `csc17b`.`users` AS `users` WHERE `username` = ? AND `password` = ?";

echo "<p>{$query}</p>";

//get the statement ready
$statement = $connection->prepare( $query );
//bind the parameters
$statement->bind_param( 'ss', $username, $password );

//runs the query
$statement->execute();

//gets the results of that query
$result = $statement->get_result();

if( $result && $result->num_rows > 0 ){
    echo "logged in";
} else {
    echo "denied";
}