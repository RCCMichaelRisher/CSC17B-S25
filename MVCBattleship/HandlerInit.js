function fireBtnHandle(){
    //do button stuff here
    // alert( "you shot me! WHY 😂")

    //get the guess from the input
    let input = document.getElementById( "guessInput" );
    let guess = input.value.toUpperCase();

    controller.processGuess( guess ); //figure out their guess

    input.value = ""; //wipe their guess

}

function keyPressHandle( event ){
    if( event.keyCode == 13 ){ //pressed enter
        event.preventDefault(); //prevent enter form action
        let fireBtn = document.getElementById("fireButton");
        fireBtn.click(); //runs the fireBtn event by clicking it
    }
}

function newGameHandle( e ) {
    controller.newGame();
}


function init(){
    //initalize events
    //find the fire button
    let fireBtn = document.getElementById("fireButton");
    fireBtn.onclick = fireBtnHandle;

    let input = document.getElementById( "guessInput" );
    input.onkeydown = keyPressHandle; //when press of key do things

    let newGameBtn = document.getElementById( "newGame" );
    newGameBtn.onclick = newGameHandle;

    controller.initGame();//init the game play

}

window.onload = init;
//same stuff different ways
// window.onload = ( e ) => {
//     //init stuff here
// }

// window.onload = function( e ) {
//     //init stuff
// }