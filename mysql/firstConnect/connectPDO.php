<?php

    //define login stuff
    //global constants
    define( "DB_IP", "209.129.8.9" );
    define( "DB_USER", "csc17b" );
    define( "DB_PASS", "csc17bstudent" );
    define( "DB_DB", "csc17b" );

    try{
        $connection = new PDO( "mysql:host=".DB_IP.";dbname=".DB_DB, DB_USER, DB_PASS );
        //set the PDO error mode to use exceptions
        $connection->setAttribute( PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION );
        echo "connected";
    } catch( PDOException $e ){
        echo "not connected";
        debug( $e );
    }


    function debug( ...$a ){
        echo "<pre>";
        print_r( $a );
        echo "</pre>";
    }
    