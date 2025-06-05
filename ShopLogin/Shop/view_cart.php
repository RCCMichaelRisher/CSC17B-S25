<?php # Script - view_cart.php
// This page displays the contents of the shopping cart.
// This page also lets the user update the contents of the cart.

// Set the page title and include the HTML header:
$page_title = 'View Your Shopping Cart';
include('includes/header.php');


// Check if the form has been submitted (to update the cart):
if ($_SERVER['REQUEST_METHOD'] == 'POST') {

    // Change any quantities:
    foreach ($_POST['qty'] as $k => $v) {

        // Must be integers!
        $pid = (int) $k;
        $qty = (int) $v;

        if ($qty == 0) { // Delete.
            unset( $_SESSION['cart'][$pid] );
        } elseif ($qty > 0) { // Change quantity.
            $_SESSION['cart'][$pid]['quantity'] = $qty;
        }

    } // End of FOREACH.

} // End of SUBMITTED IF.

/**cart struct
     * cart[
     *      1 : [ qty, price],
     *      2 : [ qty, price],
     * ]
     */
if( !empty( $_SESSION['cart'] ) ){
    require( 'connect.php');

    $q = "SELECT print_id, CONCAT_WS( ' ', `first_name`, `middle_name`, `last_name` ) as artist, print_name FROM artists, prints 
    WHERE artists.artist_id = prints.artist_id AND prints.print_id IN (";
    foreach( array_keys( $_SESSION['cart'] ) as $pid ){
        $q .= $pid . ",";
    }
    $q = substr( $q, 0 , -1 );
    $q .= ") order by artists.last_name ASC";

    $result = $connection->query( $q );

    ?>
    <form action="view_cart.php" method="post">
        <table border="0" width="90%" cellspacing="3" cellpadding="3" align="center">
        <tr>
            <td align="left" width="30%"><b>Artist</b></td>
            <td align="left" width="30%"><b>Print Name</b></td>
            <td align="right" width="10%"><b>Price</b></td>
            <td align="center" width="10%"><b>Qty</b></td>
            <td align="right" width="10%"><b>Total Price</b></td>
        </tr>
    <?php

    $total = 0;
    foreach( $result as $row ){
        $subtotal = $_SESSION['cart'][$row['print_id']]['quantity'] *  $_SESSION['cart'][$row['print_id']]['price'];
        $total += $subtotal;
        ?><tr>
            <td align="left"><?= $row['artist'] ?></td>
            <td align="left"><?= $row['print_name'] ?></td>
            <td align="right"><?= number_format($_SESSION['cart'][$row['print_id']]['price'], 2) ?></td>
            <td align="center"><input type="text" size="3" name="qty[<?= $row['print_id'] ?>]" value="<?= $_SESSION['cart'][$row['print_id']]['quantity'] ?>" /></td>
            <td align="right">$<?= number_format($subtotal, 2) ?></td>
        </tr>
        <?php
    }
    $result->close();
    $connection->close();

    ?>
        <div align="center">
            <input type="submit" name="submit" value="Update My Cart" />
        </div>
        <p align="center">Enter a quantity of 0 to remove an item.
            <br /><br />
            <a href="checkout.php">Checkout</a>
        </p>
        </table>
    </form>
    <?php
} else {
    echo '<p align="center">Your cart is empty.</p>';
}
include('includes/footer.php');
?>