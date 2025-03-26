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

        //branching independent ifs
        if ( $x < 0 ) echo( "value too small<br/>" );
        if ( $x > 2 ) print( "value too big<br/>" );
        if ( $x >= 0 && $x <= 2 ) echo( "value to okay<br/>" );

        //depends if
        if ( $x < 0 ) echo( "value too small<br/>" );
        else if ( $x > 2 ) print( "value too big<br/>" );
        else echo( "value to okay<br/>" );

        //the ternary of fun
        //it needs more love and parenthesis to work right
        $msg = ( $x < 0 ) ? ("value too small ") : 
                    ( ( $x > 2 ) ?  ("value too big ") :
                                ("value to okay ") );
        echo( $msg . "<br/>" );

        echo( gettype( $x ) . "<br/>" ); //get what type of data x is

        //switch 
        //x is a string
        switch ( intval( $x ) ){ //turn it into an int then test
            case 0:
            case 1:
            case 2:  print( "value to okay<br/>" ); break;
            default: echo( "value not okay now<br/>" ); break;
        }


        //for loop
        $loop = 5;
        for( $i = 0; $i <= $loop; $i++ ){
            print( $i . " " );
        }
        print( "<br/>" );

        //do while
        $i = 0;
        do{
            print( $i . " " ); //because echo allows for the ellipse parameters
        } 
        while( ++$i <= $loop );
        print( "<br/>" );

        //while loop
        $i = 0;
        while( $i <= $loop ){
            print( $i++ . " " );
        } 
        print( "<br/>" );

        $array = array( 9,1,2,3,4,5);
        foreach( $array as $k => $e ){ //$k index, $e element
            // echo($e, " ")
            echo( $k. " - " . $e . "<br>" );
        }

        //handle errors
        try{
            //maybe error
            throw new Exception( "it broke!" );
        } catch ( Exception $e ){
            print( $e->getMessage() . "<br/>");
        } finally {
            //this runs at the end if errored or if not
            print( "finally the block is executed<br/>" );
        }

        $arr = [ "one" => 1, "two" => 2, 4 => 5];
        echo "<pre>";
        print_r( $array );
        print_r( $arr );
        
        print_r( new Exception( "it broke!" ) );
        echo "</pre>";

        print( $arr[4] );
        print( $arr["one"] );
        ?>
    </body>
</html>