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
        int entitySize; 

    public:
        StableMatching() {
            this->entitySize = 0;
        }

        void setOptimals(vector<Person> optimals);

        vector<Person> getOptimals();
        
        void setPessimals(vector<Pet> pessimals);

        vector<Pet> getPessimals();

        void solver();

        void printStableMatch();

};


#endif