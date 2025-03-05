/*
Author: Michael Risher
Purpose: matrix multiplication O(n^3) time
*/

//system libraries
#include <iostream>  //input/output library
#include <ctime>    //time
#include <cstdlib> //rand srand
#include <iomanip> //format
using namespace std; //using namespace standard

//user libraries

//global constants not variable
//science, math, conversion, dimension

//function prototypes
int *fillMat( int );
void printMat( int *, int );
int *matMultiply( int *matA, int *matB, int dim ); //matrix multiply magic
void cleanup( int * );
//execution begins here at main
int main( int argc, char **argv ) {
    //set random number seed
    srand( time( 0 ) );
    //declare variables
    int *matA; //A side of the equation
    int *matB; //B side of the equation
    int *matResult; //outcome

    int dim;
    //initialize variables
    cout << "What is the dimension of the matrices" << endl;
    cin >> dim;

    matA = fillMat( dim );
    matB = fillMat( dim );
    //map/process the inputs -> outputs
    //do the math
    matResult = matMultiply( matA, matB, dim );

    //fill matrices A & B
    

    //do the math
    
    //display input/outputs
    cout << "Matrix A is: \n";
    printMat( matA, dim );
    cout << "Matrix B is: \n";
    printMat( matB, dim );

    //print the answer
    cout << "The result \n";
    printMat( matResult, dim );
    //clean up memory, close files
    cleanup( matA );
    cleanup( matB );
    cleanup( matResult );
    //exit the program
    return 0;
}

//fill the matrix into a 1D array
int *fillMat( int dim ){
    int *mat = new int[dim * dim];
    int n = dim * dim; //removed from the for loop for optimization
    for( int i = 0; i < n; i++ ){
        mat[i] = rand() % 9 + 1; // [1-10]
    }
    return mat;
}

//print function for the matrix
void printMat( int *mat, int dim ){
    for( int i = 0; i < dim; i++ ){ //rows 
        cout << "| ";

        for( int j = 0; j < dim; j++ ){ //cols
            //to access the other rows i need to do row * COLUMN(dim) + col
            if( dim <= 20 ){
                cout << setw( dim );
            }
            cout << mat[i * dim + j] << " ";
        }

        cout << "|" << endl;
    }
}

int *matMultiply( int *matA, int *matB, int dim ){
    /*
    how to do matrix mult
    1 2  5 6
    3 4  7 8
    time them together is 
    1*5+2*7  1*5+2*8
    3*5+4*7  3*6+4*8

    remember that AB != BA
    so dont mix it up!
    */

    //make the resulting matrix
    int *matResult = new int[ dim * dim ];

    //treat it like a 2d array yay
    for( int i = 0; i < dim; i++  ){ //rows
        for( int j = 0; j < dim; j++  ){ //cols
            matResult[i * dim + j ] = 0;
            //do the math here
            for( int k = 0; k < dim; k++ ){
                matResult[ i * dim + j ] += matA[i * dim + k] * matB[k * dim + j];
            }
        }
    }

    return matResult;
}

//cleanup the memory we used
void cleanup( int *mat ){
    delete [] mat;
}
