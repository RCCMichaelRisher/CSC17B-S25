#include <iostream>

using namespace std;

#include "Professor.hpp"
#include "Person.hpp"

void Professor::print(){
    cout << "Professor ";
    Person::print(); //call the base print function
    cout << "Department: " << department << endl;
    cout << "Email: " << email << endl;

}

void Professor::saveToFile( ofstream &outfile ) const {
    int strLen;
    //write the dept
    strLen = department.size();
    outfile.write( reinterpret_cast<const char *>( &strLen ), sizeof( strLen ) );
    outfile.write( department.c_str(), strLen );

    //write the email
    strLen = email.size();
    outfile.write( reinterpret_cast<const char *>( &strLen ), sizeof( strLen ) );\
    outfile.write( email.c_str(), strLen );
}

void Professor::loadFromFile( ifstream &infile ){
    Person::loadFromFile( infile );

    int strSize;
    //write the dept
    //read in the length of deptartment
    infile.read( reinterpret_cast<char *>( &strSize ), sizeof( strSize ) );
    char *temp = new char[strSize + 1];
    infile.read( temp, strSize );
    temp[strSize] = '\0';
    department = string( temp );
    delete temp;

    //read in the length of email
    infile.read( reinterpret_cast<char *>( &strSize ), sizeof( strSize ) );
    temp = new char[strSize + 1];
    infile.read( temp, strSize );
    temp[strSize] = '\0';
    email = string( temp );
    delete temp;
}