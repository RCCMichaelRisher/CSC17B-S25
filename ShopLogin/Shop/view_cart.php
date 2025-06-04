<?php # Script - view_cart.php
// This page displays the contents of the shopping cart.
// This page also lets the user update the contents of the cart.

// Set the page title and include the HTML header:
$page_title = 'View Your Shopping Cart';
include('includes/header.php');



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