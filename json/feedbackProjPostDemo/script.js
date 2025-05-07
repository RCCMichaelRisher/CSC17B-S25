document.getElementById( "feedbackForm" ).addEventListener( "submit", formAction );


function formAction( event ){
    event.preventDefault();

    const clicketBtn = event.target.querySelector( 'button[type="submit"]:focus') || event.target.querySelector( 'button[type="submit"]:active');
    const formData = new FormData( this );

    console.log( "clicked: ", clicketBtn );
    if( clicketBtn.value === "JSON" ){
        //do json function
        toJSON( formData, event );
    } else if ( clicketBtn.value === "XML") {
        //xml function
        //solution 1 pull this out of toXMl up to where its relevant
        const formElements = this.elements;
        toXML( formElements );
        //solution 2 tell it what this should be
        // toXML.bind( this, event )();
    }
}

function toJSON( formData, e ){
    changeData( "JSON" );
    let jsonObject = {};

    // console.log( [...formData] );
    // console.table( [...formData]);

    //for each element run an function(value, key) that puts them in the json object
    formData.forEach( (value, key ) => {
        jsonObject[key] = value;
    });

    jsonObject['timestamp'] = new Date().toISOString();

    console.log( jsonObject );
    document.getElementById( "output" ).innerHTML = JSON.stringify( jsonObject, null, 2 ); //print pretty json


    //lets talk to php!
    //form action url
    fetch( "saveFeedbackJson.php", {
        method : "POST",
        body : formData
    } )
    .then( response => response.json() ) //convert the json since the js sees it as text
    //function( response ){
    // return response.json()
    //}
    .then( result => {
        //update the html areas
        document.getElementById( "content" ).textContent = JSON.stringify( result.content, null, 2 ); //pretty json        
        document.getElementById( "message" ).textContent = JSON.stringify( result["message"], null, 2 ); //pretty json        
    } )
    .catch( error => {
        console.error( error );
        document.getElementById( "message" ).textContent = JSON.stringify( error["message"], null, 2 ); //pretty json
    }) //catch any problems

    console.log( true );
}


function toXML( formElems ){
    changeData( "XML" );
    const formElements = formElems; //this.elements; //this is for solution 2 
    console.log( formElements );
    let xmlObject = {};
    
    //different way of getting form data
    for( let i = 0; i < formElements.length; i++ ){
        const elem = formElements[i];
        xmlObject[elem.name] = elem.value;
    }

    xmlObject['timestamp'] = new Date().toISOString();

    let xmlString = "<feedback>";
    for( let key in xmlObject ){
        xmlString += `<${key}>${xmlObject[key]}</${key}>\n`;
    }
    xmlString += "</feedback>";

    console.log( xmlString );
    document.getElementById( "output" ).innerHTML = xmlString

    //fetch 
    fetch( "saveFeedbackXml.php", {
        method : "POST",
        header : {
            "Content-Type" : "application/xml"
        },
        body : xmlString
    } )
    .then( response => response.text() ) //convert response to text
    //function( response ){
    // return response.json()
    //}
    .then( result => {
        //update the html areas
        const parser = new DOMParser();
        let xml = parser.parseFromString( result, "application/xml");
        document.getElementById( "content" ).textContent = xml.getElementsByTagName("message")[0].outerHTML;    
        document.getElementById( "message" ).textContent = xml.getElementsByTagName("content")[0].outerHTML;  
    } )
    .catch( error => {
        console.error( error );
        const parser = new DOMParser();
        let xml = parser.parseFromString( result, "application/xml");
        document.getElementById( "message" ).textContent = xml.getElementsByTagName("message")[0].outerHTML;  
    }) //catch any problems

    console.log( true );
}

function changeData( str ){
    document.querySelectorAll( ".datatype" ).forEach( function( element ){
        element.innerHTML = str;
    })
}