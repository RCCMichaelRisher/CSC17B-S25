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

//structs
struct Array1D{
    int *data;
    int size;
};

struct Array2D{
    int *data;
    int rows;
    int cols;
};

//function prototypes
Array1D fillArray( int ); //sizes a 1d array and return the pointer
Array2D fillArray( int, int ); //sizes a 2d array and return the pointer
void cleanup( Array1D ); //free up memory from 1d arrays
void cleanup( Array2D ); //free memory for 2d
//i can't change the value in the array or the where it points to
void printArray( const Array1D * const, int ); //print a 1d array
void printArray( Array2D ); //print 2d array
void sortArray( Array1D ); //sort the array 
void sortArray( Array2D ); //sort the 2d array

//execution begins here at main
int main( int argc, char **argv ) {
    //set random number seed
    srand( time( 0 ) );
    //declare variables
    int length;
    int rows, cols;
    Array1D array1D;
    Array2D array2D; //== int array[rows][cols]
    //initialize variables
    length = 100;
    rows = 10;
    cols = 10;
    array1D = fillArray( length );
    array2D = fillArray( rows, cols );
    //map/process the inputs -> outputs

    //display input/outputs
    //do 1d array
    cout << "here is the 1 dimensional array" << endl;
    cout << "Your new array looks like this: " << endl;
    printArray( &array1D, 25 );
    
    //sort the array
    sortArray( array1D );

    cout << "your array sorted looks like this 😏" << endl;
    printArray( &array1D, 25 );

    //do the 2d array
    cout << "here is the 2 dimensional array" << endl;
    cout << "Your new array looks like this: " << endl;
    printArray( array2D );

    //sort the array
    sortArray( array2D );

    cout << "your array sorted looks like this 😏" << endl;
    printArray( array2D );


    //clean up memory, close files
    cleanup( array1D );
    cleanup( array2D );

    //exit the program
    return 0;
}

//sizes a 1d array and return the pointer
Array1D fillArray( int size ){
    //allocate the space
    Array1D array;
    array.data = new int[size];
    array.size = size;
    //file it with randoms
    for( int i = 0; i < size; i++ ){
        array.data[i] = rand() % 90 + 10; //[10-99] numbders
    }

    return array;
}

Array2D fillArray( int rows, int cols ){
    Array2D array;
    array.data = new int[rows * cols]; //i want an array of arrays 
    array.rows = rows;
    array.cols = cols;
    for( int i = 0; i < rows; i++ ){
        for( int j = 0; j < cols; j++ ){
            array.data[i * cols + j] = rand() % 90 + 10; //[10-99] range
        }
    }
    return array;
}

//print a 1d array
void printArray( const Array1D * const array, int perLine ){
    for (int i = 0; i < array->size; i++) {
        cout << array->data[i] << " ";
        if( ( i + 1 ) % perLine == 0 )
            cout << endl;
    }
    cout << endl;    
}

void printArray( Array2D array ){
    for (int i = 0; i < array.rows; i++) {
        for( int j = 0; j < array.cols; j++ ){
            cout << array.data[i * array.cols + j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
}

//sort the 1d array
void sortArray( Array1D array ){
    for( int i = 0; i < array.size - 1; i++ ){
        for( int j = i + 1; j < array.size; j++ ){
            if( array.data[i] > array.data[j] ){ //if 0th element is biiger than the 1st, swap em
                int temp = array.data[i];
                array.data[i] = array.data[j];
                array.data[j] = temp;
            }
        }
    }
}

void sortArray( Array2D array ){
    for( int i = 0; i < array.rows; i++ ){
        //passing a portion of the 1d array by shifting the point to the beginning of the rows
        sortArray( Array1D{ array.data + ( i * array.cols ), array.cols } );
    }
}

void cleanup( Array1D array ){
    //delete the pointer
    delete [] array.data;
    return; //does nothing but return nothing
}

void cleanup( Array2D array ){
    delete [] array.data;
}