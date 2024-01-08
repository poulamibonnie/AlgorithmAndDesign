#ifndef PET_H
#define PET_H

#include<iostream>
#include <vector>
#include <sstream>
#include "Entity.h"

using namespace std;

class Pet : public Entity {
    private:
        vector<int> revIdxPrefList;
    
    public:
        Pet(){}

        Pet(string name) : Entity(name) {}

        int getRevIdxPreference(int idx);

        void setRevIdxPreference(string prefList, int size);

};

#endif