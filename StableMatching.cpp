#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

class Entity {
    private:
        string name;
        int match;
    public:
        

};

class Person {
    private:
        string name;
        queue<int> preferences;
        int match;
    
    public:
        Person(){};

        Person(string name) {
            setName(name);
            setMatch(-1);
        }

        string getName() {
            return this->name;
        }

        void setName(string name) {
            this->name = name;
        }

        queue<int> getPreference() {
            return this->preferences;
        }

        void setPreference(string prefList) {
            stringstream ss(prefList);
            string pref;
         
            while (ss >> pref) 
            {
                this->preferences.push(stoi(pref));
            }
        }  

        int getMatch() {
            return this->match;
        }  

        void setMatch( int pet ) {
            this->match = pet;
        }

        int getTopPreference() {
            //No new pet to propose
            if(preferences.empty()) {
                return -1;
            }
            int pref = this->preferences.front();
            this->preferences.pop();
            return pref;
        }   

};


class Pet {
    private:
        string name;
        vector<int> revIdxPrefList;
        int match;
    
    public:
        Pet(){}

        Pet(string name) {
            setName(name);
            setMatch(-1);
        }

        string getName() {
            return this->name;
        }

        void setName(string name) {
            this->name = name;
        }

        int getMatch() {
            return this->match;
        }  

        void setMatch( int human ) {
            this->match = human;
        }  

        int getRevIdxPreference(int idx) {
            return this->revIdxPrefList[idx];
        }

        void setRevIdxPreference(string prefList, int size) {

            //Split operation is repeatetive may be we create a split function ??

            this->revIdxPrefList.resize(size + 1, -1);
            stringstream ss(prefList);
            string pref;
            int idx = 1;

            while (ss >> pref) 
            {
                this->revIdxPrefList[stoi(pref)] = idx++;
            }
        } 

};

string getCleanseString(string str) {
    string cleanseStr = "";
    for(int i = 0; i < str.size(); i++) {
        if((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')) {
            cleanseStr += str[i];
        }
    }
    return cleanseStr;
}

int main() {
    ifstream inputFile("program1data.txt");
    string myText;

    int loopCounter = 0;
    int setSize = 0;
    vector<Person> people;
    vector<Pet> animals;

    if (inputFile.is_open()) {
        while (getline (inputFile, myText)) {
            if(loopCounter == 0) {
                setSize = stoi(myText);
            }
            else if (loopCounter >= 1 && loopCounter <= setSize){
                Person newPerson = Person(getCleanseString(myText));
                people.push_back(newPerson);
            }
            else if(loopCounter >= setSize + 1 && loopCounter <= (setSize * 2)) {
                people[ loopCounter - setSize - 1 ].setPreference(myText);
            }
            else if(loopCounter >= (setSize * 2) + 1 && loopCounter <= (setSize * 3)) {
                Pet newPet = Pet(getCleanseString(myText));
                animals.push_back(newPet);
            }
            else{
                animals[ loopCounter - (3 * setSize) - 1 ].setRevIdxPreference(myText, setSize);
            }
            loopCounter++;
        }
        inputFile.close();
    }
    else{
        std::cerr << "Error opening the file." << std::endl;
        return -1;
    }
    
    int currIdx = 0;
    int nextIdx = -1;
    int matchFound = 0;


    while(matchFound != setSize) {
        int petProposed = people[currIdx].getTopPreference();


        if(petProposed == -1) {
            std::cerr << "Validate input files, all the pets proposed but all person didnot find match!" << std::endl;
            return -1;
        }

        int petIdx = petProposed - 1;
        if(animals[petIdx].getMatch() == -1) {
            //Pet accepts proposal
            people[currIdx].setMatch(petIdx + 1);
            animals[petIdx].setMatch(currIdx + 1);
            matchFound++;
        } 
        else {
            
            int matchedPet = animals[petIdx].getMatch();
            int prefIdxCurrMatch = animals[petIdx].getRevIdxPreference(matchedPet);
            int prefIdxNewMatch = animals[petIdx].getRevIdxPreference(currIdx + 1);
            
            if(prefIdxNewMatch < prefIdxCurrMatch) { //For trade up
                people[currIdx].setMatch(petIdx + 1);
                animals[petIdx].setMatch(currIdx + 1);
                people[matchedPet - 1].setMatch(-1);
                nextIdx = currIdx + 1;
                currIdx = matchedPet - 1;
                continue;
            }
            else {
                continue;    //Pet rejects proposal
            } 
        }

        currIdx = (nextIdx == -1) ? currIdx + 1 : nextIdx;
    }

    for(int i = 0; i < people.size(); i++) {
        string res = people[i].getName() + " / "  +  animals[ people[i].getMatch() -1].getName();
        cout<<res<<endl;

    }

    return 0;
}