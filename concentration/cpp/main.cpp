/* 
 * Author: Michael Risher
 * Purpose: concentration game
 */

//System Libraries
#include <iostream>  //Input Output Library
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <fstream> //files
#include <sstream>
using namespace std;

//User Libraries
#include "Card.hpp"

//Global Constants not Variables
//Science, Math, Conversions, Dimensions

//Function Prototypes
Card *fillDeck( int );
void printDeck( Card *, int );
void print( ostream &stream, Card *deck, int n  );
void shuffle( Card *deck, int n, int times );

//Execution begins here at main
int main(int argc, char** argv) {
    //Set random number seed
    srand( time( 0 ) );
    //Declare Variables
    
    //Initialize Variables
    Card *deck = fillDeck( Card::NORMAL_DECK_SIZE );
    printDeck( deck, Card::NORMAL_DECK_SIZE );
    shuffle( deck, Card::NORMAL_DECK_SIZE, 7 );
    //Map/Process the Inputs -> Outputs
    
    //Display Inputs/Outputs
    printDeck( deck, Card::NORMAL_DECK_SIZE );
    ofstream outfile( "../output.html" );
    if( outfile ) { //if it opened
        print( outfile, deck, Card::NORMAL_DECK_SIZE );
    }
    
    // print( cout, deck, Card::NORMAL_DECK_SIZE );
    //can also do string stream since its parent is ostream
    // stringstream ss;
    // print( ss, deck, 52 );
    // cout <<endl << endl << ss.str();
    
    //Clean up memory and files
    outfile.close(); //close the file
    delete [] deck;
    //Exit the Program
    return 0;
}

Card *fillDeck( int n ){
    Card *deck = new Card[ n ];
    for (int i = 0; i < n; i++) {
        deck[i] = Card( i );
    }

    return deck;
}

void shuffle( Card *deck, int n, int times ){
    for( int i = 0; i < times; i++ ){
        for( int j = 0; j < n; j++ ){
            int r = rand() % n;
            Card temp = deck[i];
            deck[i] = deck[r];
            deck[r] = temp;
        }
    }
}

void printDeck( Card *deck, int n ){
    for( int i = 0; i < 13; i++ ){
        cout
            << setw( 20 ) << deck[i].toString()
            << setw( 20 ) << deck[i + 13].toString()
            << setw( 20 ) << deck[i + 26].toString()
            << setw( 20 ) << deck[i + 39].toString()
            << endl;        
    }
}

void print( ostream &stream, Card *deck, int n  ){
    for( int i = 0; i < n; i++ ){
        stream << deck[i].toHTML() << endl;
    }
}




