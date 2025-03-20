#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

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
void Course::saveToFile( string filename ){
    ofstream outfile( filename, ios::binary );
    //check file opened
    if( !outfile ){
        cout << "Error opening file for saving course" << endl;
        return;
    }
    //save the course to binary
    //save course
    int nameLen = name.size();
    //write the string size
    outfile.write( reinterpret_cast<char *>( &nameLen ), sizeof( nameLen ) );
    //write the actual string
    outfile.write( name.c_str(), nameLen );

    //write numStudents
    outfile.write( reinterpret_cast<char *>( &numStudents ), sizeof( numStudents ) );

    //save students
    for( int i = 0; i < numStudents; i++ ){
        students[i].saveToFile( outfile );
    }

    //check there is a prof
    bool hasProf = ( professor != nullptr );
    //wirte to the binary
    outfile.write( reinterpret_cast<char *>(&hasProf), sizeof( hasProf ) );
    if( hasProf ){
        //if you have them then print them
        professor->saveToFile( outfile );
    }

    //we done here 
    outfile.close();
}

void Course::loadFromFile( string filename ){
    ifstream infile( filename, ios::binary );
    if( !infile ){
        cout << "Error opening file for loading course" << endl;
        return;
    }

    //read the same order we wrote in
    //load course name
    int nameLen;
    infile.read( reinterpret_cast< char *>( &nameLen ), sizeof( nameLen ) );
    char *tempName = new char[ nameLen + 1 ]; //make a new char * with space for the null char \0 at the end
    infile.read( tempName, nameLen );
    tempName[ nameLen ] = '\0';
    this->name = string( tempName );
    delete [] tempName; //it was temporary, death was coming for it

    //num of students
    infile.read( reinterpret_cast< char * >( &this->numStudents ), sizeof( this->numStudents ) );

    //load student data
    this->students = new Student[ this->numStudents ];
    for( int i = 0; i < this->numStudents; i++ ){
        this->students[i].loadFromFile( infile );
    }
/*
    //has prof?
    bool hasProf;
    infile.read( reinterpret_cast<char *> ( &hasProf ), sizeof( hasProf ) );
    if( hasProf ){
        this->professor = new Professor();
        this->professor->loadFromFile( infile );
    } else{
        this->professor = nullptr;
    }
*/
    infile.close();
}