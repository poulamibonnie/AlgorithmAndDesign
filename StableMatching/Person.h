#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <queue>
#include <sstream>
#include "Entity.h"

using namespace std;

class Person : public Entity {
    private:
        queue<int> preferences;
        
    public:
        Person(){}

        Person(string name) : Entity(name) {};

        queue<int> getPreference();

        void setPreference(string prefList);

        int getTopPreference();

};

#endif
