class Model{

    constructor(){
        this.boardSize = 7; 
        this.numShips = 4;
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

    fire(){}

    isSunk( ship ){}

    /**
     * generate random location for all ships and assign then to the ship array
     */
    generateShipLocations(){
        let locations;
        for( let i = 0; i < this.numShips; i++ ){
            let ship = this.ships[i];

            do{
                locations = this.generateShip( ship ); //make the locations for one ship
            } while( this.collision( locations ) ); //loop if there are collisions

            //all is well we can add it to the final ship array
            ship.location = locations;
        }
        console.log( this.ships );

    }

    /**
     * generate a single ship location
     * @param {} ship 
     */
    generateShip( ship ){
        let dir = Math.floor( Math.random() * 2 ); 
        let row, col;

        if( direction === 1 ) { //horizontal
            row = Math.floor( Math.random() * this.boardSize  )

            col =  Math.floor( Math.random() * this.boardSize - ship.shipLength + 1  )

        } else { //vertical 
            row = Math.floor( Math.random() * this.boardSize  - ship.shipLength + 1 )

            col =  Math.floor( Math.random() * this.boardSize  )
        }

        //todo fill the rest of the rest of the locations spots 
    }

    collision( location ){}
}

let model = new Model();