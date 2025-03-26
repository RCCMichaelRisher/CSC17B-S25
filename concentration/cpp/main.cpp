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

using namespace std;

//User Libraries
#include "Card.hpp"

//Global Constants not Variables
//Science, Math, Conversions, Dimensions

//Function Prototypes
Card *fillDeck( int );
void printDeck( Card *, int );

//Execution begins here at main
int main(int argc, char** argv) {
    //Set random number seed
    srand( time( 0 ) );
    //Declare Variables
    
    //Initialize Variables
    Card *deck = fillDeck( Card::NORMAL_DECK_SIZE );
    printDeck( deck, Card::NORMAL_DECK_SIZE );
    // shuffle();
    //Map/Process the Inputs -> Outputs
    
    //Display Inputs/Outputs
    
    //Clean up memory and files
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