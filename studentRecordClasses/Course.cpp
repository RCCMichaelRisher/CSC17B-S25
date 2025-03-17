#include <iostream>
#include <cstdlib>

using namespace std;


//include the dang header!!!!
#include "Course.hpp"

Course::Course( int num, string name ){
    this->name = name;
    this->numStudents = num;
    students = new Student[ numStudents ];
    professor = nullptr;
}

void Course::inputStudents(){
    for( int i = 0; i < numStudents; i++ ){
        //temp var to hold the address of where it is
        Student *s = &this->students[i];

        string inStr;
        int inDec;
        cout << "\nEnter details for student " << i+1 << endl;
        cout << "id: ";
        cin >> inDec;
        s->setId( inDec );
        cin.ignore();

        //get the name
        cout << "name: ";
        getline( cin, inStr );
        s->setName( inStr );

        //num of grades
        cout << "Enter number of grades: ";
        cin >> inDec;
        s->setNGrades( inDec );

        //make the grades
        int *temp = new int[inDec];
        for( int j = 0; j < inDec; j++ ){
            temp[j] = rand() % 101;
        }

        s->setGrades( temp );
        s->calvAvg();
    }
}

void Course::print(){
    cout << endl;
    cout << "Course Name: "  << name << endl;
    cout << "NUm students: " << numStudents << endl;
    if( professor != nullptr ){
        professor->print();
    }
    cout << "----Students----" << endl;
    for( int i = 0; i < numStudents; i++ ){
        this->students[i].print();
    }
}

void Course::inputProfessor(){
    Professor *p = new Professor;

    int inDec;
    string inStr;

    cout << "Input professor info" << endl;
    cout << "Faculty if:" << endl;
    cin >> inDec;
    cin.ignore();
    p->setId( inDec );

    //get the name
    cout << "name: ";
    getline( cin, inStr );
    p->setName( inStr );

    //get the email
    cout << "email: ";
    getline( cin, inStr );
    p->setEmail( inStr );

    //get the name
    cout << "Department: ";
    getline( cin, inStr );
    p->setDepartment( inStr );

    //set the pointer p to be that new field in Course
    this->professor = p;
}
void Course::saveToFile( string filename ){}
void Course::loadFromFile( string filename ){}