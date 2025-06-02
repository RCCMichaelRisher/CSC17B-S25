<?php

include( 'includes/header.php' );

require_once( "connect.php" );


$q = "SELECT `artists`.`artist_id`, CONCAT_WS( ' ', `first_name`, `middle_name`, `last_name` ) as artist, `prints`.`print_name`, `prints`.`price`,  `prints`.`description`, `prints`.`print_id`
 FROM `shop`.`artists` AS `artists`, `shop`.`prints` AS `prints` WHERE `artists`.`artist_id` = `prints`.`artist_id`";

 if( isset( $_GET['aid'] ) && filter_var( $_GET['aid'], FILTER_VALIDATE_INT, array( 'min_range' => 1 ) ) ){ //if artist is present
    $q = "SELECT `artists`.`artist_id`, CONCAT_WS( ' ', `first_name`, `middle_name`, `last_name` ) as artist, `prints`.`print_name`, `prints`.`price`,  `prints`.`description`, `prints`.`print_id`
 FROM `shop`.`artists` AS `artists`, `shop`.`prints` AS `prints` WHERE `artists`.`artist_id` = `prints`.`artist_id` AND prints.artist_id = {$_GET['aid']}";

 }


echo "<table align=center>
<tr>
<td>Artist</td>
<td>Print Name</td>
<td>Description</td>
<td>Price</td>
</tr>
";


//get stuff from db
if( $result = $connection->query( $q ) ){
    foreach( $result as $row ){
        echo "
            <tr>
            <td><a href='browse_prints.php?aid={$row['artist_id']}' >{$row['artist']}</a></td>
            <td><a href='view_print.php?pid={$row['print_id']}'>{$row['print_name']}</a></td>
            <td>{$row['description']}</td>
            <td>{$row['price']}</td>
            </tr>
            ";
    }
    $result->close();
}

echo "</table>";



$connection->close();
include( "includes/footer.php");
?>