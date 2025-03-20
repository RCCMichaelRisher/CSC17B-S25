#ifndef Professor_H
#define Professor_H

#include <string>
#include "Person.hpp"

using namespace std;

class Professor : public Person{
    private: 
      string department;
      string email;
    public: 
      Professor(){}

      //setters
      void setDepartment( string d ) { department = d;}
      void setEmail( string e ) { email = e; }
      //getters

      //bye byeers
      virtual ~Professor(){}
      //fns
      virtual void print();
      void saveToFile( ofstream & ) const override;
      void loadFromFile( ifstream & ) override;
      
};


#endif /* Professor_H */