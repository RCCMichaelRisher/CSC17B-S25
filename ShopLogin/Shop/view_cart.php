<?php # Script - view_cart.php
// This page displays the contents of the shopping cart.
// This page also lets the user update the contents of the cart.

// Set the page title and include the HTML header:
$page_title = 'View Your Shopping Cart';
include('includes/header.php');


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

}
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

    ?>
    <tr>
        <td align="left" width="30%"><b><?= $row['artist'] ?> </b></td>
        <td align="left" width="30%"><b><?= $row['print_name'] ?></b></td>
        <td align="right" width="10%"><b><?= $_SESSION['cart'][$row['print_id']]['price'] ?></b></td>
        <td align="center" width="10%"><b><?= $_SESSION['cart'][$row['print_id']]['quantity'] ?></b></td>
        <td align="right" width="10%"><b><?= $subtotal ?></b></td>
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

include('includes/footer.php');
?>