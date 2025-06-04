<?php # Script - add_cart.php
// This page adds prints to the shopping cart.

// Set the page title and include the HTML header:
$page_title = 'Add to Cart';
include('includes/header.php');

include('connect.php');
if( isset( $_GET['pid'] ) && filter_var( $_GET['pid'], FILTER_VALIDATE_INT, array( 'min_range' => 1 ) ) ){
    $pid = $_GET['pid'];

    //is there a cart already?
    if( isset( $_SESSION['cart'][$pid] ) ){
        //add to the quantity
        $_SESSION['cart'][$pid]['quantity']++;
        echo "<p>Another copy has been added to the cart</p>";

    } else{
        $q = "SELECT price FROM prints WHERE print_id = ?";
        $state = $connection->prepare($q);
        $state->bind_param( "i", $pid );
        $state->execute();
        $state->store_result();

        if( $state->num_rows() == 1 ){
            $state->bind_result( $price );
            $state->fetch();

            //make the cart
            $_SESSION['cart'][$pid] = [
                'quantity' => 1,
                'price' => $price
            ];

            echo "<p>the print has been added to the cart</p>";
        } else{
            echo "<p>the print is not valid</p>";
        }
        $state->close();
    }
} else{
    echo "<p>the print is not valid</p>";
}


$connection->close();
include('includes/footer.php');
?>