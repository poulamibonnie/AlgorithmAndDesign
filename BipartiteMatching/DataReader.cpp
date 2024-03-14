//---------------------------------------------------------------------------
// DATAREADER.CPP
// Defination of DATAREADER class members
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

#include "DataReader.h"

//-------------------------- Constructor -----------------------------------//
// Default Constructor for the class DataReader
// Preconditions: None
// Postconditions: New object is created

DataReader::DataReader() {
    this->numNodes = 0;
    this->numEdges = 0;
}

 //-------------------------- Setter Method -----------------------------------//
    // Setter method 'setNumNodes()' to set the number of nodes of the graph.
    // Preconditions: None
    // Postconditions: None

void DataReader::setNumNodes(const int& _numNodes) {
    this->numNodes = _numNodes;
}


//-------------------------- Getter Method -----------------------------------//
// Getter method 'getNumNodes()' to return the number of nodes.
// Preconditions: None
// Postconditions: Returns the number of nodes

int DataReader::getNumNodes() const {
    return this->numNodes;
}


//-------------------------- readNumNode ---------------------------------//
// Method to read the number of points
// Preconditions:  None
// Postconditions: Return valid number of nodes int the size or else 
//                 throw exception. A valid input can only be an even integer

void DataReader::readNumNode(const string& inputText) {
    int numOfNodes = 0;
    try {
        // Convert input string to integer and store as numOfNodes
        numOfNodes = stoi(inputText);

        // Validate the number of nodes is even and greater than 0
        if (numOfNodes % 2 != 0 || numOfNodes < 2) {
            std::cerr << "Error: Number Of nodes should be greater than 1 and even" << endl;
            throw 0;
        }
        
        // Set the number of nodes in the graph
        this->setNumNodes(numOfNodes);
       
    }
    // The catch blocks handle any exceptions thrown by stoi().
    // The error is reported and then we exit.
    catch (const std::invalid_argument& e) {
        std::cerr << "Error:  Number Of Nodes [" << e.what() << "]" << endl;
        throw 0;
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Error:  Number Of Nodes [" << e.what() << "]" << endl;
        throw 0;
    }
    return;
}


//-------------------------- setName ------------------------//
// Method to read the name of the entity.
// Preconditions:  None
// Postconditions: Read the name of the entity;

void DataReader::setName(const string& inputText, int idx) {
    this->nameList[idx] = getCleanseString(inputText); 
}


//-------------------------- Getter Method -----------------------------------//
// Method to get the name of entity based 1-indexed array
// Preconditions: None
// Postconditions: Name of the entity

string DataReader::getName(const int &idx) const {
    return this->nameList[idx];
}

//-------------------------- getCleanseString -------------------------------//
// Method to ensure the input is either string [a - z] [A - Z] [0 - 9]
// Preconditions:  None
// Postconditions: This function cleanse the input string

string DataReader::getCleanseString(const string& inputText) const {
    string cleanseStr = "";
    for (int i = 0; i < inputText.size(); i++) {
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

//-------------------------- readNumEdges -------------------------------//
// Method to read the number of edges in the graph
// Preconditions:  None
// Postconditions: Return if the number of edge is valid else throw 
//                 exception

void DataReader::readNumEdges(const string& inputText) {
    try {
        // Convert input string to integer and store as edges
        int numOfEdges = stoi(inputText);

        if (numOfEdges < 1) {
            std::cerr << "Error: Number Of Edges should be greater than 0" << endl;
            throw 0;
        }

        // Initiate the number of edges
        this->setNumEdges(numOfEdges);
    }
    // The catch blocks handle any exceptions thrown by stoi().
    // The error is reported and then we exit.
    catch (const std::invalid_argument& e) {
        std::cerr << "Error:  Number Of Edges [" << e.what() << "]" << endl;
        throw 0;
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Error:  Number Of Edges [" << e.what() << "]" << endl;
        throw 0;
    }
    return;
}

//-------------------------- Setter Method -----------------------------------//
// Setter method 'setNumEdges()' to set the number of edges of the graph.
// Preconditions: None
// Postconditions: None

void DataReader::setNumEdges(const int& numOfEdges) {
    this->numEdges = numOfEdges;
    return;
}

//-------------------------- readEdge  ------------------------------------//
// This method is used to read the egdes from the file
// Preconditions: None
// Postconditions: None   

void  DataReader::readEdge(const string &inputText) {
    istringstream ss(inputText);
    vector<string> edgeNodes;
    int node1, node2;
    int val = 1;

    try {
        edgeNodes = this->splitStrOnSpace(inputText);
        if (edgeNodes.size() != 2) {
            std::cerr << "Error: Invalid Edge" << endl;
            throw 0;
        }

        // Set Nodes
        node1 = stoi(edgeNodes[0]);
        node2 = stoi(edgeNodes[1]);

        // Creating an edge in the graph.
        this->setAdjList(node1, node2, val);
        
    }
    // The catch blocks handle any exceptions thrown by stoi().
    // The error is reported and then we exit.
    catch (const std::invalid_argument& e) {
        std::cerr << "Error: Node Edges [" << e.what() << "]" << endl;
        throw 0;
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Error:  Node Edges [" << e.what() << "]" << endl;
        throw 0;
    }
}

//-------------------------- setAdjList  ------------------------------------//
// This method is used to create adjacency list based on the edges provided
// Preconditions: None
// Postconditions: Node  

void DataReader::setAdjList(const int&node1, const int&node2, const int &val) {
    // Set it to 1 indicates there is an edge
    // Here we assume we have unidirection edge starting from 
    // left to right;
    this->adjList[node1][node2] = val;
}

//-------------------------- getAdjList  ------------------------------------//
// This method is used return the adjacency list for a node.
// Preconditions: None
// Postconditions: Returns the adjacency list for a node.

vector<int> DataReader::getAdjList(const int& node) const {
    return this->adjList[node];
}

//-------------------------- splitStrOnSpace -------------------------------//
// Method to split the input on space
// Preconditions:  None
// Postconditions: Return space seperated string

vector<string> DataReader::splitStrOnSpace(const string& inputText) const {
    vector<string> edge;
    istringstream ss(inputText);
    string edge_str;

    while (ss >> edge_str)
    {
        if (edge_str.empty()) {
            continue;
        }
        edge.push_back(edge_str);
    }

    return edge;
}

//-------------------------- fileRead ---------------------------------------//
// Method to read the file line by line
// Preconditions:   An input file with name program2data.txt needs to be
//                  available in the same location as the source files with
//                  the input data in the desired format.
// Postconditions:  Read a validly formatted file. If the file is empty or
//                  the program is unable to open the file, an error is
//                  returned.

void DataReader::fileRead(const string& filename) {
    ifstream inputFile(filename);
    string myText;
    int loopCounter = 0;
    int additionalNode = 2;
    
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
        while (getline(inputFile, myText)) {
            if (loopCounter == 0) {
                
                this->readNumNode(myText);
                this->nameList.resize(this->numNodes + 1);

                // We are creating a 1 indexed list and we also want to add 
                // Source and Sink
                this->adjList.resize(this->numNodes + additionalNode, vector<int> (this->numNodes + additionalNode, 0));
            }
            else if (loopCounter >= 1 && loopCounter <= this->numNodes) {
                
                this->setName(myText, loopCounter);
            }
            else if (loopCounter == this->numNodes + 1) {
                
                this->readNumEdges(myText);
            }
            else {
             
                this->readEdge(myText);
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
