class Question{
    constructor( category, question, answers ){
        const nArgs = arguments.length;
        if ( nArgs == 0 || nArgs > 3 ){
            this.category = "";
            this.question = "";
        } else if( nArgs == 3 ){
            this.category = category;
            this.question = question;
            this.answers = answers;
        } else if (nArgs == 2 ){
            this.category = category;
            this.question = question;
        } else {
            // if( typeof category == "object"){
                this.category = category.category;
                this.question = category.question;
                this.answers = category.answers;
            // }
        } 
    }

    setCategory( a ) { this.category = a; }
    setQuestion( a ) { this.question = a; }
    setAnswers ( a ) { this.answers = a; }

    getCategory(){ return this.category; }
    getQuestion(){ return this.question; }
    getAnswers( number ){
        if( number >= 0 && number < this.answers.length ){
            return this.answers[number];
        } else {
            return "HUH??";
        }
    }

    //parent == place in the DOM to into to
    display( parent ){
        let p = document.createElement( "p" ); //<p>
        p.textContent = this.question;
        parent.appendChild( p ); //document.body.innerHtml = ( p ) //replacing our document writes

        for( let i = 0; i < this.answers.length; i++ ){
            if( this.answers[i].length > 0 ){
                //not blank
                let div = document.createElement( "div");
                let label = document.createElement( "label" );
                label.textContent = this.answers[i];

                //input checkbox
                let input = document.createElement( "input" );
                input.setAttribute("id", this.answers[i] );
                Object.assign( input, {
                    type: "radio",
                    name: this.category,
                    value: this.answers[i]
                });
                label.appendChild( input );
                div.appendChild( label );
                parent.appendChild( div );
            }
        }
    }

}
