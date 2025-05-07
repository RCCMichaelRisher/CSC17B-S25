<?php

if( !empty( $_GET['name']) && !empty( $_GET['email']) ){
    //validate its actual email 
    //name length

    $name = htmlspecialchars( $_GET['name'] );
    $email = htmlspecialchars( $_GET['email'] );

    
    ?>
    <h1>Form Data</h1>
    <p><?php echo $name ?></p>
    <p><?= $email ?></p>

    <h2>json data</h2>
    <pre>
    <?php
    $data = [ 
        'name' => $name,
        'email' => $email
    ];
    echo json_encode( $data, JSON_PRETTY_PRINT );
    echo "</pre>";

} else{
    ?><p>no data</p><?php
}

?>