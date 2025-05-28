<?php

require_once( "connect.php" );

$username = htmlspecialchars_decode( $_GET['username'] );
$password = htmlspecialchars_decode( $_GET['password'] );

$query = "SELECT `userId`, `username`, `password` FROM `csc17b`.`users` AS `users` WHERE `username` = '{$username}' AND `password` = '{$password}'";

echo "<p>{$query}</p>";

$result = $connection->query( $query );

if( $result && $result->num_rows > 0 ){
    echo "logged in";
} else {
    echo "denied";
}