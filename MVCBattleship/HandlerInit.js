function fireBtnHandle(){
    //do button stuff here
    alert( "you shot me! WHY 😂")
    //TODO bomb ships
}

function init(){
    //initalize events
    //find the fire button
    let fireBtn = document.getElementById("fireButton");
    fireBtn.onclick = fireBtnHandle;

}

window.onload = init;
//same stuff different ways
// window.onload = ( e ) => {
//     //init stuff here
// }

// window.onload = function( e ) {
//     //init stuff
// }