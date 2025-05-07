<?php
//tell js im sending xml
header( "Content-Type: application/xml" );

$input = file_get_contents( "php://input" ); //gets the raw post request
//turn to xml
$data = simplexml_load_string( $input ); //loads xml from string
print_r( $data );
//verify we got something
if( !$data ){
    http_response_code( 400 );
    echo "<response><message>invalid xml</message></response>" ;//assoc array to string
    exit;
}

//load file if there is one
$file = 'feedback.xml';
$feedback = new SimpleXMLElement( "<feedback/>");

//check if exists
if( file_exists( $file ) ){
    $feedback = simplexml_load_file( $file );
}

//append the new feedback
$newFeedback = $feedback->addChild( 'feedback');
foreach( $xml as $k => $v ){
    $newFeedback->addChild( $k, htmlspecialchars( $value ) );
}

//save to the file
$feedback->asXml( $file );

//send a reaponse to js
$dom = dom_import_simpleXML( $feedback );
$content = $dom->ownerDocument->saveXML( $dom->ownerDocument->documentElemt ); //read the contents from the xml object
echo "<reponse><message>Saved succesufully</message><content>{$content}</content></response>";
?>