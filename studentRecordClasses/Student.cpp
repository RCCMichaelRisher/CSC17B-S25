#include <iostream>
#include <iomanip>

using namespace std;

#include "Student.hpp"

void Student::print() const {
    cout << left << setw( 10 ) << "Name: " << name << endl;    
    cout << left << setw( 10 ) << "Id: " << id  << endl;
    cout << left << setw( 10 ) << "Grades: [";
    for( int i = 0; i < nGrades; i++ ){
        cout << grades[i] << ", ";
    }
    cout << "]" <<endl;
    cout << left << setw(10 ) <<  "Avg: " << avg << endl;
}

void Student::calvAvg() {
    this->avg = 0;
    for( int i = 0; i < nGrades; i++ ){
        this->avg += grades[i];
    }
    this->avg /= nGrades + 0.0f;
}

void Student::saveToFile( ofstream &outfile ) const {
    //write name & id 
    Person::saveToFile( outfile );
    //grade & ngrades
    //need to do ngrades first so when i load it I know how long the grades section is binary
    outfile.write( reinterpret_cast<const char *>( &nGrades ), sizeof( nGrades ) );
    //print grades
    //the size is the size of a single int times the length of the array
    outfile.write( reinterpret_cast<const char *>( grades ), sizeof( int ) * nGrades  );

    //write avg
    outfile.write( reinterpret_cast<const char *>( &avg ), sizeof( avg ) );
}

void Student::loadFromFile( ifstream &infile ){
    Person::loadFromFile( infile );
    //grade & ngrades
    //need to do ngrades first so when i load it I know how long the grades section is binary
    infile.read( reinterpret_cast<char *>( &nGrades ), sizeof( nGrades ) );
    //allocate memory
    grades = new int[5];
    //the size is the size of a single int times the length of the array
    infile.read( reinterpret_cast<char *>( grades ), sizeof( int ) * nGrades  );

    //write avg
    infile.read( reinterpret_cast<char *>( &avg ), sizeof( avg ) );
}