<?php # Script - show_image.php
// This pages retrieves and shows an image.

$image = false;

$name = !empty( $_GET['name'] ) ? $_GET['name'] : "print image";

if( isset( $_GET['image'] ) && filter_var( $_GET['image'], FILTER_VALIDATE_INT, array( 'min_range' => 1 ) ) ){
    $image = "../uploads/" . $_GET['image'];

    if( !file_exists( $image ) || !is_file( $image ) ){
        $image = false;
    }
}

if ( !$image ){
    $image = "images/unavailable.png";
    $name = "unavailable.png";
}

$info = getimagesize( $image );
$fs = filesize( $image );
header( "Content-Type: {$info['mime']}");
header( "Content-Disposition: inline; filename=\"$name\"");
header ( "Content-Length: $fs");

//send the file to the browser
readfile( $image );