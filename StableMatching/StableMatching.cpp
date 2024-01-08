#include "StableMatching.h"

void StableMatching::setOptimals(vector<Person> optimals) {
    this->optimals = optimals;
}

vector<Person> StableMatching::getOptimals() {
    return this->optimals;
}

void StableMatching::setPessimals(vector<Pet> pessimals) {
    this->pessimals = pessimals;
}

vector<Pet> StableMatching::getPessimals() {
    return this->pessimals;
}

void StableMatching::solver() {
    entitySize = optimals.size();
    int currIdxPerson = 0;
    int nextIdxPerson = -1;
    int matchFound = 0;
    
    while(matchFound != entitySize) {
        int petProposed = this->optimals[currIdxPerson].getTopPreference();


        if(petProposed == -1) {
            std::cerr << "Validate input files, all the pets proposed but all person didnot find match!" << std::endl;
            return;
        }

        int petIdx = petProposed - 1;
        if(this->pessimals[petIdx].getMatch() == -1) {
            //Pet accepts proposal
            this->optimals[currIdxPerson].setMatch(petIdx + 1);
            this->pessimals[petIdx].setMatch(currIdxPerson + 1);
            matchFound++;
        } 
        else {
            
            int matchedPet = this->pessimals[petIdx].getMatch();
            int prefIdxCurrMatch = this->pessimals[petIdx].getRevIdxPreference(matchedPet);
            int prefIdxNewMatch = this->pessimals[petIdx].getRevIdxPreference(currIdxPerson + 1);
            
            if(prefIdxNewMatch < prefIdxCurrMatch) { //For trade up
                this->optimals[currIdxPerson].setMatch(petIdx + 1);
                this->pessimals[petIdx].setMatch(currIdxPerson + 1);
                this->optimals[matchedPet - 1].setMatch(-1);
                nextIdxPerson = currIdxPerson + 1;
                currIdxPerson = matchedPet - 1;
                continue;
            }
            else {
                continue;    //Pet rejects proposal
            } 
        }

        currIdxPerson = (nextIdxPerson == -1) ? currIdxPerson + 1 : nextIdxPerson;
    }
    
}

void StableMatching::printStableMatch() {
    for(int i = 0; i < this->entitySize; i++) {
        string res = this->optimals[i].getName() + " / "  +  this->pessimals[ this->optimals[i].getMatch() -1].getName();
        cout<<res<<endl;

    }
}