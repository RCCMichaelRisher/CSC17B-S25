<?php

echo "<pre>";
print_r( $_POST );
echo "</pre>";


exit;
//dont run anything below this is only testing a post request


//tell js im sending json
header( "Content-Type: application/json" );

$input = file_get_contents( "php://input" ); //gets the raw post request
//turn to json
$data = json_decode( $input, true ); //string -> assoc array || class

//verify we got something
if( !$data ){
    http_response_code( 400 );
    echo json_encode( ["message" => "invalid JSON" ] ); //assoc array to string
    exit;
}

//load file if there is one
$file = 'feedback.json';
$feedback = [];

//check if exists
if( file_exists( $file ) ){
    $jsonFeedback = file_get_contents( $file );
    $feedback = json_decode( $jsonFeedback, true ) ?   : [];
}

//append the new feedback
$feedback[] = $data;

//save to the file
file_put_contents( $file, json_encode( $feedback, JSON_PRETTY_PRINT ) );

//send a reaponse to js
echo json_encode( [
    "message" => "Feedback saved succesfully",
    "content" => $feedback
]);
?>