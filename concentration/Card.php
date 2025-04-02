<?php

class Card{
    private $cardNum;
    private $faceVal;
    private $suit;
    private $name;
    private $picture;

    public static $NORMAL_DECK_SIZE = 52;

    public function __construct( $cardNum ){
        $this->cardNum = $cardNum;
        $this->faceVal = $cardNum % 13 + 1;
        $this->setSuit();
        $this->setName();
        $this->setPicture();
    }

    public function Card(){
        $this->cardNum = -1;
        $this->faceVal = -1;
        $this->suit = "Null";
        $this->name = "Null";
        $this->picture = "Null";
    }

    private function setSuit(){
        if( $this->cardNum < 13 ){
            $this->suit = "Hearts";
        } else if( $this->cardNum < 26 ){
            $this->suit = "Diamonds";
        } else if( $this->cardNum < 39 ){
            $this->suit = "Clubs";
        } else {
            $this->suit = "Spades";
        }
    }

    private function setName(){
        switch ( $this->cardNum % 13) {
            case 12: $this->name = "King"; break;
            case 11: $this->name = "Queen"; break;
            case 10: $this->name = "Jack"; break;
            case 9:  $this->name = "Ten"; break;
            case 8:  $this->name = "Nine"; break;
            case 7:  $this->name = "Eight"; break;
            case 6:  $this->name = "Seven"; break;
            case 5:  $this->name = "Six"; break;
            case 4:  $this->name = "Five"; break;
            case 3:  $this->name = "Four"; break;
            case 2:  $this->name = "Three"; break;
            case 1:  $this->name = "Two"; break;
            case 0:  $this->name = "Ace"; break;
            default: $this->name = to_string( $this->cardNum % 13 + 1 ); break;
        }
    }

    private function setPicture(){
        $n = $this->name;
        $s = $this->suit;
    
        //to lower string
        $n = strtolower( $n );
        $s = strtolower( $s );

        $this->picture = "cards/" . $n . $s . ".jpg";
    }

    public function __toString(){
        return $this->name . " of " . $this->suit;
    }

    public function toHTML() {
        $ss = "<div class=\"card\">" .
            "<img src=\"" . $this->picture . "\" alt=\"" . $this->__toString() . "\" />" .
            "<p>" . $this->__toString() . "</p>".
            "</div>";
        return $ss;
    }


// int getCardNum() const {
// int getFaceVal() const {
// string getSuit() const {
// string getName() const {
// string getPicture() cons
// string toString() const;
// string toHTML() const;
}


?>