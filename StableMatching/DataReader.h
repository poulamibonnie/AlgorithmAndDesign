//---------------------------------------------------------------------------
// DATAREADER.H
// Declaration of DATAREADER class members
// Author(s): Poulami Das Ghosh
//---------------------------------------------------------------------------
// DATAREADER class: This is the data reader class that is used to read 
// input from the file.
//   It includes the following features:
//   -- It reads and creates a list of objects (pet and person) from input 
//      file.
//   -- It reads and set the preference list for all objects (pet and person) 
//      from input file.
//   -- It reads and sets the entity size from the file which determines the
//      size of the list of objects.
//   -- It allows data cleansing capability to ensure removal of special 
//      characters.

// Assumptions:
//   -- The input file will always be available in the same directory.
//   -- The characters input text should be in range [A- Z][a-z][0-9] 
//      and not empty. 
//   -- File format:
//      Line 1: Number of people/pets (n)
//      Lines 2 to n+1: Names of people
//      Lines n+2 to 2n+1: Preference lists of people using indices,
//                         not names (n preferences per line)
//      Lines 2n+2 to 3n+1: Names of pets
//      Lines 3n+2 to 4n+1: Preference lists of pets using indices,
//                          not names (n preferences per line)
//   -- Here entitySize is in range [1 - 100]
//---------------------------------------------------------------------------

#ifndef DATAREADER_H
#define DATAREADER_H

#include <iostream>
#include <fstream>
#include <cassert>
#include "Entity.h"
#include "Person.h"
#include "Pet.h"

class DataReader { 
    private:
        vector<Person> firstParty;
        vector<Pet> secondParty;
        int entitySize;

//-------------------------- getCleanseString -------------------------------//
// Method to ensure the input string is valid and in the range [A- Z][a-z][0-9]
// Preconditions:  None
// Postconditions: Returns valid string with characters in the range
//                 [A- Z][a-z][0-9]. In case multiple word input is received,
//                 this function ensures each word is seperated by exactly one
//                 space in the output. If the cleansed string is empty, the
//                 program will return an error.


        string getCleanseString(const string &inputText);

//-------------------------- readEntitySize ---------------------------------//
// Method to read valid entity size from the file input.
// Preconditions:  None
// Postconditions: Returns valid int type entity size from the file or throws
//                 error for invalid entries. 
//                 [ Valid 'entitySize' range [1 - 100] ]
//                 [ Valid 'entitySize' should be an integer. ]

        void readEntitySize(const string &inputText);

//-------------------------- readAndCreateFirstparty ------------------------//
// Method to read and create 'Person' type object.
// Preconditions:  None
// Postconditions: Reads and create new 'Person' type object for each entry of 
//                 valid name in the file and store them in vector 'firstParty'

        void readAndCreateFirstparty(const string &inputText);

//-------------------------- readAndCreateSecondparty -----------------------//
// Method to read and create 'Pet' type object.
// Preconditions:  None
// Postconditions: Reads and create new 'Pet' type object for each entry of
//                 valid name in the file and store them in vector
//                 'secondParty'

        void readAndCreateSecondparty(const string &inputText);

//-------------------------- readFirstPartyPref -----------------------------//
// Method to read and set the preference list of a person based on index
// Preconditions:  An integer input 'Idx' indicating the index of the object  
//                 whose preference list is being set.
// Postconditions: The function sets preference as the property for each object 
//                 based on 'idx'. If the inputText is empty the program 
//                 shall return error.

        void readFirstPartyPref(const string &inputText, const int &idx);

//-------------------------- readSecondPartyPref ----------------------------//
// Method to read and set the preference list of a pet based on index
// Preconditions:  An integer input 'Idx' indicating the index of the object  
//                 whose preference list is being set.
// Postconditions: The function sets preference as the property for each object 
//                 based on 'idx'. If the inputText is empty the program shall 
//                 return error.

        void readSecondPartyPref(const string &inputText, const int &idx);

    public:
//-------------------------- Constructor -----------------------------------//
// Default Constructor for the class DataReader
// Preconditions: None
// Postconditions: New object is created

        DataReader() {
            entitySize = 0;
        }

//-------------------------- Getter Method -----------------------------------//
// Getter method 'getFirstParty()' to return the list of persons.
// Preconditions: None
// Postconditions: Returns the list of persons in a vector

        vector<Person> getFirstParty();

//-------------------------- Getter Method -----------------------------------//
// Getter method 'getSecondParty()' to return the list of persons.
// Preconditions: None
// Postconditions: Returns the list of pets in a vector

        vector<Pet> getSecondParty();

//-------------------------- Getter Method -----------------------------------//
// Getter method 'getEntitySize()' to return the size of the list.
// Preconditions: None
// Postconditions: Returns the list size

        int getEntitySize();

//-------------------------- fileRead ---------------------------------------//
// Method to read the file line by line
// Preconditions:   An input file with name program1data.txt needs to be
//                  available in the same location as the source files with
//                  the input data in the desired format.
// Postconditions:  Read a validly formatted file. If the file is empty or
//                  the program is unable to open the file, an error is
//                  returned.

        void fileRead(const string &filename);

};

#endif