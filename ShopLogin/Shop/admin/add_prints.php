<!doctype html>
<html>
<head>
    <title>add a print</title>
    <link rel="stylesheet" href="../styles.css">
</head>
<body>
    <?php
        require( "../connect.php" );
        if( $_SERVER['REQUEST_METHOD'] == "POST" ){ //doing the action
            var_dump( $_POST );
            $errors = [];
            if( !empty( $_POST['print_name'])){
                $pn = trim( $_POST['print_name'] );
            }
            else{
                $errors[] = "needs a print name";
            }

            //check for an image
            // debug( $_POST );
            // debug( $_FILES );
            if( is_uploaded_file( $_FILES['image']['tmp_name'] ) ){
                $temp = "../../uploads/" . md5(  $_FILES['image']['name'] );

                if( move_uploaded_file( $_FILES['image']['tmp_name'], $temp) ){
                    echo '<p>the file was uploaded</p>';

                    $i = $_FILES['image']['name'] ;
                }
            } else{
                $errors[] = "no image submitted";
            }

            //size
            $s = !empty(  $_POST['size']  ) ? trim( $_POST['size'] ) : null;

            //price
            if(is_numeric(  $_POST['price'] ) ) {
                $price = !empty(  $_POST['price']  ) ? trim( $_POST['price'] ) : null;
            }else {
                $errors[]= "pirce needs to be a  number";
            }

            //desciption
            $desc = !empty(  $_POST['description']  ) ? trim( $_POST['description'] ) : null;

            $ai  = !empty(  $_POST['artist']  ) ? trim( $_POST['artist'] ) : null;

            if( empty( $errors ) ) {
                //we good upload to db
                $q = "INSERT INTO `prints`(`artist_id`, `print_name`, `price`, `size`, `description`, `image_name`) VALUES (?,?,?,?,?,?)";
                $statement = $connection->prepare( $q );
                $statement->bind_param( "isdsss", $ai, $pn, $price, $s, $desc, $i );
                $statement->execute();

                if( $statement->affected_rows == 1 ) {
                    echo "<p>the artist has been added to the database</p>";
                } else {
                    echo "<p>There was an error</p>";
                }

                //close
                $statement->close();
                

            } else{
                echo "<p>There were errors</P>";
                foreach( $errors as $e )
                    echo $e;
            }
            
        } 

    ?>

    <h1>add an artist</h1>
    <form action="add_prints.php" method="post" enctype="multipart/form-data">
        <fieldset>
            <legend>Fill out the form to add print</legend>

            <label for="print_name"><b>print name</b></label>
            <input type="text" id="print_name" name="print_name" value="">

            <label for="image"><b>image</b></label>
            <input type="file"  name="image" value="">

            <label for="artist"><b>artist</b></label>
            <select name="artist">
                <?php
                    $q = "SELECT artist_id, concat_ws( ' ', first_name, middle_name, last_name ) as name FROM `artists`";
                    $result = $connection->query( $q );

                    if( $result->num_rows > 0 ){
                        foreach( $result as $row ){
                            echo "<option value='" . $row['artist_id'] . "'>{$row['name']}</option>";
                        }
                    }
                ?>
            </select>

            <label for="price"><b>price</b></label>
            <input type="text" name="price" value="">

            <label for="size"><b>size</b></label>
            <input type="text" name="size" value="">

            <label for="description"><b>description</b></label>
            <textarea name="description"></textarea>

            <input type="submit" value="submit" />

        </fieldset>
    </form>
</body>
</html>
<?php
$connection->close();
?>





