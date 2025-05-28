<!doctype html>
<html>
<head>
    <title>add an artist</title>
    <link rel="stylesheet" href="../styles.css">
</head>
<body>
    <?php
        if( $_SERVER['REQUEST_METHOD'] == "POST" ){ //doing the action
            var_dump( $_POST );
            if( !empty( $_POST['last_name'] ) ){
                $ln = trim( $_POST['last_name']);
                $fn = !empty( $_POST['first_name'] ) ? trim( $_POST['first_name'] ) : null;
                $mn = !empty( $_POST['middle_name'] ) ? trim( $_POST['middle_name'] ) : null;

                //talk to the database
                require( "../connect.php" );

                $q = "INSERT INTO `artists`(`first_name`, `last_name`, `middle_name`) VALUES (?,?,?)";
                $statement = $connection->prepare( $q );
                $statement->bind_param( "sss", $fn, $ln, $mn );

                // debug( $ln, $mn, $fn );
                $statement->execute();


                //did it work???
                if( $statement->affected_rows == 1 ) {
                    echo "<p>the artist has been added to the database</p>";
                } else {
                    echo "<p>There was an error</p>";
                }

                //close
                $statement->close();
                $connection->close();
            }
            else{
                echo "<p style='color:red'>the artist needs a last name</p>";
            }
        } 

    ?>

    <h1>add an artist</h1>
    <form action="add_artist.php" method="post">
        <fieldset>
            <legend>Fill out the form to add and artist</legend>

            <label for="first_name"><b>first name</b></label>
            <input type="text" id="first_name" name="first_name" value="">

            <label for="middle_name"><b>middle name</b></label>
            <input type="text" id="middle_name" name="middle_name" value="">

            <label for="last_name"><b>last name</b></label>
            <input type="text" id="last_name" name="last_name" value="">

            <input type="submit" value="submit" />

        </fieldset>
    </form>
</body>
</html>





