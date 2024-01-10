//---------------------------------------------------------------------------
// PERSON.CPP
// Defination of members exclusive to Person class.
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

#include "Person.h"

//-------------------------- Constructor -----------------------------------//
//Parametrized Constructor for the class Person. It inherits all the public 
//members of Entity class.
//Input: Valid string containing the name of the object is provided as input.
//Output: New object is created with name as input string and match as -1 
//        indicating no item matched

Person::Person(string name) : Entity(name) {};

//-------------------------- getPreference() -----------------------------------//
//Output the prefrerence queue of an object(Person)
//Input: None
//Output: Returns integer queue containing the preference list of the object(Person)

queue<int> Person::getPreference() {
    return this->preferences;
}

//-------------------------- setPreference(prefList) -----------------------------------//
//Set the preference queue for an object(Person)
//Input: string containing the preference list
//Output: None 

void Person::setPreference(const string &prefList) {
    stringstream ss(prefList);
    string pref;
    
    // Extract space seperated number through tokenization
    while (ss >> pref) 
    {
        try {
            this->preferences.push(stoi(pref));
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
}  

//-------------------------- getTopPreference() -----------------------------------//
//Outputs the top preference of pet
//Input: None
//Output: returns the index of the top pet prefered 

int Person::getTopPreference() {
    // Empty preferences queue indicates no new pet to propose
    if(preferences.empty()) {
        return -1;
    }

    // Get the top preference and remove it from queue
    int pref = this->preferences.front();
    this->preferences.pop();
    return pref;
}   

