//---------------------------------------------------------------------------
// PERSON.CPP
// Defination of members exclusive to Person class.
// Author(s): Poulami Das Ghosh
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

#include "Person.h"

//-------------------------- Constructor -----------------------------------//
// Parametrized Constructor for the class Person. It inherits all the public 
// members of Entity class.
// Preconditions:  Valid string containing the name of the object is provided as input.
// Postconditions: New object is created with name as input string and match as -1 
//        indicating no item matched

Person::Person(const string &name) : Entity(name) {};

//-------------------------- getPreference-----------------------------------//
// Output the prefrerence queue of an object(Person)
// Preconditions:  None
// Postconditions: Returns integer queue containing the preference list of 
//                 the object(Person)

queue<int> Person::getPreference() {
    return this->preferences;
}

//-------------------------- setPreference-----------------------------------//
// Set the preference queue for an object(Person)
// Preconditions:  A valid integer 'size' is received indicating the number 
//                 of Person
// Postconditions: Insert into the queue in order of preference. If the  
//                 preference list queue cannot be constructed due to invalid
//                 input throw error. 
                 
void Person::setPreference(const string &prefList, const int &size) {
    vector<int> prefSet(size + 1, -1);
    stringstream ss(prefList);
    string pref;
    int numPref = -1;
    int counter = 0;

    // Extract space seperated number through tokenization
    while (ss >> pref) 
    {
        try {
            counter++;
            //Assigning preference
            numPref = stoi(pref);
            
            if (numPref < 1 || numPref > size) {
                // Throw error if incorrect preference index is set 
                std::cerr <<"Error: Invalid Preference Being Set For Person" << endl;
                throw 0;
            }
            else if (prefSet[numPref] != -1) {
                // Throw error if duplicate preference index is set 
                std::cerr <<"Error: Duplicate Preference Being Set For Person" << endl;
                throw 0;
            }

            this->preferences.push(numPref);
            prefSet[numPref] = 1;

        }
        catch (const std::invalid_argument & e) {
            // Throw error if input Person's Preference is invalid
            std::cerr << "Error: Person Preference [" << e.what() << "]" << endl;
            throw 0;
        }
        catch (const std::out_of_range & e) {
            // Throw error if input Person's Preference is outsize integer range
            std::cerr << "Error: Person Preference [" << e.what() << "]" << endl;
            throw 0;
        }
    }

    if (counter != size) {
        // Throw if the Preference List size doesn't match entity size 
        std::cerr <<"Error: Person's Preference List Size Incorrect." << endl; 
        throw 0;
    }

    return;
}  

//-------------------------- getTopPreference -------------------------------//
// Outputs the top preference of pet
// Preconditions: None
// Postconditions: returns the index of the top pet prefered 

int Person::getTopPreference() {
    // Empty preferences queue indicates no new pet to propose
    if (preferences.empty()) {
        return -1;
    }

    // Get the top preference and remove it from queue
    int pref = this->preferences.front();
    this->preferences.pop();
    return pref;
}   

