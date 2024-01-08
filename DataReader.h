#ifndef DATAREADER_H
#define DATAREADER_H

#include <iostream>
#include <fstream>
#include "Entity.h"
#include "Person.h"
#include "Pet.h"

class DataReader { 
    private:
        vector<Person> firstParty;
        vector<Pet> secondParty;
        int entitySize;

    public:
        DataReader() {
            entitySize = 0;
        }

        vector<Person> getFirstParty();

        vector<Pet> getSecondParty();

        int getEntitySize();

        string getCleanseString(string str);

        void fileRead(string filename);

};

#endif