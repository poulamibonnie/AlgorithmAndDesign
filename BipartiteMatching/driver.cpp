//---------------------------------------------------------------------------
// DRIVER.CPP
// This is the driver function that will be used to run the application.
// Author(s): Poulami Das Ghosh
//---------------------------------------------------------------------------
// This file contains the main() method that will execute all other methods.
//
// Assumptions:
//   -- The input file name will be program3data.txt
//   -- The input file will be available in the same location.
//---------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <queue>
#include "DataReader.h"
#include "Dinitz.h"

using namespace std;

//---------------------------- Main -------------------------------------------
// Main function for getting the Bipartite matching using Dinitz algorithm
// Preconditions:   An input file with name program3data.txt needs to be
//                  available in the same location as the source files with
//                  the input data in the desired format.
// Postconditions: The Bipartite matching will be displayed in the console.
//                  Each line in the output contains the name of one person
//                  and one pet separated by " / ". This implies that the
//                  person is matched. Also some of the parties may remain 
//                  unmatched. Additionally we need to print the number of valid 
//                  matches. 

int main() {

    try {
        // Read input from the file
        DataReader reader;
        reader.fileRead("program3data.txt");
    
        // Call the solver method to find the Bipartite pair
        Dinitz solver(reader);
        solver.getBipartiteMatch();

        // Print the Bipartite pair
        solver.printBipartiteMatch(reader);
            
    }
    catch (...) {
        std::cerr << "Finding Bipartite Match Failed" << std::endl;
        return 0;
    }

    return 0;
}
