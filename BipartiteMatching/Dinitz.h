//---------------------------------------------------------------------------
// DINITZ.H
// Declaration of DINITZ algorithm class member
// Author(s): Poulami Das Ghosh
//---------------------------------------------------------------------------
// This file contains the class variables and helper methods to do bipartite 
// matching using the Dinitz Algorithm.
// Here are the class variables:
//  - level => Stores the level of the nodes in the Graph. This is created
//             by doing BFS.
//  - lvlAdjList => This is the adjacency list of the level graph constructed
//  - adjList => This is the adjacency list of the residual graph constructed
//  - totalNumNodes => The total number of nodes in the graph including source
//                     and the sink.
//  The methods perform the following function:
//  - Add the source and sink
//  - Augment flow with path.
//  - Perform BFS and construct the level graph.
//  - Delete edges in path from the level graph.
//
// Assumptions:
//  - The nodes are inserted in the adjacency list based on 1-based indexing
//  - The source is assigned as 0th index and sink is the (n+1)th object in 
//    the array
//---------------------------------------------------------------------------

#ifndef DINITZ_H
#define DINITZ_H
#include <vector>
#include <queue>
#include "DataReader.h"

using namespace std;

class Dinitz {
    private:
        vector<int> level;
        vector<vector<int> > lvlAdjList;  // Level Order Graph : Adjacency List
        vector<vector<int> > adjList;     // Residual Graph Adjacency List
        int totalNumNodes;

//-------------------------- addSource-------------------------------//
// This function is used to add the source to the residual graph
// Preconditions: Receives the number of nodes as input.
// Postconditions: None

        void addSource(const int &numOfNodes);

//-------------------------- addSink-------------------------------//
// This function is used to add the sink to the residual graph
// Preconditions: Receives the number of nodes as input.
// Postconditions: None

        void addSink(const int &numOfNodes);

//-------------------------- bfs----------------------------------//
// This function perform the bfs to help construct the level graph
// Preconditions: None.
// Postconditions: None

        bool bfs();

//-------------------------- buildAdjListLG--------------------------//
// This function construct the adjcency matrix for the level graph
// Preconditions: None.
// Postconditions: Return valid adjcency matrix

        void buildAdjListLG();

//-------------------------- retreat--------------------------//
// This function retreat back if we get stuck in some 
// intermediate node
// Preconditions: The node from when we need to retreat.
// Postconditions: Delete any incoming edges from the node in 
//                 the Level Graph

        void retreat(const int& node);

//-------------------------- sendFlow--------------------------//
// This function perform the following functions:
//  - Augment flow with path.
//  - Update Residual Graph
//  - Delete edges from the level graph
// Preconditions: None
// Postconditions: Update the Level Graph and find augmented path

        bool sendFlow(vector<int> &path, const int &source, const int &sink);

//-------------------------- adjustResidualGraph--------------------------//
// This function reverses the direction of nodes in the residual grapg
// Preconditions: Should receive valid source and destination
// Postconditions: The updated residual graph will point from destination 
//                 to source

        void adjustResidualGraph(const int &src, const int &dst);

//-------------------------- deleteFromLGraph--------------------------//
// This function deletes the edges if the sink is reached or if stuck
// Preconditions: Two valid nodes
// Postconditions: The edge between the nodes are removed

        void deleteFromLGraph(const int &src, const int &dst);

//-------------------------- adjustGraphs--------------------------//
// This function adjust the level graph by deleting the edge in the
// path and reversing the direction of the edge in the residual 
// graph
// Preconditions: A valid path from source to sink
// Postconditions: None

        void adjustGraphs(vector<int> &path);

    public:

//-------------------------- Constructor -----------------------------------//
// Parametrized Constructor for the class Dinitz. 
// Preconditions:  Valid DataReader object.
// Postconditions: This is the constructor of the solver class. It perform 
// the following functions:
// - Initialize the residual graph
// - Initialize the level graph
// - Initiallize the level array
// - Add source and the sink

        Dinitz(const DataReader &reader);

//-------------------------- getBipartiteMatch--------------------------//
// This function computes the bipartite matching
// Preconditions: None
// Postconditions: Returns the valid  bipartite matching between the 
// left half and right half

        void getBipartiteMatch();

//-------------------------- printBipartiteMatch--------------------------//
// This function prints the bipartite matching
// Preconditions: None
// Postconditions: Output the matches in the order that the “left” 
// items appear in the file and the total number of matches. 

        void printBipartiteMatch(const DataReader &reader) const;









};

#endif