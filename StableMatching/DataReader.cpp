//---------------------------------------------------------------------------
// DATAREADER.CPP
// Defination of DATAREADER class members
// Author(s): Poulami Das Ghosh
//---------------------------------------------------------------------------
// DATAREADER class: This is the data reader class that is used to read 
// input from the file.
//   It includes the following features:
//   -- It reads and creates a list of objects (pet and person) from input 
//      file.
//   -- It reads and set the preference list for all object (pet and person) 
//      from input file.
//   -- It reads and set the entity size from the file which determines the 
//      size of the list of objects.
//   -- It allows data cleansing capability to ensure removal of speacial 
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
//   -- Here entitySize should be greater than 0
//---------------------------------------------------------------------------

#include "DataReader.h"

//-------------------------- Getter Method -----------------------------------//
// Getter method 'getFirstParty()' to return the list of persons.
// Preconditions None
// Postconditions Returns the list of Person in a vector

vector<Person> DataReader::getFirstParty() {
    return this->firstParty;
}

//-------------------------- Getter Method -----------------------------------//
// Getter method 'getSecondParty()' to return the list of persons.
// Preconditions None
// Postconditions Returns the list of pets in a vector

vector<Pet> DataReader::getSecondParty() {
    return this->secondParty;
}

//-------------------------- Getter Method ----------------------------------//
// Getter method 'getEntitySize()' to return the size of the list.
// Preconditions None
// Postconditions Returns the list size

int DataReader::getEntitySize() {
    return this->entitySize;
}

//-------------------------- getCleanseString -------------------------------//
// Method to ensure the input string is valid and in the range [A- Z][a-z][0-9]
// Preconditions:  None
// Postconditions: Returns valid string with characters in the range
//                 [A- Z][a-z][0-9]. In case multiple word input is received,
//                 this function ensures each word is seperated by exactly one
//                 space in the output. If the cleansed string is empty, the
//                 program will return an error.

string DataReader::getCleanseString(const string &inputText) {
    string cleanseStr = "";
    for(int i = 0; i < inputText.size(); i++) {
        // Ensure that all characters are in range [A- Z][a-z][0-9]
        if ((inputText[i] >= 'A' && inputText[i] <= 'Z') || 
            (inputText[i] >= 'a' && inputText[i] <= 'z') ||
            inputText[i] >= '0' && inputText[i] <= '9') {
            cleanseStr += inputText[i];
        }
        // Ensuring we retain a space between words in case of
        // multi word string
        else if (!cleanseStr.empty() && inputText[i] == ' '
                && cleanseStr.back() != ' ') {
            cleanseStr += inputText[i];
        }
    }

    // Checking if the resultant string is blank
    if (cleanseStr.empty()) {
        std::cerr << "Error: Empty or invalid name being set" << std::endl;
        throw 0;
    }

    return cleanseStr;
}

//-------------------------- readEntitySize ----------------------------------//
// Method to read valid entity size from the file input.
// Preconditions:  None
// Postconditions: Returns valid int type entity size from the file or throws
//                 error for invalid entries. 
//                 [ Valid 'entitySize' range [1 - 100] ]
//                 [ Valid 'entitySize' should be an integer. ]

void DataReader::readEntitySize(const string &inputText) {
    try {
        // Convert input string to integer and store as entity size
        this->entitySize = stoi(inputText);

        // Validate that entity size is in the allowed range
        // If it is not, throw an error and exit
        if (this->entitySize < 1) {
            std::cerr << "Error: Entity Size should be greater than 0" << endl;
            throw 0;
        }
    }
    // The catch blocks handle any exceptions thrown by stoi().
    // The error is reported and then we exit.
    catch (const std::invalid_argument & e) {
        std::cerr << "Error: Entity Size [" << e.what() << "]" << endl;
        throw 0;
    }
    catch (const std::out_of_range & e) {
        std::cerr << "Error: Entity Size [" << e.what() << "]" << endl;
        throw 0;
    }

    return;
}

//-------------------------- readAndCreateFirstparty --------------------------//
// Method to read and create 'Person' type object.
// Preconditions:  None
// Postconditions: Reads and create new 'Person' type object for each entry of 
//                 valid name in the file and store them in vector 'firstParty'

void DataReader::readAndCreateFirstparty(const string &inputText) {
    try {
        Person firstPartyMember = Person(getCleanseString(inputText));
        this->firstParty.push_back(firstPartyMember);
    }
    catch (...) {
        throw 0;
    }
    
    return;
}

