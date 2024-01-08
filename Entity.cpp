#include "Entity.h"

string Entity::getName() {
    return this->name;
}

void Entity::setName(string name) {
    this->name = name;
}

int Entity::getMatch() {
    return this->match;
}  

void Entity::setMatch(int pet) {
    this->match = pet;
}
