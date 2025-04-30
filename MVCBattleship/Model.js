class Model{

    constructor(){
        this.boardSize = 7; 
        this.numShips = 1;
        this.numShipsSunk = 0;

        this.ships = [
            { 
                location: [0,0,0],
                hits: ["","","" ],
                shipLength: 3
            },
            { 
                location: [0,0],
                hits: ["","" ],
                shipLength: 2
            },
            { 
                location: [0,0,0,0],
                hits: ["","","","" ],
                shipLength: 4
            },
            { 
                location: [0,0,0,0,0],
                hits: ["","","","","" ],
                shipLength: 5
            }
        ];
    }

    newGame(){
        this.numShipsSunk = 0;
        this.generateShipLocations();
    }

    /**
     * fire action on the user guessing
     * @param {string} guess 
     * @returns {boolean} if hit return true
     */
    fire( guess ){
        //go through the ship and check for collision with bullet
        for( let i = 0; i < this.numShips; i++ ){
            let ship = this.ships[i];
            let index = ship.location.indexOf( guess );

            //rehitting the same target
            if( ship.hits[index] == "hit" ){
                view.displayMessage( "You already hit " + guess );
                return true;
            }
            else if( index >= 0 ){
                ship.hits[index] = "hit";
                view.displayHit( guess );
                view.displayMessage( "Hit at " + guess );


                //did i sink it
                if( this.isSunk( ship ) ){
                    view.displayMessage( "You sunk my ship" );
                    this.numShipsSunk++;
                }
                return true;
            }
        }

        //nothing got hit
        view.displayMiss( guess );
        view.displayMessage( "You missed" );
        return false;
    }

    /**
     * did you sink my ship
     * @param {Object} ship 
     * @param {string[]} ship.locations
     * @param {string[]} ship.hits
     * @param {number} ship.shipLength
     * @returns {boolean} true if sunk
     */
    isSunk( ship ){
        for( let i = 0; i < ship.shipLength; i++ ){
            if( ship.hits[i] !== "hit" ){
                return false;
            }
        }
        return true;
    }

    /**
     * generate random location for all ships and assign then to the ship array
     */
    generateShipLocations(){
        let location;
        for( let i = 0; i < this.numShips; i++ ){
            let ship = this.ships[i];

            do{
                location = this.generateShip( ship ); //make the locations for one ship
            } while( this.collision( location ) ); //loop if there are collisions

            //all is well we can add it to the final ship array
            ship.location = location;
        }
        console.log( this.ships );

    }

    /**
     * generate a single ship location
     * @param {} ship 
     */
    generateShip( ship ){
        let direction = Math.floor( Math.random() * 2 ); 
        let row, col;

        if( direction === 1 ) { //horizontal
            row = Math.floor( Math.random() * this.boardSize  )

            col =  Math.floor( Math.random() * ( this.boardSize - ship.shipLength + 1 )  )

        } else { //vertical 
            row = Math.floor( Math.random() * (this.boardSize  - ship.shipLength + 1 ) )

            col =  Math.floor( Math.random() * this.boardSize  )
        }

        //todo fill the rest of the rest of the locations spots 
        //fill in the other points
        let newShipLocation = [];
        for( let i = 0; i < ship.shipLength; i++ ){
            if( direction === 1 ) {
                //horizontal
                newShipLocation.push( row + "" + ( col + i ) ) ;
            } else {
                newShipLocation.push( ( row + i ) + "" + col ) ;
            }
        }
        return newShipLocation;
    }

    /**
     * checks if boat is place on a boat
     * @param {string[]} location 
     * @returns {boolean}
     */
    collision( placedShip ){
        for( let i = 0; i < this.numShips; i++ ){
            let ship = this.ships[i];
            for( let j = 0; j < placedShip.length; j++ ){
                if( ship.location.indexOf( placedShip[j] ) >= 0 ){
                    console.log( placedShip, "Sank at :(");
                    return true; //it sank
                }
            }
        }
        return false; //no collision 
    }
}

let model = new Model();