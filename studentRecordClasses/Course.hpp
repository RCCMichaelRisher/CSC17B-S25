#ifndef Course_H
#define Course_H

#include "Student.hpp"
#include "Professor.hpp"
#include <string>

using namespace std;

class Course {
    private: 
      int numStudents;
      Student *students;
      Professor *professor;
      string name;
    public: 
      Course(){}
      Course( int, string );
      //getters
      int getNumStudents() const { return numStudents;}    
      Student *getStudents () const { return students;}
      Professor *getProfessor () const { return professor;}
      string getName () const { return name;}

      //setters
      
      //destructor
      virtual ~Course(){
        delete [] students;
        delete professor;
      }

      //other fns
      void print();
      void inputStudents();
      void inputProfessor();
      void saveToFile( string filename );
      void loadFromFile( string filename );

    
      
};


#endif /* Course_H */