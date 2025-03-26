#include "Card.hpp"
#include <algorithm>

Card::Card(){
    cardNum = -1;
    faceVal = -1;
    suit = "Null";
    name = "Null";
    picture = "Null";
}

Card::Card( int num ){
    cardNum = num;
    faceVal = num % 13 + 1;
    setSuit();
    setName();
    setPicture();
}

void Card::setSuit(){
    if( cardNum < 13 ){
        suit = "Hearts";
    } else if( cardNum < 26 ){
        suit = "Diamonds";
    } else if( cardNum < 39 ){
        suit = "Clubs";
    } else {
        suit = "Spades";
    }
}

void Card::setName(){
    switch ( cardNum % 13) {
        case 12: name = "King"; break;
        case 11: name = "Queen"; break;
        case 10: name = "Jack"; break;
        case 9: name = "Ten"; break;
        case 8: name = "Nine"; break;
        case 7: name = "Eight"; break;
        case 6: name = "Seven"; break;
        case 5: name = "Six"; break;
        case 4: name = "Five"; break;
        case 3: name = "Four"; break;
        case 2: name = "Three"; break;
        case 1: name = "Two"; break;
        case 0: name = "Ace"; break;
        default: name = to_string( cardNum % 13 + 1 ); break;
    }
}

char helpLower( char c ){
    return tolower( c );
}

void Card::setPicture(){
    string n = name;
    string s = suit;

    //transform name to lowercase
    //        input    input stop  output    what doing
    transform( n.begin(), n.end(), n.begin(), &helpLower );

    //transform suit to lower with a lambda function
    // [] capture class balnk means wer are not using any variable from the surrounding scope
    //-> char mean the return type of this function
    transform( s.begin(), s.end(), s.begin(), [](char c) -> char { return tolower( c ); } );

    picture = "cards/" + n + s + ".jpg";
}

string Card::toString() const {
    return name + " of " + suit;
}