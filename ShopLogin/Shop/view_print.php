<?php

require_once( "connect.php" );


if( isset( $_GET['pid'] ) && filter_var( $_GET['pid'], FILTER_VALIDATE_INT, array( 'min_range' => 1 ) ) ){
    $pid = $_GET['pid'];

    $q = "SELECT CONCAT_WS( ' ', `first_name`, `middle_name`, `last_name` ) as artist, `prints`.`print_name`, `prints`.`price`, `prints`.`description`, `prints`.`size`, `prints`.`image_name`, `prints`.`print_id` 
    FROM `shop`.`artists` AS `artists`, `shop`.`prints` AS `prints` 
    WHERE `prints`.`print_id` = ?";
    $state = $connection->prepare( $q );
    $state->bind_param( "i", $pid );
    $state->execute();
    $result = $state->get_result();

    if( $result->num_rows >= 1 ){
        $row = $result->fetch_assoc();

        $pageTitle = $row['print_name'];
        include( "includes/header.php");

        ?>
        <div align="center">
            <b><?= $row['print_name'] ?></b> by <br>
            <?= $row['artist'] ?>
            <?php
            echo ( is_null($row['size']) ? '(no size info)' : $row['size'] ); 

            ?>
            <br>$<?= $row['price'] ?>
            <a href="add_cart.php?pid=<?= $pid ?>">Add to cart</a>
        </div>
        <?php

        if( $image = @getimagesize( "../uploads/$pid" ) ){
            ?>
            <div align="center">
                <img src="show_image.php?image=<?= $pid ?>&name=<?= urlencode($row['image_name']) ?>" />
            </div>
            <?php
        } else{
            ?>
            <div align="center">
                No image
            </div>
            <?php
        }


    } else{
        $pageTitle = "Error";
        include( "includes/header.php");
        ?><div align="center">This page has been accessed in error</div><?php
    }

    $state->close();

    
    //display the print
} else{
    $pageTitle = "Error";
    include( "includes/header.php");
    ?><div align="center">This page has been accessed in error</div><?php
}

$connection->close();

include( "includes/footer.php");
?>