
class View{
    /**
     * display messages to the user in the message area
     * @param {string} msg 
     */
    displayMessage( msg ){
        let msgArea = document.getElementById( "messageArea" );
        msgArea.innerHTML = msg;
    }

    displayHit( location ){}

    displayMiss( location ){}
}

let view = new View();