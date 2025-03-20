/* 
 * Author: Michael Risher
 * Purpose: student records with class 😉
 * 
 */

//System Libraries
#include <iostream>  //Input Output Library
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries
#include "Course.hpp"

//Global Constants not Variables
//Science, Math, Conversions, Dimensions

//Function Prototypes

//Execution begins here at main
int main(int argc, char** argv) {
    //Set random number seed
    srand( time( 0 ) );
    //Declare Variables
    string filename = "students.dat";
    int numStudents;
    string courseName;
    //Initialize Variables
    cout << "how many students: ";
    cin >> numStudents;
    cin.ignore();

    cout << "course name: ";
    getline( cin, courseName );
    
    Course *course = new Course( numStudents, courseName );

    //add students
    course->inputStudents();
    //add professor
    course->inputProfessor();
    //save?
    course->saveToFile( filename );
    //print the course
    course->print();
    //make the money
    
    delete course;

    //load it from the file this time
    cout << "\n\n\n\nLoading the course back from a file" << endl;
    Course *loadedCourse = new Course();
    loadedCourse->loadFromFile( filename );
    //print
    loadedCourse->print();
    // loadedCourse->getStudents()[0].debug();

    delete loadedCourse;
    //Exit the Program
    return 0;
}