//---------------------------------------------------------------------------
// PERSON.H
// Declare members exclusive to Person class.
// Authors: Poulami Das Ghosh
//---------------------------------------------------------------------------
// Person class:  This is a derived class to Entity and stores the preference
//   queue of an object(Person). It includes the following features:
//   -- Inherits all the public members of Entity class.
//   -- Set the preference queue for the object(Person)
//   -- Returns the preference queue for the object(Person)
//   -- Returns the top preference of the object(Person)

// Assumptions:
//   -- 'prefList' is recieved as input from the input file and should 
//       contain space delimited numbers representing the Pets
//---------------------------------------------------------------------------

#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <queue>
#include <sstream>
#include "Entity.h"

using namespace std;

class Person : public Entity {
    private:
        queue<int> preferences;
        
    public:
//-------------------------- Constructor -----------------------------------//
//Default Constructor for the class Person
//Input: None
//Output: New object is created
        Person(){}

//-------------------------- Constructor -----------------------------------//
//Parametrized Constructor for the class Person. It inherits all the public 
//members of Entity class.
//Input: Valid string containing the name of the object is provided as input.
//Output: New object is created with name as input string and match as -1 
//        indicating no item matched
  
        Person(const string &name);

//-------------------------- getPreference() -----------------------------------//
//Output the prefrerence queue of an object(Person)
//Input: None
//Output: Returns integer queue containing the preference list of the object(Person)

        queue<int> getPreference();

//-------------------------- setPreference(prefList) -----------------------------------//
//Set the preference queue for an object(Person)
//Input: (1) String containing the preference list
//       (2) Number of Pet/Person
//Output: None 

        void setPreference(const string &prefList, int &size);

//-------------------------- getTopPreference() -----------------------------------//
//Outputs the top preference of pet
//Input: None
//Output: returns the index of the top pet prefered 

        int getTopPreference();

};

#endif
