#ifndef Card_H
#define Card_H

#include <string>
using namespace std;

class Card {
    private: 
        int cardNum;
        int faceVal;
        string suit;
        string name;
        string picture;

        //private setters
        void setSuit();
        void setName();
        void setPicture();
    public: 
        static const int NORMAL_DECK_SIZE = 52;
        Card();
        Card( int );
        int getCardNum() const { return cardNum; }
        int getFaceVal() const { return faceVal; }
        string getSuit() const { return suit; }
        string getName() const { return name; }
        string getPicture() const { return picture; }
        string toString() const;
        string toHTML() const;

      
};


#endif /* Card_H */