<?php session_start() ?>
<!doctype html>
<html>
<head>
    <title><?php echo isset( $pageTitle ) ? $pageTitle : "Shop" ?></title>
    <link rel="stylesheet" href="styles.css">
</head>
<body>
    <header>
        <div class="logo">
            <img src="images/title.jpg" width="600" height="61" >
        </div>
        <nav>
            <ul class="nav-links">
                <li><a href="index.php"><img src="images/home.jpg"></a></li>
                <li><a href="browse_prints.php"><img src="images/prints.jpg"></a></li>
                <li><a href="view_cart.php"><img src="images/cart.jpg"></a></li>
            </ul>
        </nav>
    </header>






