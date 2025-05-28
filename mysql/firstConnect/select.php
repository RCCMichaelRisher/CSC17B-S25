<?php
//SELECT `userId`, `username`, `password` FROM `csc17b`.`users` AS `users`

require_once( "connect.php");

$result = $connection->query( "SELECT `userId`, `username`, `password` FROM `csc17b`.`users` AS `users`" );

debug( $result );

for( $i = 0; $i < $result->num_rows; $i++ ){
    $row = $result->fetch_assoc();
    echo $row['userId'] . ' u: ' . $row['username'] . ' p: ' . $row['password'] . '<br>';
}

echo "<p>better for</p>";

foreach( $result as $row ){
    echo $row['userId'] . ' u: ' . $row['username'] . ' p: ' . $row['password'] . '<br>';
}

$array = [];
foreach( $result as $row ){
    array_push( $array, $row );
}

debug( $array );