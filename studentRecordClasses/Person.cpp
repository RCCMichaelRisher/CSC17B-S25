#include <string>
#include <iostream>

using namespace std;
#include "Person.hpp"


Person::Person( string name, int id ){
    this->id = id;
    this->name = name;
}

void Person::print() const {
    cout << "Name: " << name << endl;
    cout << "Id: " << id << endl;
}

void Person::saveToFile( ofstream &outfile ) const {
    //name
    int nameLen = name.size();
    //print str size
    outfile.write( reinterpret_cast<const char *>( &nameLen ), sizeof( nameLen ) );
    outfile.write( name.c_str(), nameLen );
    //id
    outfile.write( reinterpret_cast<const char *>( &id ), sizeof( id ) );
}

void Person::loadFromFile( ifstream &infile ){
    //name
    int nameLen;
    infile.read( reinterpret_cast<char *>( &nameLen ), sizeof( nameLen ) );
    char *temp = new char[ nameLen + 1 ];
    infile.read( temp, nameLen );
    temp[nameLen] = '\0';
    this->name = temp;
    //free the mem
    delete [] temp;
    //id
    infile.read( reinterpret_cast<char *>( &id ), sizeof( id ) );
}