//---------------------------------------------------------------------------
// DATAREADER.H
// Declaration of DATAREADER class members
// Author(s): Poulami Das Ghosh
//---------------------------------------------------------------------------
// DATAREADER class: This is the data reader class that is used to read 
// input from the file.
//   It includes the following features:
//       * Read the number of nodes and edges of the graph.
//       * Read & assign the name of each person (node).
//       * Construct an adjacency list based on the edges provided as input
//
// Assumptions:
//   -- The input file will always be available in the same directory.
//   -- While building the adjacency list we assume the edges are from
//      left half to right half
//   -- File Format:
//      * The first line will hold the number of nodes n, which will be even.
//      * The next n/2 lines will store the names of items to be matched in the 
//        “left” set.
//      * n/2 further lines will store the names of items to be matching in the
//         “right” set.
//      * Next, the number of edges will be stored and following that will
//        be the edges (one per line)
//---------------------------------------------------------------------------

#ifndef DATAREADER_H
#define DATAREADER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>


using namespace std;

class DataReader {
private:
    int numNodes;
    vector<string> nameList;
    int numEdges;
    vector<vector<int> > adjList;

    //-------------------------- readNumNode ---------------------------------//
    // Method to read the number of points
    // Preconditions:  None
    // Postconditions: Return valid number of nodes int the size or else 
    //                 throw exception. A valid input can only be an even integer

    void readNumNode(const string& inputText);

    
    //-------------------------- getCleanseString -------------------------------//
    // Method to ensure the input is either string [a - z] [A - Z] [0 - 9]
    // Preconditions:  None
    // Postconditions: This function cleanse the input string

    string getCleanseString(const string& inputText) const;

    //-------------------------- readNumEdges -------------------------------//
    // Method to read the number of edges in the graph
    // Preconditions:  None
    // Postconditions: Return if the number of edge is valid else throw 
    //                 exception

    void readNumEdges(const string& inputText);

    //-------------------------- splitStrOnSpace -------------------------------//
    // Method to split the input on space
    // Preconditions:  None
    // Postconditions: Return space seperated string
    vector<string> splitStrOnSpace(const string& inputText) const;

public:
    //-------------------------- Constructor -----------------------------------//
    // Default Constructor for the class DataReader
    // Preconditions: None
    // Postconditions: New object is created

    DataReader();

    //-------------------------- setName ------------------------//
    // Method to read the name of the entity.
    // Preconditions:  None
    // Postconditions: Read the name of the entity;

    void setName(const string &inputText, int idx);

    //-------------------------- Getter Method -----------------------------------//
    // Method to get the name of entity based 1-indexed array
    // Preconditions: None
    // Postconditions: Name of the entity

    string getName(const int &idx) const;


    //-------------------------- Getter Method -----------------------------------//
    // Getter method 'getNumNodes()' to return the number of nodes.
    // Preconditions: None
    // Postconditions: Returns the number of nodes

    int getNumNodes() const;

    //-------------------------- Setter Method -----------------------------------//
    // Setter method 'setNumNodes()' to set the number of nodes of the graph.
    // Preconditions: None
    // Postconditions: None

    void setNumNodes(const int& _numNodes);

    //-------------------------- Setter Method -----------------------------------//
    // Setter method 'setNumEdges()' to set the number of edges of the graph.
    // Preconditions: None
    // Postconditions: None

    void setNumEdges(const int& numOfEdges);

    //-------------------------- readEdge  ------------------------------------//
    // This method is used to read the egdes from the file
    // Preconditions: None
    // Postconditions: None   

    void readEdge(const string &inputText);

    //-------------------------- setAdjList  ------------------------------------//
    // This method is used to create adjacency list based on the edges provided
    // Preconditions: None
    // Postconditions: Node  

    void setAdjList(const int&node1, const int&node2, const int &val);

    //-------------------------- getAdjList  ------------------------------------//
    // This method is used return the adjacency list for a node.
    // Preconditions: None
    // Postconditions: Returns the adjacency list for a node.

    vector<int> getAdjList(const int& node) const;
    

    //-------------------------- fileRead ---------------------------------------//
    // Method to read the file line by line
    // Preconditions:   An input file with name program2data.txt needs to be
    //                  available in the same location as the source files with
    //                  the input data in the desired format.
    // Postconditions:  Read a validly formatted file. If the file is empty or
    //                  the program is unable to open the file, an error is
    //                  returned.

    void fileRead(const string& filename);

};

#endif
