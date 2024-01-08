#include "Pet.h"

int Pet::getRevIdxPreference(int idx) {
    return this->revIdxPrefList[idx];
}

void Pet::setRevIdxPreference(string prefList, int size) {
    this->revIdxPrefList.resize(size + 1, -1);
    stringstream ss(prefList);
    string pref;
    int idx = 1;

    while (ss >> pref) 
    {
        this->revIdxPrefList[stoi(pref)] = idx++;
    }
} 

