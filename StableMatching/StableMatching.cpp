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

#include "StableMatching.h"

//------------------------- setOptimals ------------------------------------//
// This is the setter method to initiate the vector with objects of type
// Person.
// Preconditions: The input should contain a vector of objects of type Person
// Postconditions: It sets the list of people participating in stable matching
void StableMatching::setOptimals(const vector<Person> &_optimals) {
    this->optimals = _optimals;
    return;
}

//--------------------------getOptimals--------------------------------------//
// This is the getter method to output the vector with objects of type Person.
// Preconditions: None
// Postconditions: Returns the list of people participating in stable matching
vector<Person> StableMatching::getOptimals() {
    return this->optimals;
}

//----------------------------setPessimals ----------------------------------//
// This is the setter method to initiate the vector with objects of type
// Pet.
// Preconditions: The input should contain a vector of objects of type Pet
// Postconditions: It sets the list of pets participating in stable matching

void StableMatching::setPessimals(const vector<Pet> &_pessimals) {
    this->pessimals = _pessimals;
    return;
}

//---------------------------getPessimals-------------------------------------//
// This is the getter method to output the vector with objects of type Pet 
// Preconditions: None
// Postconditions: Returns the list of pets participating in stable matching

vector<Pet> StableMatching::getPessimals() {
    return this->pessimals;
}

//---------------------------acceptProposal-----------------------------------//
// This function is called to accept a proposal being made. It will set the 
// match variable for both parties.
// Preconditions: A valid index of the proposer(Person) and proposed(Pet) is
//                received as input.
// Postconditions: Accepts proposal and set the 'match' property for the both
//                 the optimals and the pessimals.

void StableMatching::acceptProposal(const int &currIdxPerson, const int &petIdx) {
    this->optimals[currIdxPerson].setMatch(petIdx + 1);
    this->pessimals[petIdx].setMatch(currIdxPerson + 1);
    return;
}

//---------------------------tradeUpOrReject---------------------------------//
// This function is called to check the posibililty of trade up if a better 
// match is found and implements tradeup whenever possible
// Preconditions:  A valid index prepresenting the proposer and proposed.
// Postconditions: Accepts proposal if a better proposal is received by  
//                 trade up with previously matched person else reject
//                 proposal.

void StableMatching::tradeUpOrReject(const int &petIdx, int &currIdxPerson) {
    int matchedPet = this->pessimals[petIdx].getMatch();
    int prefIdxCurrMatch = this->pessimals[petIdx].getRevIdxPreference(matchedPet);
    int prefIdxNewMatch = this->pessimals[petIdx].getRevIdxPreference(currIdxPerson + 1);

    // Pet accepts proposal and trades up if it finds a better match
    if (prefIdxNewMatch < prefIdxCurrMatch) { 
        acceptProposal(currIdxPerson, petIdx);
        this->optimals[matchedPet - 1].setMatch(-1);

        // Modify the value of currIdxPerson to newly unmatched person
        currIdxPerson = matchedPet - 1;
    }

    // If tradeup not better, reject proposal
    return;
}

//---------------------------solver-----------------------------------------//
// This function is used to find stable matches using the Gale-Shapley
// algorithm. 
// Preconditions:  None
// Postconditions: Returns stable match for each object optimal to proposer.

void StableMatching::solver() {
    int entitySize = static_cast<int>(optimals.size());
    int currIdxPerson = 0;
    int matchFound = 0;
    int petProposed = -1;
    int petIdx = -1;
    int maxIdx = -1;

    while (matchFound != entitySize) {
        // This is to remember the max index till which we have traversed
        // so far via the linear path. This is used to re-convene the
        // linear traversal after we have completed the trade ups.
        maxIdx = max(maxIdx, currIdxPerson);

        // Person makes a proposal to the top Pet preference currently
        // in his/her list.
        petProposed = this->optimals[currIdxPerson].getTopPreference();
        petIdx = petProposed - 1;

        if (petProposed == -1) {
            std::cerr << "[Error] Validate Input : All the pets proposed but no match found!" << std::endl;
            throw 0;
            return;
        }

        if (this->pessimals[petIdx].getMatch() == -1) {
            // Directly accept if no other proposal made to the pet.
            acceptProposal(currIdxPerson, petIdx);
            matchFound++;
        } 
        else {
            // If the pet already has a match, it can accept or reject
            // new proposal.
            tradeUpOrReject(petIdx, currIdxPerson);
            continue;
        }

        currIdxPerson = maxIdx + 1;
    }

    return;
}

//---------------------------printStableMatch----------------------------------//
// This function is used to print the stable matches. 
// Preconditions:  The stable match is found for all proposers.
// Postconditions: The stable matching will be displayed in the console.
//                  Each line in the output contains the name of one person
//                  and one pet separated by " / ". This implies that the
//                  person is matched to that pet based on the Gale-Shapley
//                  algorithm. There will be as many lines in the output as
//                  the number of persons (or pets). Also the output is 
//                  optimal to persons.

void StableMatching::printStableMatch() {
    for(int i = 0; i < this->optimals.size(); i++) {
        string res = this->optimals[i].getName() + " / "  +  this->pessimals[ this->optimals[i].getMatch() -1].getName();
        cout<<res<<endl;
    }
    return;
}