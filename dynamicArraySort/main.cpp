/*
Author: Michael Risher
Purpose: Sort and use 1d and 2d array with pointers 😞
*/

//system libraries
#include <iostream>  //input/output library
#include <cstdlib> //random function library
#include <ctime> //time 
using namespace std; //using namespace standard

//user libraries

//global constants not variable
//science, math, conversion, dimension

//function prototypes
int *fillArray( int ); //sizes a 1d array and return the pointer
int **fillArray( int, int ); //sizes a 2d array and return the pointer
void cleanup( int * ); //free up memory from 1d arrays
//i can't change the value in the array or the where it points to
void printArray( const int * const, int, int ); //print a 1d array
void sort( int *, int ); //sort the array 

//execution begins here at main
int main( int argc, char **argv ) {
    //set random number seed
    srand( time( 0 ) );
    //declare variables
    int length;
    int rows, cols;
    int *array1D;
    int **array2D; //== int array[rows][cols]
    //initialize variables
    length = 100;
    array1D = fillArray( length );
    array2D = fillArray( rows, cols );
    //map/process the inputs -> outputs

    //display input/outputs
    //do 1d array
    cout << "here is the 1 dimensional array" << endl;
    cout << "Your new array looks like this: " << endl;
    printArray( array1D, length, 25 );

    //sort the array
    sort( array1D, length );

    cout << "your array sorted looks like this 😏" << endl;
    printArray( array1D, length, 25 );

    //do the 2d array
    cout << "here is the 2 dimensional array" << endl;
    cout << "Your new array looks like this: " << endl;
    printArray( array2D, rows, cols );

    //sort the array
    sort( array2D, rows, cols );

    cout << "your array sorted looks like this 😏" << endl;
    printArray( array2D, rows, cols );

    cout << "╰(*°▽°*)╯";
    //clean up memory, close files
    cleanup( array1D );
    cleanup( array2D );

    //exit the program
    return 0;
}

//sizes a 1d array and return the pointer
int *fillArray( int size ){
    //allocate the space
    int *array = new int[size];
    //file it with randoms
    for( int i = 0; i < size; i++ ){
        array[i] = rand() % 90 + 10; //[10-99] numbders
    }

    return array;
}

int **fillArray( int rows, int cols ){
    int **array = new int*[rows]; //i want an array of arrays 
    for( int i = 0; i < rows; i++ ){
        array[i] = new int[cols];
        for( int j = 0; j < cols; j++ ){
            array[i][j] = rand() % 90 + 10; //[10-99] range
        }
    }
}

//print a 1d array
void printArray( const int * const array, int length, int perLine ){
    for (int i = 0; i < length; i++) {
        cout << array[i] << " ";
        if( ( i + 1 ) % perLine == 0 )
            cout << endl;
    }
    cout << endl;    
}

//sort the 1d array
void sort( int *array, int length ){
    for( int i = 0; i < length - 1; i++ ){
        for( int j = i + 1; j < length; j++ ){
            if( array[i] > array[j] ){ //if 0th element is biiger than the 1st, swap em
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

void cleanup( int *array ){
    //delete the pointer
    delete [] array;
    return; //does nothing but return nothing
}

void cleanup( int **array, int rows ){
    for( int i = 0; i < rows; i++ ){
        delete [] array[i];
    }
    
    delete array;
}