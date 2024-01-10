//---------------------------------------------------------------------------
// ENTITY.CPP
// Member function definitions for class Entity
// Authors: Poulami Das Ghosh
//---------------------------------------------------------------------------
// Entity class:  This is the parent class of Pet and Person
//   it includes the following features:
//   -- it has two private class variable 'name' and 'match'.
//      -- the 'name' variable stores the name of the entity.
//      -- the 'match' variable stores the index of the matched item (Pet/Person)
//   -- Has getter method 'getName' to output the name of the entity(Pet/Person)
//   -- Has setter method 'setName' to set the name of the entity(Pet/Person)
//   -- Has getter method 'getMatch' to output the match for the entity(Pet/Person)
//   -- Has setter method 'setMatch' to set the match for the entity(Pet/Person)
//
// Assumptions:
//   -- The user input would be valid and valid string will be received for 'name'.
//   -- 'match' initialized to -1 indicates no item matched.
//---------------------------------------------------------------------------

#include "Entity.h"

//-------------------------- Constructor -----------------------------------//
//Parametrized Constructor for the class Entity
//Input: Valid string containing the name of the object is provided as input.
//Output: New object is created with name as input string and match as -1 
//        indicating no item matched

Entity::Entity(const string &name) {
    setName(name);
    setMatch(-1);
}

//-------------------------- Getter Method -----------------------------------//
//Getter method 'getName' to return the name of the entity(Pet/Person)
//Input: None
//Output: Returns the name of the entity(Pet/Person)

string Entity::getName() {
    return this->name;
}

//-------------------------- Setter Method -----------------------------------//
//Setter method 'setName' to set the name of the entity(Pet/Person)
//Input: Valid string containing the name of the object is provided as input.
//Output: None

void Entity::setName(const string &name) {
    this->name = name;
}

//-------------------------- Getter Method -----------------------------------//
//Getter method 'getMatch' to return the matched item of the entity(Pet/Person)
//Input: None
//Output: Returns the index of the matched item of the entity(Pet/Person)

int Entity::getMatch() {
    return this->match;
}  

//-------------------------- Setter Method -----------------------------------//
//setter method 'setMatch' to set the match for the entity(Pet/Person)
//Input: Valid integer containing the index of the matched item.
//Output: None

void Entity::setMatch(const int &matchedIdx) {
    this->match = matchedIdx;
}
