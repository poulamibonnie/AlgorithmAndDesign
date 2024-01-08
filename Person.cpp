#include "Person.h"

queue<int> Person::getPreference() {
    return this->preferences;
}

void Person::setPreference(string prefList) {
    stringstream ss(prefList);
    string pref;
    
    while (ss >> pref) 
    {
        this->preferences.push(stoi(pref));
    }
}  

int Person::getTopPreference() {
    //No new pet to propose
    if(preferences.empty()) {
        return -1;
    }
    int pref = this->preferences.front();
    this->preferences.pop();
    return pref;
}   

