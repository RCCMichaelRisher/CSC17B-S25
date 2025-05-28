<?php
    echo "reading the cookie values <br>";

    $text = $_COOKIE['object'];

    echo $text . "<br>";

    echo "<pre>";
    print_r( json_decode( $text, true ) );
    echo "</pre>";
    ?>