/* 
 * Author: Michael Risher
 * Purpose: 
 */

//System Libraries
#include <iostream>  //Input Output Library
#include <exception>
using namespace std;

//User Libraries

//Global Constants not Variables
//Science, Math, Conversions, Dimensions

//Function Prototypes

//Execution begins here at main
int main(int argc, char** argv) {
    //Set random number seed
    int x;
    string msg;
    //input x
    cout << "Input the value of x, x must be an int from x >= 0 and x <= 2" << endl;
    cin >> x;

    //branching 
    if ( x < 0 ) cout << "value too small " << endl;
    if ( x > 2 ) cout << "value too big " << endl;
    if ( x >= 0 && x <= 2 ) cout << "value to okay " << endl;

    if ( x < 0 ) cout << "value too small " << endl;
    else if ( x > 2 ) cout << "value too big " << endl;
    else cout << "value to okay " << endl;

    msg = ( x < 0 ) ? "value too small " :
        ( x > 2 ) ?  "value too big " :
                    "value to okay ";
    cout << msg << endl;

    //switch 
    switch ( x ){
        case 0:
        case 1:
        case 2: cout << "value to okay " << endl;
        default: cout << "value not okay now" << endl;
    }
    

    //looping construct for, do-while, while, for in
    int loop = 5;
    for( int i = 0; i <= loop; i++ ){
        cout << i << " ";
    }
    cout << endl;

    int i = 0;
    do{
        cout << i++ << " ";
    } while ( i <= loop );
    cout << endl;
    
    //while loop
    i = 0;
    while( i <= loop ){
        cout << i++ << " ";
    }
    cout << endl;

    //for in aka range based for loop construct thing
    int array[] = {0,1,2,3,4,5};
    for( int i : array ){
        cout << i << " ";
    }
    cout << endl;

    //try catch on errors
    try{
        //do something until it breaks
        //or throws an error
        throw runtime_error( "Its a feature" );
    } catch ( const exception &e ){
        cout << "Caught an exception: " << e.what() << endl;
    }

    return 0;
}