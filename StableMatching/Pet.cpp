//---------------------------------------------------------------------------
// PET.CPP
// Defination of members exclusive to Person class.
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

#include "Pet.h"

//-------------------------- Constructor -----------------------------------//
// Parametrized Constructor for the class Pet. It inherits all the public 
// members of Entity class.
// Preconditions:  Valid string containing the name of the object is provided 
//                 as input.
// Postconditions: New object of type Pet is created with name as input string
//                  and match as -1 indicating no item matched

Pet::Pet(const string &name) : Entity(name) {}

//-------------------------- getRevIdxPreference-------------------------------//
// Function to find the reverse Index or rank of the person in the object's 
// (Pet) prefernce list in O(1) TC
// Preconditions: Valid integer representing the index of the Person who 
//                proposed(now or previously)
// Postconditions: Returns the rank of the person who proposed

int Pet::getRevIdxPreference(const int &idx) {
    return this->revIdxPrefList[idx];
}

//-------------------------- setRevIdxPreference------------------------------//
//Function to find the reverse Index or rank of the person in the object's
// (Pet) prefernce list in O(1) TC
// Preconditions:  A valid integer 'size' is received indicating the number 
//                 of Person

// Postconditions: ReverseIndex of preference list is set indicating the rank 
//                 of each preference. If the rank vector cannot be  
//                 constructed due to invalid input throw error.            

void Pet::setRevIdxPreference(const string &prefList, const int &size) {
    this->revIdxPrefList.resize(size + 1, -1);

    stringstream ss(prefList);
    string pref;
    int idx = 1, counter = 0;
    int numPref;

    // Extract space seperated number through tokenization
    while (ss >> pref) 
    {
        counter++;
        try {
            // Assigning rank to prefernce 
            numPref = stoi(pref);
            
            if (numPref < 1 || numPref > size) {
                // Throw error if incorrect preference index is set 
                std::cerr << "Error: Invalid Preference Being Set for Pet" << endl;
                throw 0;
            }
            else if (this->revIdxPrefList[numPref] != -1) {
                // Throw error if there are duplicates in preference list
                std::cerr << "Error: Duplicate Preference Being Set for Pet" << endl;
                throw 0;
            }

            this->revIdxPrefList[numPref] = idx++;
        }
        catch (const std::invalid_argument & e) {
            // Throw error if input Pet's Preference is invalid
            std::cerr << "Error: Pet Preference [" << e.what() << "]" << endl;
            throw 0;
        }
        catch (const std::out_of_range & e) {
            // Throw error if input Pet's Preference is outsize integer range
            std::cerr << "Error: Pet Preference [" << e.what() << "]" << endl;
            throw 0;
        }
    }

    if (counter != size) {
        // Throw if the Preference List size doesn't match entity size 
        std::cerr <<"Error: Pet's Preference List Size Incorrect." << endl; 
        throw 0;
    }
    
    return;
} 

