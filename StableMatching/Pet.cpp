//---------------------------------------------------------------------------
// PET.CPP
// Defination of members exclusive to Person class.
// Authors: Poulami Das Ghosh
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
//Parametrized Constructor for the class Pet. It inherits all the public 
//members of Entity class.
//Input: Valid string containing the name of the object is provided as input.
//Output: New object of type Pet is created with name as input string and match as -1 
//        indicating no item matched

Pet::Pet(const string &name) : Entity(name) {}

//-------------------------- getRevIdxPreference() -----------------------------------//
//Function to find the reverse Index or rank of the person in the object's(Pet) 
//      prefernce list in O(1) TC
//Input: Valid integer representing the index of the Person who proposed(now or previously)
//Output: Returns the rank of the person who proposed
int Pet::getRevIdxPreference(const int &idx) {
    return this->revIdxPrefList[idx];
}

//-------------------------- setRevIdxPreference(prefList, size) -----------------------------------//
//Function to find the reverse Index or rank of the person in the object's(Pet) 
//      prefernce list in O(1) TC
//Input: (1) String containing the preference list
//       (2) Number of Pet/Person
//Output: None

void Pet::setRevIdxPreference(const string &prefList, const int &size) {
    this->revIdxPrefList.resize(size + 1, -1);

    stringstream ss(prefList);
    string pref;
    int idx = 1, counter = 0;

    // Extract space seperated number through tokenization
    while (ss >> pref) 
    {
        counter++;
        try {
            // Assigning rank to prefernce 
            this->revIdxPrefList[stoi(pref)] = idx++;

        }
        catch (const std::invalid_argument & e) {
            std::cout <<"Error: Invalid Item For Person [" << e.what() << "]" << "\n";
            exit(0);
        }
        catch (const std::out_of_range & e) {
            std::cout <<"Error: Out Of Range Item For Person [" << e.what() << "]" << "\n";
            exit(0);
        }
    }

    if(counter != size) {
        std::cout <<"Error: Pet's Preference List Size Incorrect." << endl; 
        exit(0);
    }
} 

