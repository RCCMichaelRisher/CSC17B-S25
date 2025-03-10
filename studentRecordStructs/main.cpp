/*
Author: Michael Risher
Purpose: template to be used for all future homework, labs, exams, projects
*/

//system libraries
#include <iostream>  //input/output library
#include <cstdlib> //rnad
#include <ctime>
#include <string>
#include <iomanip>
#include <fstream> //files
using namespace std; //using namespace standard

//user libraries

//global constants not variable
//science, math, conversion, dimension

//structs

struct Student{
    string name;
    int id;
    int *grades; //array of grades
    int nGrades; //how many grades
    float avg; 
};

struct Roster {
    Student *students;
    int nStudents; //how many students
};


//function prototypes
void inputStudents( Roster * );
void printRoster( const Roster * );
void printStudent( const Student s );
void calcAvg( Student &s );
void load( string );
void saveRoster( Roster *, string );
void clean( Roster * );

//execution begins here at main
int main( int argc, char **argv ) {
    //set random number seed
    srand( time( 0 ) ); //set the rand seed
    //declare variables

    string filename = "students.dat"; //binary files
    int numStudents;
    Roster *roster;
    char choice;
    //initialize variables
    cout << "Load a file? ?! (y/n): ";
    cin >> choice;

    if( choice == 'y' ){
        cout << "What file do you want to load: ";
        cin >> filename;

        //load from file  & print
        load( filename );
    } else {
        cout << "How many students do you have: ";
        cin >> numStudents;

        //init roster
        roster = new Roster;
        roster->nStudents = numStudents;
        roster->students = new Student[numStudents];

        //input the data for students
        inputStudents( roster );

        //map/process the inputs -> outputs
        //save to file
        saveRoster( roster, filename );

        //display input/outputs
        printRoster( roster );

        //clean up memory, close files
        clean( roster );
    }
    
    //exit the program
    return 0;
}

/*
input data for students
*/
void inputStudents( Roster *roster) {
    for (int i = 0; i < roster->nStudents; i++)
    {
        cout << "\nEnter details for student " << i+1 << endl;
        cout << "ID: ";
        cin >> roster->students[i].id;
        cin.ignore(); //remove the newline that got left over

        cout << "Name: ";
        getline( cin, roster->students[i].name );

        //how many tests
        cout << "Enter number of test scores: ";
        cin >> roster->students[i].nGrades;
        //have to allocate the grade space first
        roster->students[i].grades = new int[ roster->students[i].nGrades ];
        for( int j = 0; j < roster->students[i].nGrades; j++ ){
            roster->students[i].grades[j] = rand() % 101;
        }

        calcAvg( roster->students[i] );
    }
    
}

//calculates the average grade
void calcAvg( Student &s ){
    s.avg = 0;
    for( int i = 0; i < s.nGrades; i++ ){
        s.avg += s.grades[i];
    }
    s.avg /= s.nGrades;
}

void printRoster( const Roster *r ){
    cout << "Roster" << endl;
    for (int i = 0; i < r->nStudents; i++) {
        cout << "Student " << i+1 << endl;
        printStudent( r->students[i] );
    }
    
}

void printStudent( const Student s ){
    cout << left << setw( 10 ) << "Name: " << s.name << endl;
    cout << left << setw( 10 ) << "ID: " << s.id << endl;
    cout << left << setw( 10 ) << "Tests: [";
    for (int i = 0; i < s.nGrades; i++) {
        cout << s.grades[i] << ", ";
    }
    cout << "]" << endl;
    cout << left << setw( 10 ) << "Average: " << s.avg << endl;
}

void saveRoster( Roster *r, string filename ){
    //open file in binary
    ofstream output( filename, ios::binary );
    //did open?
    if( output.good() ){
        //write stuffs
        //in binary file you can't do output << stuff
        output.write( reinterpret_cast<char *>( &r->nStudents ), sizeof( int ) ); //write num students
        //write the students
        for( int i = 0; i < r->nStudents; i++ ){
            output.write( reinterpret_cast<char *>( &r->students[i].id ), sizeof( int ) ); //write the id
            //get the size of the string
            int nameLen = r->students[i].name.size();
            output.write( reinterpret_cast<char *>( &nameLen ), sizeof( int ) ); //write the string size
            output.write( r->students[i].name.c_str(), nameLen ); //write the string as a char *
            output.write( reinterpret_cast<char *>( &r->students[i].nGrades ), sizeof( int ) ); //ngrades
            output.write( reinterpret_cast<char *>( r->students[i].grades ),
                r->students[i].nGrades * sizeof( int ) ); //write the array 
            output.write( reinterpret_cast<char *>( &r->students[i].avg ), sizeof( float ) ); //write the avg
        }
        //close the file
        output.close();
    } else {
        //console error instead of cout
        cerr << "Error: could not open file " << filename << endl;
    }
        
    //not error
}

void load( string filename ){
    //open file
    fstream in( filename, ios::in | ios::binary );
    //is good?
    if( in.good() ){
        //read stuff
        int nStudents;
        in.read( reinterpret_cast<char *>( &nStudents ), sizeof( int ) ); //get num
        //create roster & init
        Roster *ros = new Roster;
        ros->nStudents = nStudents;
        ros->students = new Student[nStudents];
        for( int i = 0; i < ros->nStudents; i++ ){
            in.read( reinterpret_cast<char *>( &ros->students[i].id ), sizeof( int ) ); //read id
            //read string aka char *
            int namelen;
            in.read( reinterpret_cast<char *>( &namelen ), sizeof( int ) );
            char *name = new char[namelen + 1];
            in.read( name, namelen ); //read the char * of name
            name[namelen] = '\0';
            ros->students[i].name = string( name );
            delete [] name;

            in.read( reinterpret_cast<char *>( &ros->students[i].nGrades ), sizeof( int ) ); //ngrades
            //allocate student grades
            ros->students[i].grades = new int[ ros->students[i].nGrades ];
            in.read( reinterpret_cast<char *>( ros->students[i].grades ),
                ros->students[i].nGrades * sizeof( int ) 
            ); //read in grades
            in.read( reinterpret_cast<char *>( &ros->students[i].avg ), sizeof( float ) ); //read in avg
        }
        in.close();
        //print the roster?
        printRoster( ros );
        //clean ros
        clean( ros );

    } else {
        //error?
        cerr << "Error: couldn't load file: " << filename << endl;
    }
}

void clean( Roster *r ){
    for( int i = 0; i < r->nStudents; i++ ){
        delete [] r->students[i].grades; //delete the in array first
    }
    delete [] r->students; //delete the students array
    delete r; //delete roster
}