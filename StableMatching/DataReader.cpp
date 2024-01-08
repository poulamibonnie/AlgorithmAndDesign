#include "DataReader.h"

vector<Person> DataReader::getFirstParty() {
    return this->firstParty;
}


vector<Pet> DataReader::getSecondParty() {
    return this->secondParty;
}


int DataReader::getEntitySize() {
    return this->entitySize;
}


string DataReader::getCleanseString(string str) {
    string cleanseStr = "";
    for(int i = 0; i < str.size(); i++) {
        if((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')) {
            cleanseStr += str[i];
        }
    }
    return cleanseStr;
}


void DataReader::fileRead(string filename) {
    ifstream inputFile(filename);
    string myText;

    int loopCounter = 0;

    if (inputFile.is_open()) {
        while (getline (inputFile, myText)) {
            if(loopCounter == 0) {
                entitySize = stoi(myText);
            }
            else if (loopCounter >= 1 && loopCounter <= entitySize){
                Person firstPartyMember = Person(getCleanseString(myText));
                firstParty.push_back(firstPartyMember);
            }
            else if(loopCounter >= entitySize + 1 && loopCounter <= (entitySize * 2)) {
                firstParty[ loopCounter - entitySize - 1 ].setPreference(myText);
            }
            else if(loopCounter >= (entitySize * 2) + 1 && loopCounter <= (entitySize * 3)) {
                Pet secondPartyMember = Pet(getCleanseString(myText));
                secondParty.push_back(secondPartyMember);
            }
            else{
                secondParty[ loopCounter - (3 * entitySize) - 1 ].setRevIdxPreference(myText, entitySize);
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
