
class Controller{

    constructor(){
        this.guesses = 0;
    }

    /**
     * parse the guess from the user input
     * @param {string} guess the players guess string
     * @returns {string|null} location. null if invalid
     */
    parseGuess( guess ){
        //determine what the heck it was.
        const alphabet = [ "A", "B", "C", "D", "E", "F", "G" ];
        //is ther even input
        if(  guess === null || guess.length !== 2) {
            alert( "why cant you read");
            view.displayMessage( "Invalid Location!!!!" );
        } else{
            let firstChar = guess.charAt( 0 );
            let row = alphabet.indexOf( firstChar ); //gets index from the letter
            let col = parseInt( guess.charAt( 1 ) );
            
            if( isNaN( row ) || isNaN( col ) ){ //incase of weird input i didnt catch
                alert( "weird input try again");
                view.displayMessage( "Invalid Location!!!!" );
            } else if( row < 0 || row >= model.boardSize || col < 0 || col >= model.boardSize ){
                alert( "not in the board space");
                view.displayMessage( "not in the board space");
            } else{
                //everyting is ok nothing fire this time;
                return row + "" + col; //make into a string and concat them together
            }
        }
    }

    processGuess( guess ){
        let location = this.parseGuess( guess ); //what the heck is that?
        if( location ){
            this.guesses++;
            let hit = model.fire( location ); //call the hit func in model
            //if you hit my last ship this is where id learn about it first
            //test win condition
            if( hit && model.numShipsSunk == model.numShips ){
                view.displayMessage( "You sank all my ships. Much impress") ;
            }
        }

    }

    initGame(){
        //make the ships
        model.generateShipLocations();
    }
}

let controller = new Controller();