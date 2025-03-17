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