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