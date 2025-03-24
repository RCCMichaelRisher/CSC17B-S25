<!DOCTYPE html>
<html>
    <head>
        <!-- meta data also this a comment -->
        <meta charset="UTF-8" />
        <title>Awesome webpage title here</title>
        <!-- stylesheets, js, fonts, other stuff i cant think of -->
        
    </head>
    <body>
        <!-- meat of the page -->
        <?php
        //and so begins the php-ing
        //varaible are typeless and start $
        $prompt = "Input the value of x, x must be an int from x >= 0 and x <= 2";
        $script = <<<EOD
<script>
let x = prompt( '${prompt}' );
document.cookie = 'x=' + x;
</script>
EOD;
        print( $script );
        //access the cookie
        $x = $_COOKIE["x"];
        //the . concats the string together
        print( $x . "<br>");

        ?>
    </body>
</html>