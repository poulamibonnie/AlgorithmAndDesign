//---------------------------------------------------------------------------
// DINITZ.CPP
// Defination of DINITZ algorithm class member
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

#include "Dinitz.h"


//-------------------------- Constructor -----------------------------------//
// Parametrized Constructor for the class Dinitz. 
// Preconditions:  Valid DataReader object.
// Postconditions: This is the constructor of the solver class. It perform 
// the following functions:
// - Initialize the residual graph
// - Initialize the level graph
// - Initiallize the level array
// - Add source and the sink

Dinitz::Dinitz(const DataReader &reader) {
    int numOfNodes = reader.getNumNodes();
    int additionalNode = 2;  // To accomodate for source and sink
    this->totalNumNodes = numOfNodes + additionalNode;

    // Initialize adjacency list for residual graph
    this->adjList.resize(this->totalNumNodes, vector<int> (this->totalNumNodes, 0));

    // Initialize adjacency list for Level Graph
    this->lvlAdjList.resize(this->totalNumNodes, vector<int> (this->totalNumNodes, 0));

    // Initialize level array
    this->level.resize(this->totalNumNodes);

    // Re-initialize adjacency list for residual graph
    for (int src = 0; src < totalNumNodes; src++) {
        vector<int> orgAdjList = reader.getAdjList(src);
        for (int dst = 0; dst < totalNumNodes; dst++) {
            adjList[src][dst] = orgAdjList[dst];
        }
    }

    // Add source
    addSource(numOfNodes);

    // Add sink
    addSink(numOfNodes);
}

//-------------------------- addSource-------------------------------//
// This function is used to add the source to the residual graph
// Preconditions: Receives the number of nodes as input.
// Postconditions: None

void Dinitz::addSource(const int &numOfNodes){
    for (int i = 1; i <= numOfNodes/2; i++) {
        this->adjList[0][i] = 1;
    }
    return;
}

//-------------------------- addSink-------------------------------//
// This function is used to add the sink to the residual graph
// Preconditions: Receives the number of nodes as input.
// Postconditions: None

void Dinitz::addSink(const int &numOfNodes){
    int sink = numOfNodes + 1;

    for (int i = numOfNodes/2 + 1; i <= numOfNodes; i++) {
        this->adjList[i][sink] = 1;
    }
    return;
}

//-------------------------- bfs----------------------------------//
// This function perform the bfs to help construct the level graph
// Preconditions: None.
// Postconditions: None

bool Dinitz::bfs() {
    int source = 0;
    int sink = this->totalNumNodes - 1;
  
    queue<int> pq;
    this->level.assign(totalNumNodes, -1);

    // the level[] states the level of each node from the source.
    // Here the level[] will also show if the node is visited

    pq.push(source);
    this->level[source] = 0;
    
    while (!pq.empty()) {
        int node = pq.front();
        pq.pop();
        
        // Visit the neighbourhood of each node from the residual graph
        vector<int> adjListRow = this->adjList[node];
        for (int nbr = 0; nbr < adjListRow.size(); nbr++) {
            if (this->level[nbr] == -1 && adjListRow[nbr] == 1) {
                pq.push(nbr);
                this->level[nbr] = this->level[node] + 1;
            }
        }
    }

    // If sink can be reached returns true else false
    return (this->level[sink] == -1) ? false : true;
}

//-------------------------- buildAdjListLG--------------------------//
// This function construct the adjcency matrix for the level graph
// Preconditions: None.
// Postconditions: Return valid adjcency matrix

void Dinitz::buildAdjListLG() {
    for (int node = 0; node < this->totalNumNodes; node++) {
        for (int nbr = 0; nbr < this->totalNumNodes; nbr++) {
            this->lvlAdjList[node][nbr] =  this->adjList[node][nbr];
        }
    }
    return; 
}

//-------------------------- retreat--------------------------//
// This function retreat back if we get stuck in some 
// intermediate node
// Preconditions: The node from when we need to retreat.
// Postconditions: Delete any incoming edges from the node in 
//                 the Level Graph