//-------------------------- readAndCreateSecondparty --------------------------//
// Method to read and create 'Pet' type object.
// Preconditions:  None
// Postconditions: Reads and create new 'Pet' type object for each entry of 
//                 valid name in the file and store them in vector 'secondParty'

void DataReader::readAndCreateSecondparty(const string &inputText) {
    try {
        Pet secondPartyMember = Pet(getCleanseString(inputText));
        this->secondParty.push_back(secondPartyMember);
    }
    catch (...) {
        throw 0;
    }
    return;
}

//-------------------------- readFirstPartyPref -----------------------------//
// Method to read and set the preference list of a person based on index
// Preconditions:  An integer input 'Idx' indicating the index of the object  
//                 whose preference list is being set.
// Postconditions: The function sets preference as the property for each object 
//                 based on 'idx'. If the inputText is empty the program 
//                 shall return error.
void DataReader::readFirstPartyPref(const string &inputText, const int &idx)
{
    if (inputText.empty()) {
        std::cerr << "Error: Empty preference list is being set for Person" 
        << std::endl;
        throw 0;
    }
    try {
        this->firstParty[idx].setPreference(inputText, getEntitySize());
    }
    catch (...) {
        throw 0;
    }
    return;
}

//-------------------------- readSecondPartyPref ----------------------------//
// Method to read and set the preference list of a pet based on index
// Preconditions:  An integer input 'Idx' indicating the index of the object  
//                 whose preference list is being set.
// Postconditions: The function sets preference as the property for each object 
//                 based on 'idx'. If the inputText is empty the program shall 
//                 return error.
void DataReader::readSecondPartyPref(const string &inputText, const int &idx)
{ 
    if (inputText.empty()) {
        std::cerr << "Error: Empty preference list is being set for Pet" 
        << std::endl;
        throw 0;
    }
    try {
        this->secondParty[idx].setRevIdxPreference(inputText, getEntitySize());
    }
    catch (...) {
        throw 0;
    }
    return;
}

//-------------------------- fileRead ---------------------------------------//
// Method to read the file line by line
// Preconditions:   An input file with name program1data.txt needs to be
//                  available in the same location as the source files with
//                  the input data in the desired format.
// Postconditions:  Read a validly formatted file. If the file is empty or
//                  the program is unable to open the file, an error is
//                  returned.
void DataReader::fileRead(const string &filename) {
    ifstream inputFile(filename);
    string myText;
    int loopCounter = 0;

    if (!inputFile.is_open()) {
        // Failed to open file, report error and exit
        std::cerr << "Error opening the file." << std::endl;
        throw 0;
    }

    if (inputFile.peek() == std::ifstream::traits_type::eof()) {
        // File is empty, report error and exit
        std::cerr << "Error: Empty File" << std::endl;
        inputFile.close(); 
        throw 0; 
    }
    
    try {
        while (getline (inputFile, myText)) {
            if (loopCounter == 0) {
                // If it is the first line, interpret the text as
                // number of people/pets
                readEntitySize(myText);
            }
            else if (loopCounter >= 1 && loopCounter <= this->entitySize){
                // For lines 2 to n+1, interpret the text as names
                // of people
                readAndCreateFirstparty(myText);
            }
            else if (loopCounter >= this->entitySize + 1
                    && loopCounter <= (this->entitySize * 2)) {
                // For lines n+2 to 2n+1, interpret the text as preference
                // lists of people
                readFirstPartyPref(myText, (loopCounter - this->entitySize - 1));
            }
            else if (loopCounter >= (this->entitySize * 2) + 1
                    && loopCounter <= (this->entitySize * 3)) {
                // For lines 2n+2 to 3n+1, interpret the text as names of pets
                readAndCreateSecondparty(myText);
            }
            else if (loopCounter >= (this->entitySize * 3) + 1
                    && loopCounter <= (this->entitySize * 4)) {
                // For lines 3n+2 to 4n+1, interpret the text as preference
                // lists of pets.
                readSecondPartyPref(myText,
                                    (loopCounter - (3 * this->entitySize) - 1));
            }

            loopCounter++;
        }
        
    }
    catch (...) {
        inputFile.close();
        throw 0;
    }
        
    inputFile.close();
    return;
}
