<?php

// print_r()//raw dump of data
// $v = "";
// if ( isset( $v ) ) {
//     echo "T";
// } else 
//     echo "F";
// echo "<br>";
if( !empty( $_POST['name']) && !empty( $_POST['email']) ){
    //validate its actual email 
    //name length

    $name = htmlspecialchars( $_POST['name'] );
    $email = htmlspecialchars( $_POST['email'] );

    
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