void Dinitz::retreat(const int &node){
    for (int i = 0; i < this->totalNumNodes; i++) {
        this->lvlAdjList[i][node] = 0;
    }

    return;
}


//-------------------------- sendFlow--------------------------//
// This function perform the following functions:
//  - Augment flow with path.
//  - Update Residual Graph
//  - Delete edges from the level graph
// Preconditions: None
// Postconditions: Update the Level Graph and find augmented path

bool Dinitz::sendFlow(vector<int> &path, const int &source, const int &sink) {
    int node = source;
    bool hasRetreated = false;

    // Augment flow with path.
    while (node != sink) {
        if (hasRetreated) {
            hasRetreated = false;
        }
        else {
            // Update current path if new node.
            path.push_back(node); 
        }
         
        
        int nextNodeFound = 0;
        // Advance along some edge in LG that leaves current location.
        for (int nbr = 0; nbr < totalNumNodes; nbr++) {
            if (level[node] + 1 == level[nbr] && lvlAdjList[node][nbr] == 1) {
                node = nbr;
                nextNodeFound = 1;
                break;
            }
        }
        
        // Stuck at source
        if (nextNodeFound == 0 && node == source) {
            return false;
        } 
        // Stuck at itermediate nodes
        else if (nextNodeFound == 0) {
            // Retreat & Delete current node and incoming edges from LG.
            retreat(node);
            path.pop_back();
            node = path.back();
            hasRetreated = true;
        }
    }
    path.push_back(sink);  
    return true;
}

//-------------------------- adjustResidualGraph--------------------------//
// This function reverses the direction of nodes in the residual grapg
// Preconditions: Should receive valid source and destination
// Postconditions: The updated residual graph will point from destination 
//                 to source

void Dinitz::adjustResidualGraph(const int &src, const int &dst) {
    this->adjList[src][dst] = 0;
    this->adjList[dst][src] = 1;
    return;
}

//-------------------------- deleteFromLGraph--------------------------//
// This function deletes the edges if the sink is reached or if stuck
// Preconditions: Two valid nodes
// Postconditions: The edge between the nodes are removed

void Dinitz::deleteFromLGraph(const int &src, const int &dst) {
    this->lvlAdjList[src][dst] = 0;
    return;
}

//-------------------------- adjustGraphs--------------------------//
// This function adjust the level graph by deleting the edge in the
// path and reversing the direction of the edge in the residual 
// graph
// Preconditions: A valid path from source to sink
// Postconditions: None

void Dinitz::adjustGraphs(vector<int> &path) {
    int idx = (int) path.size() - 1;

    
    while (idx > 0) {
        int dst = path[idx];
        int src = path[idx - 1];
        adjustResidualGraph(src, dst);
        deleteFromLGraph(src, dst);
     
        idx--;
        path.pop_back();
    }
    path.pop_back();
   
    return;
}

//-------------------------- getBipartiteMatch--------------------------//
// This function computes the bipartite matching
// Preconditions: None
// Postconditions: Returns the valid  bipartite matching between the 
// left half and right half

void Dinitz::getBipartiteMatch() {
    int source = 0;
    int sink = this->totalNumNodes - 1;
    
    while (bfs()) {
       // Create the adjacency list of level graph
       // based on Residual graph
       buildAdjListLG();
       vector<int> path;

       while (sendFlow(path, source, sink)) {
            // Adjust Level Graph
            // Adjust Residual Graph
            adjustGraphs(path);
            
       }
    }
    
    return;
}

//-------------------------- printBipartiteMatch--------------------------//
// This function prints the bipartite matching
// Preconditions: None
// Postconditions: Output the matches in the order that the “left” 
// items appear in the file and the total number of matches. 

void Dinitz::printBipartiteMatch(const DataReader &reader) const {
    int numMatches = 0;
    for (int j = 1; j <= totalNumNodes/2 - 1; j++) {
        for (int i = totalNumNodes/2 ; i <= totalNumNodes - 2; i++) {
            if (this->adjList[i][j] == 1) {
                cout << reader.getName(j) <<" / "<<reader.getName(i) << endl;
                numMatches++;
            }
        }
    }
    cout << numMatches <<" total matches"<<endl;
}