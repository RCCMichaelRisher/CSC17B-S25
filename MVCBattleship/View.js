
class View{
    /**
     * display messages to the user in the message area
     * @param {string} msg 
     */
    displayMessage( msg ){
        let msgArea = document.getElementById( "messageArea" );
        msgArea.innerHTML = msg;
    }

    displayHit( location ){
        let cell = document.getElementById( location );
        cell.setAttribute( "class", "hit" );

    }

    displayMiss( location ){
        let cell = document.getElementById( location );
        cell.setAttribute( "class", "miss" );
    }

    /**
     * turn all the hits and misses back into cells
     */
    resetCells(){
        //get all the cells
        for( let i = 0; i < model.boardSize; i++ ){
            for( let j = 0; j < model.boardSize; j++ ){
                document.getElementById( i + "" + j ).setAttribute( "class", "cell" );
            }
        }

    }
}

let view = new View();