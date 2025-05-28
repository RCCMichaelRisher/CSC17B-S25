<?php 

require_once( "connectPDO.php" );

$result = $connection->query( "SELECT `userId`, `username`, `password` FROM `csc17b`.`users` AS `users`" );

debug( $result );

while( $row = $result->fetch() ){
    echo $row['userId'] . ' u: ' . $row['username'] . ' p: ' . $row['password'] . '<br>';
}