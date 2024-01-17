//---------------------------------------------------------------------------
// STABLEMATCHING.CPP
// Member definations for the class StableMatching
// Author(s): Poulami Das Ghosh
//---------------------------------------------------------------------------
// STABLEMATCHING class: In this class we implement stable matching using the
//                       Gale-Shapley alogorithm.
//   It includes the following features:
//   -- It has vectors of Person and Pet type as class members.
//   -- Getter and setter methods are provided for accessing the private 
//      class members.
//   -- It implements Gale-Shapley alogorithm.
//   -- The output printing is also handled in this class.
//
// Assumption: As per the specification, the algorithm needs to be designed as 
//            optimal to persons. Hence vector<Person> is designated as 
//            optimals and vector<Pet> is designated as pessimals and treated 
//            accordingly.
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
// Default Constructor for the class StableMatching
// Preconditions: None
// Postconditions: New object is created

        StableMatching(){};

//------------------------- setOptimals -------------------------------------//
// This is the setter method to initiate the vector with objects of type
// Person
// Preconditions: The input should contain a vector of objects of type Person
// Postconditions: It sets the list of people participating in stable matching

        void setOptimals(const vector<Person> &optimals);

//--------------------------getOptimals--------------------------------------//
// This is the getter method to output the vector with objects of type Person 
// Preconditions: None
// Postconditions: Returns the list of people participating in stable matching

        vector<Person> getOptimals();

//----------------------------setPessimals ----------------------------------//
// This is the setter method to initiate the vector with objects of type
// Pet.
// Preconditions: The input should contain a vector of objects of type Pet
// Postconditions: It sets the list of pets participating in stable matching
        
        void setPessimals(const vector<Pet> &pessimals);

//---------------------------getPessimals-------------------------------------//
// This is the getter method to output the vector with objects of type Pet 
// Preconditions: None
// Postconditions: Returns the list of pets participating in stable matching

        vector<Pet> getPessimals();

//---------------------------acceptProposal----------------------------------//
// This function is called to accept a proposal being made. It will set the 
// match variable for both parties.
// Preconditions: A valid index of the proposer(Person) and proposed(Pet) is
//                received as input.
// Postconditions: Accepts proposal and set the 'match' property for the both
//                 the optimals and the pessimals.

        void acceptProposal(const int &currIdxPerson, const int &petIdx);

//---------------------------tradeUpOrReject-------------------------------//
// This function is called to check the posibililty of trade up if a better 
// match is found and implements tradeup whenever possible
// Preconditions:  A valid index prepresenting the proposer and proposed.
// Postconditions: Accepts proposal if a better proposal is received by  
//                 trade up with previously matched person else reject
//                 proposal.

        void tradeUpOrReject(const int &petIdx, int &currIdxPerson);

//---------------------------solver---------------------------------------------//
// This function is used to find stable matches using the Gale-Shapley's algo. 
// Preconditions:  None
// Postconditions: Returns stable match for each objects optimal to proposer.

        void solver();

//---------------------------printStableMatch----------------------------------//
// This function is used to print the stable matches. 
// Preconditions:  The stable match is found for all proposers.
// Postconditions: The stable matching will be displayed in the console.
//                  Each line in the output contains the name of one person
//                  and one pet separated by " / ". This implies that the
//                  person is matched to that pet based on the Gale-Shapley
//                  algorithm. There will be as many lines in the output as
//                  the number of persons (or pets). Also the output is 
//                  optimal to personsone

        void printStableMatch();

};


#endif