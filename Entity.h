#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
using namespace std;

class Entity {
    private:
        string name;
        int match;
    
    public:
        Entity(){}

        Entity(string name) {
            setName(name);
            setMatch(-1);
        }

        string getName();

        void setName(string name);

        int getMatch();

        void setMatch(int pet);
};

#endif
