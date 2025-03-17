//include guards prevent multiple definitions
#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>

using namespace std;

class Person {
    private:
    protected:
        string name;
        int id;
    public:
        //constructors
        Person(){} //default constructor
        Person( string name, int id );
        //accessors / getters
        string getName() const { return name; }
        int getId() const { return id; }
        //mutator / setters
        void setName( string n ) { name = n; }
        void setId( int id )  { this->id = id; }
        //destructor
        virtual ~Person(){}

        //functions
        virtual void print() const;

};

#endif /* PERSON_HPP */