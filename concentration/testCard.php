<!doctype html>

<html>
    <head>
    </head>
    <body>
        <?php

        require './Card.php';
        function main(){
            $deck = array();
            for( $i = 0; $i < Card::$NORMAL_DECK_SIZE; $i++ ){
                $deck[$i] = new Card( $i );
                echo $deck[$i]->toHtml();
            }
        }

        main();

        ?>
    </body>
</html>