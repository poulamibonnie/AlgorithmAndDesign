#include "DataReader.h"
#include "Entity.h"
#include "Person.h"
#include "Pet.h"
#include "StableMatching.h"

int main() {
    DataReader reader;
    reader.fileRead("program1data.txt");

    StableMatching matcher;
    matcher.setOptimals(reader.getFirstParty());
    matcher.setPessimals(reader.getSecondParty());

    matcher.solver();
    matcher.printStableMatch();

    return 0;
}

