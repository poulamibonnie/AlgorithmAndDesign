//---------------------------------------------------------------------------
// DRIVER.CPP
// This is the driver function that will be used to run the application.
// Author(s): Poulami Das Ghosh
//---------------------------------------------------------------------------
// This file contains the main() method that will execute all other methods.
//
// Assumptions:
//   -- The input file name will be program1data.txt
//   -- The input file will be available in the same location.
//---------------------------------------------------------------------------

#include "DataReader.h"
#include "Entity.h"
#include "Person.h"
#include "Pet.h"
#include "StableMatching.h"

//---------------------------- Main -----------------------------------
// Main function for getting the stable matching using Gale-Shapely
// algorithm.
// Preconditions:   An input file with name program1data.txt needs to be
//                  available in the same location as the source files with
//                  the input data in the desired format.
// Postconditions:  The stable matching will be displayed in the console.
//                  Each line in the output contains the name of one person
//                  and one pet separated by " / ". This implies that the
//                  person is matched to that pet based on the Gale-Shapley
//                  algorithm. There will be as many lines in the output as
//                  the number of persons (or pets). Also the output is 
//                  optimal to persons.
int main() {

    try {
        // Read input from the file
        DataReader reader;
        reader.fileRead("program1data.txt");

        StableMatching matcher;

        // Set the list of Persons
        matcher.setOptimals(reader.getFirstParty());

        // Set the list of Pets
        matcher.setPessimals(reader.getSecondParty());

        // Get stable matching using Gale-Shapley's algorithm
        matcher.solver();

        // Print stable matches
        matcher.printStableMatch();
    }
    catch (...) {
        std::cerr << "Stable Matching Failed" << std::endl;
        return 0;
    }

    return 0;
}