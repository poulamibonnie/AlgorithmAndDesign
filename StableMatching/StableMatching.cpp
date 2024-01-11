//---------------------------------------------------------------------------
// STABLEMATCHING.CPP
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

#include "StableMatching.h"

//------- setOptimals(const vector<Person> &optimals) -------------------------//
//This is the setter method to initiate the vector with objects of type Person 
//Input: List of people participating in stableMatching
//Output: None

void StableMatching::setOptimals(const vector<Person> &optimals) {
    this->optimals = optimals;
    return;
}

//--------------------------getOptimals() -------------------------------------//
//This is the getter method to output the vector with objects of type Person 
//Input: None
//Output: List of people participating in stableMatching

vector<Person> StableMatching::getOptimals() {
    return this->optimals;
}

//------- setPessimals(const vector<Pet> &pessimals) -------------------------//
//This is the setter method to initiate the vector with objects of type Pet    
//Input: List of pet participating in stableMatching
//Output: None

void StableMatching::setPessimals(const vector<Pet> &pessimals) {
    this->pessimals = pessimals;
    return;
}

//---------------------------getPessimals() -----------------------------------//
//This is the getter method to output the vector with objects of type Person 
//Input: None
//Output: List of pet participating in stableMatching

vector<Pet> StableMatching::getPessimals() {
    return this->pessimals;
}

//---------------------------acceptProposal(<Input>) -----------------------------------//
// This function is called to accept a proposal being made. It will set the match 
// variable for both parties.
//Input: (1) The idx of the person making the proposal.
//       (2) The idx of the pet accepting the proposal.
//Output: None

void StableMatching::acceptProposal(const int &currIdxPerson, const int &petIdx) {
    this->optimals[currIdxPerson].setMatch(petIdx + 1);
    this->pessimals[petIdx].setMatch(currIdxPerson + 1);
    return;
}

//---------------------------tradeUpOrReject(<Input>) -----------------------------------//
// This function is called to check the posibililty of trade up if a better match is 
// found and implements tradeup whenever possible
//Input: (1) The idx of the person making the proposal.
//       (2) The idx of the pet accepting the proposal.
//       (3) The idx of next person to make the proposal.
//Output: None

void StableMatching::tradeUpOrReject(const int &petIdx, int &currIdxPerson, int &nextIdxPerson) {
    int matchedPet = this->pessimals[petIdx].getMatch();
    int prefIdxCurrMatch = this->pessimals[petIdx].getRevIdxPreference(matchedPet);
    int prefIdxNewMatch = this->pessimals[petIdx].getRevIdxPreference(currIdxPerson + 1);

    // Pet accepts proposal and trade up if it finds a better match
    if(prefIdxNewMatch < prefIdxCurrMatch) { 
        acceptProposal(currIdxPerson, petIdx);
        this->optimals[matchedPet - 1].setMatch(-1);

        // Modify the value of currIdxPerson and nextIdxPerson to ensure correct order of proposal
        nextIdxPerson = currIdxPerson + 1;
        currIdxPerson = matchedPet - 1;
        return;
    }
    // If tradeup not better, reject proposal
    else{
        
        return;
    }
   

}

//---------------------------solver()---------------------------------------------//
// This function is used to find stable matches using the Gale-Shapley's algo. 
//Input: None
//Output: None

void StableMatching::solver() {
    int entitySize = optimals.size();
    int currIdxPerson = 0;
    int nextIdxPerson = -1;
    int matchFound = 0;
    int petProposed = -1;
    int petIdx = -1;

    while(matchFound != entitySize) {

        // Person makes a proposal
        petProposed = this->optimals[currIdxPerson].getTopPreference();
        petIdx = petProposed - 1;

        if(petProposed == -1) {
            std::cerr << "[Error] Validate Input : All the pets proposed but no match found!" << std::endl;
            return;
        }

        // Directly accept if not other proposal made to the pet.
        // if the pet already has a match, it can accept or reject new proposal.
        if(this->pessimals[petIdx].getMatch() == -1) {
            acceptProposal(currIdxPerson, petIdx);
            matchFound++;
        } 
        else {
            tradeUpOrReject(petIdx, currIdxPerson, nextIdxPerson);
            continue;
        }

        currIdxPerson = (nextIdxPerson == -1) ? currIdxPerson + 1 : nextIdxPerson;
    }
    return;
}

//---------------------------printStableMatch()---------------------------------------------//
// This function is used to print the stable matches. 
//Input: None
//Output: None

void StableMatching::printStableMatch() {
    for(int i = 0; i < this->optimals.size(); i++) {
        string res = this->optimals[i].getName() + " / "  +  this->pessimals[ this->optimals[i].getMatch() -1].getName();
        cout<<res<<endl;
    }
    return;
}