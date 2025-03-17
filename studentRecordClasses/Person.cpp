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