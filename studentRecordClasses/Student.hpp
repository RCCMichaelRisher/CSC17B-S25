#ifndef Student_H //if not defined
#define Student_H

using namespace std;
#include "Person.hpp"

class Student : public Person {
    private: 
        int *grades;
        int nGrades;
        float avg; 
    public:
        //constructors
        Student(){}
        Student( string name, int id, int nGrades ) : Person( name, id ), nGrades( nGrades ){
            grades = new int[nGrades];
            avg = 0;
        }
        //accessors
        int   getNGrades() const { return nGrades;}
        int  *getGrades() const { return grades;}
        float getAvg() const { return avg; }
        //mutator
        void setNGrades( int n ) { nGrades = n;}
        void setGrades( int *g ) { grades = g;}
        void setAvg( float a ) { avg = a; }
        //destructor
        virtual ~Student() {
            delete [] grades;
        }

        void print() const override;
        void calvAvg();

      
};


#endif /* Student_H */