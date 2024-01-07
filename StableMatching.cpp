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
        Entity() {}

        Entity(string name) {
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

        void setMatch(int pet) {
            this->match = pet;
        }
};

class Person : public Entity {
    private:
        queue<int> preferences;
        
    public:
        Person(){}

        Person(string name) : Entity(name) {}

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


class Pet : public Entity {
    private:
        vector<int> revIdxPrefList;
    
    public:
        Pet(){}

        Pet(string name) : Entity(name) {}

        int getRevIdxPreference(int idx) {
            return this->revIdxPrefList[idx];
        }

        void setRevIdxPreference(string prefList, int size) {
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

class StableMatching {
    private:
        vector<Person> optimals;
        vector<Pet> pessimals;
        int entitySize; 

    public:
        StableMatching() {
            this->entitySize = 0;
        }

        void setOptimals(vector<Person> optimals) {
            this->optimals = optimals;
        }

        vector<Person> getOptimals() {
            return this->optimals;
        }
        
        void setPessimals(vector<Pet> pessimals) {
            this->pessimals = pessimals;
        }

        vector<Pet> getPessimals() {
            return this->pessimals;
        }

        void solver() {
            entitySize = optimals.size();
            int currIdx = 0;
            int nextIdx = -1;
            int matchFound = 0;
            
            while(matchFound != entitySize) {
                int petProposed = this->optimals[currIdx].getTopPreference();


                if(petProposed == -1) {
                    std::cerr << "Validate input files, all the pets proposed but all person didnot find match!" << std::endl;
                    return;
                }

                int petIdx = petProposed - 1;
                if(this->pessimals[petIdx].getMatch() == -1) {
                    //Pet accepts proposal
                    this->optimals[currIdx].setMatch(petIdx + 1);
                    this->pessimals[petIdx].setMatch(currIdx + 1);
                    matchFound++;
                } 
                else {
                    
                    int matchedPet = this->pessimals[petIdx].getMatch();
                    int prefIdxCurrMatch = this->pessimals[petIdx].getRevIdxPreference(matchedPet);
                    int prefIdxNewMatch = this->pessimals[petIdx].getRevIdxPreference(currIdx + 1);
                    
                    if(prefIdxNewMatch < prefIdxCurrMatch) { //For trade up
                        this->optimals[currIdx].setMatch(petIdx + 1);
                        this->pessimals[petIdx].setMatch(currIdx + 1);
                        this->optimals[matchedPet - 1].setMatch(-1);
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
            
        }

        void printStableMatch() {
            for(int i = 0; i < this->entitySize; i++) {
                string res = this->optimals[i].getName() + " / "  +  this->pessimals[ this->optimals[i].getMatch() -1].getName();
                cout<<res<<endl;

            }
        }

};

class DataReader { 
    private:
        vector<Person> people;
        vector<Pet> animals;
        int entitySize;

    public:
        DataReader() {
            entitySize = 0;
        }

        vector<Person> getPeople() {
            return this->people;
        }

        vector<Pet> getAnimals() {
            return this->animals;
        }

        int getEntitySize() {
            return this->entitySize;
        }

        void fileRead(string filename) {
            ifstream inputFile(filename);
            string myText;

            int loopCounter = 0;
    
            if (inputFile.is_open()) {
                while (getline (inputFile, myText)) {
                    if(loopCounter == 0) {
                        entitySize = stoi(myText);
                    }
                    else if (loopCounter >= 1 && loopCounter <= entitySize){
                        Person newPerson = Person(getCleanseString(myText));
                        people.push_back(newPerson);
                    }
                    else if(loopCounter >= entitySize + 1 && loopCounter <= (entitySize * 2)) {
                        people[ loopCounter - entitySize - 1 ].setPreference(myText);
                    }
                    else if(loopCounter >= (entitySize * 2) + 1 && loopCounter <= (entitySize * 3)) {
                        Pet newPet = Pet(getCleanseString(myText));
                        animals.push_back(newPet);
                    }
                    else{
                        animals[ loopCounter - (3 * entitySize) - 1 ].setRevIdxPreference(myText, entitySize);
                    }
                    loopCounter++;
                }
                inputFile.close();
            }
            else{
                std::cerr << "Error opening the file." << std::endl;
                return;
            }
    }

};

int main() {
    DataReader reader;
    reader.fileRead("program1data.txt");

    StableMatching matcher;
    matcher.setOptimals(reader.getPeople());
    matcher.setPessimals(reader.getAnimals());

    matcher.solver();
    matcher.printStableMatch();

    return 0;
}

