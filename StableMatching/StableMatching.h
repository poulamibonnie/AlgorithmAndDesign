//---------------------------------------------------------------------------
// STABLEMATCHING.H
// Member declaration to implement stable matching using Gale-Shapely's 
// algorithm
// Authors: Poulami Das Ghosh
//---------------------------------------------------------------------------
// STABLEMATCHING class: In this class we implement stable matching using the
//                       Gale-Shapely's alogorithm.
//   it includes the following features:
//   -- It has vectors of Person and Pet type as class variable
//   -- Getter and setter methods are provided for the class variable
//   -- It implements Gale-Shapely's alogorithm.
//   -- The output printing is also handled in this class  
//
//Assumption: As per the specication, the algorithm needs to be designed as 
//            optimal to person. Hence vector<Person> is designated as 
//            optimals and vector<Pet> is designated as pesimals and treated 
//            accordingly
//---------------------------------------------------------------------------

#ifndef STABLEMATCHING_H
#define STABLEMATCHING_H

#include <iostream>
#include "Person.h"
#include "Pet.h"

using namespace std;

class StableMatching {
    private:
        vector<Person> optimals;
        vector<Pet> pessimals;
        
    public:
//-------------------------- Constructor -----------------------------------//
//Default Constructor for the class StableMatching
//Input: None
//Output: New object is created

        StableMatching(){};

//------- setOptimals(const vector<Person> &optimals) -------------------------//
//Default Constructor for the class StableMatching
//Input: This is the setter method to initiate the vector with objects of 
//       type Person 
//Output: None

        void setOptimals(const vector<Person> &optimals);

//--------------------------getOptimals() -------------------------------------//
//This is the getter method to output the vector with objects of type Person 
//Input: None
//Output: List of people participating in stableMatching

        vector<Person> getOptimals();

//------- setPessimals(const vector<Pet> &pessimals) -------------------------//
//This is the setter method to initiate the vector with objects of type Pet    
//Input: List of pet participating in stableMatching
//Output: None
        
        void setPessimals(const vector<Pet> &pessimals);

//---------------------------getPessimals() -----------------------------------//
//This is the getter method to output the vector with objects of type Person 
//Input: None
//Output: List of pet participating in stableMatching

        vector<Pet> getPessimals();

//---------------------------acceptProposal(<Input>) -----------------------------------//
// This function is called to accept a proposal being made. It will set the match 
// variable for both parties.
//Input: (1) The idx of the person making the proposal.
//       (2) The idx of the pet accepting the proposal.
//Output: None

        void acceptProposal(const int &currIdxPerson, const int &petIdx);

//---------------------------tradeUpOrReject(<Input>) -----------------------------------//
// This function is called to check the posibililty of trade up if a better match is 
// found and implements tradeup whenever possible
//Input: (1) The idx of the person making the proposal.
//       (2) The idx of the pet accepting the proposal.
//       (3) The idx of next person to make the proposal.
//Output: None

        void tradeUpOrReject(const int &petIdx, int &currIdxPerson, int &nextIdxPerson);

//---------------------------solver()---------------------------------------------//
// This function is used to find stable matches using the Gale-Shapley's algo. 
//Input: None
//Output: None

        void solver();

//---------------------------printStableMatch()---------------------------------------------//
// This function is used to print the stable matches. 
//Input: None
//Output: None

        void printStableMatch();

};


#endif