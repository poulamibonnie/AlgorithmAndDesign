//---------------------------------------------------------------------------
// PET.H
// Declare members exclusive to Person class.
// Author(s): Poulami Das Ghosh
//---------------------------------------------------------------------------
// Pet class:  This is a derived class to Entity and stores the preference
//   queue of an object(Pet). It includes the following features:
//   -- Inherits all the public members of Entity class.
//   -- Set the reverse Index Pref list(rank) for the object(Pet)
//   -- Returns the reverse Index or rank of the person in the object's(Pet) 
//      prefernce list

// Assumptions:
//   -- 'prefList' is recieved as input from the input file and should 
//       contain space delimited numbers representing the Pets
//   -- 'size' is a integer type variable indicating the size of perfList 
//       after splitting
//---------------------------------------------------------------------------

#ifndef PET_H
#define PET_H

#include<iostream>
#include <vector>
#include <sstream>
#include "Entity.h"

using namespace std;

class Pet : public Entity {
    private:
        vector<int> revIdxPrefList;
    
    public:
//-------------------------- Constructor -----------------------------------//
// Default Constructor for the class Pet
// Preconditions:  None
// Postconditions: New object is created of type Pet

        Pet(){}

//-------------------------- Constructor -----------------------------------//
// Parametrized Constructor for the class Pet. It inherits all the public 
// members of Entity class.
// Preconditions:  Valid string containing the name of the object is provided 
//                 as input.
// Postconditions: New object of type Pet is created with name as input string
//                  and match as -1 indicating no item matched

        Pet(const string &name);

//-------------------------- getRevIdxPreference-------------------------------//
// Function to find the reverse Index or rank of the person in the object's 
// (Pet) prefernce list in O(1) TC
// Preconditions: Valid integer representing the index of the Person who 
//                proposed(now or previously)
// Postconditions: Returns the rank of the person who proposed

        int getRevIdxPreference(const int &idx);

//-------------------------- setRevIdxPreference------------------------------//
// Function to find the reverse Index or rank of the person in the object's
// (Pet) prefernce list in O(1) TC
// Preconditions:  A valid integer 'size' is received indicating the number 
//                 of Person
// Postconditions: ReverseIndex of preference list is set indicating the rank 
//                 of each preference.

        void setRevIdxPreference(const string &prefList, const int &size);

};

#endif