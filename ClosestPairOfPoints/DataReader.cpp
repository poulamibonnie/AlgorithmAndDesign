//---------------------------------------------------------------------------
// DATAREADER.H
// Defination of DATAREADER class members
// Author(s): Poulami Das Ghosh
//---------------------------------------------------------------------------
// DATAREADER class: This is the data reader class that is used to read 
// input from the file.
//   It includes the following features:
//   - It reads and create a list of point object from the file.
//   - It reads the size of the point list.
//   - It checks the validity of the file
//   - It perform cleansing operation on each line


// Assumptions:
//   -- The input file will always be available in the same directory.
//   -- The coordinates should be a real number (double not integer).
//   -- File Format:
//      - file will consist of n points, with n specified on the first line, 
//        and n additional lines containing the x- and y-coordinates, 
//        which will be real numbers (not integers). 
//---------------------------------------------------------------------------

#include "DataReader.h"
//-------------------------- Constructor -----------------------------------//
// Default Constructor for the class DataReader
// Preconditions: None
// Postconditions: New object is created

DataReader::DataReader() {
    numPoints = 0;
}

//-------------------------- Setter Method -----------------------------------//
// Setter method 'setNumPoints()' to set the size of the point list.
// Preconditions: None
// Postconditions: None

void DataReader::setNumPoints(const int& numLine) {
    this->numPoints = numLine;
}


//-------------------------- Getter Method -----------------------------------//
// Getter method 'getNumPoints()' to return the size of the point list.
// Preconditions: None
// Postconditions: Returns the list size

int DataReader::getNumPoints() const {
    return this->numPoints;
}

//-------------------------- Setter Method -----------------------------------//
// Setter method 'setPoints()' to append point to the end of the list.
// Preconditions: None
// Postconditions: None

void DataReader::setPoints(const Point& currPoint) {
    this->points.push_back(currPoint);
}

//-------------------------- Getter Method -----------------------------------//
// Getter method 'getPoints()' to return the list of points.
// Preconditions: None
// Postconditions: Returns the list of points in a vector

vector<Point> DataReader::getPoints() const {
    return this->points;
}

//-------------------------- readNumPoint ---------------------------------//
// Method to read the number of points
// Preconditions:  None
// Postconditions: Return valid number of points int the size or else 
//                 throw exception. A valid input can only be an integer

void DataReader::readNumPoint(const string& inputText) {
    int numOfPoints = 0;
    try {
        // Convert input string to integer and store as numOfPoints
        numOfPoints = stoi(inputText);
        this->setNumPoints(numOfPoints);
        // Validate that entity size is in the allowed range
        // If it is not, throw an error and exit
        if (numOfPoints < 1) {
            std::cerr << "Error: Number Of Points should be greater than 0" << endl;
            throw 0;
        }
    }
    // The catch blocks handle any exceptions thrown by stoi().
    // The error is reported and then we exit.
    catch (const std::invalid_argument& e) {
        std::cerr << "Error:  Number Of Points [" << e.what() << "]" << endl;
        throw 0;
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Error:  Number Of Points [" << e.what() << "]" << endl;
        throw 0;
    }
    return;
}

//-------------------------- readAndCreatePoints ------------------------//
// Method to read and create 'Point' type object.
// Preconditions:  None
// Postconditions: Reads and create new 'Point' type object for each entry of 
//                 valid points in the file and store them in vector 'points'

void DataReader::readAndCreatePoint(const string& inputText) {
    istringstream ss(inputText);
    string coordinate_str;
    vector<string> coordinate;
    double xcoordinate, ycoordinate;

    try {
        coordinate = this->splitStrOnSpace(inputText);
        if (coordinate.size() != 2) {
            std::cerr << "Error: Invalid Coordinates" << endl;
            throw 0;
        }
        xcoordinate = stod(coordinate[0]);
        ycoordinate = stod(coordinate[1]);
        Point pt(xcoordinate, ycoordinate);
        this->setPoints(pt);
    }
    // The catch blocks handle any exceptions thrown by stod().
    // The error is reported and then we exit.
    catch (const std::invalid_argument& e) {
        std::cerr << "Error: Coordinates [" << e.what() << "]" << endl;
        throw 0;
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Error:  Coordinatess [" << e.what() << "]" << endl;
        throw 0;
    }

}

//-------------------------- splitStrOnSpace -------------------------------//
// Method to split data by space
// Preconditions:  None
// Postconditions: Returns splitted text 

vector<string> DataReader::splitStrOnSpace(const string& inputText) const {
    vector<string> coordinate;
    istringstream ss(inputText);
    string coordinate_str;

    while (ss >> coordinate_str)
    {
        if (coordinate_str.empty()) {
            continue;
        }
        coordinate.push_back(coordinate_str);
    }

    return coordinate;
}

//-------------------------- getCleanseString -------------------------------//
// Method to ensure the input string is valid and the points are real number
// Preconditions:  None
// Postconditions: This function will return remove special charaters and 
//                 check for real number (integer for point list size and 
//                 double for coordinates)

string DataReader::getCleanseString(const string& inputText) const {
    string cleanseStr = "";
    for (int i = 0; i < inputText.size(); i++) {
        // Ensure that all characters are in range [0-9][Space][.]
        if (
            inputText[i] >= '0' && inputText[i] <= '9') {
            cleanseStr += inputText[i];
        }
        else if (!cleanseStr.empty() && inputText[i] == ' ' || inputText[i] == '.' || inputText[i] == '-') {
            cleanseStr += inputText[i];
        }
    }

    return cleanseStr;
}

//-------------------------- fileRead ---------------------------------------//
// Method to read the file line by line
// Preconditions:   An input file with name program2data.txt needs to be
//                  available in the same location as the source files with
//                  the input data in the desired format.
// Postconditions:  Read a validly formatted file. If the file is empty or
//                  the program is unable to open the file, an error is
//                  returned.

void DataReader::fileRead(const string& filename) {
    ifstream inputFile(filename);
    string myText;
    int loopCounter = 0;

    if (!inputFile.is_open()) {
        // Failed to open file, report error and exit
        std::cerr << "Error opening the file." << std::endl;
        throw 0;
    }

    if (inputFile.peek() == std::ifstream::traits_type::eof()) {
        // File is empty, report error and exit
        std::cerr << "Error: Empty File" << std::endl;
        inputFile.close();
        throw 0;
    }

    try {
        while (getline(inputFile, myText)) {
            if (loopCounter == 0) {
                // If it is the first line, extract the number of points
                this->readNumPoint(myText);
            }
            else {
                // The coordinates are extracted here
                string input = this->getCleanseString(myText);

                if (input.empty()) {
                    loopCounter++;
                    continue;
                }
                this->readAndCreatePoint(input);
            }
            loopCounter++;
        }
    }
    catch (...) {
        inputFile.close();
        throw 0;
    }

    inputFile.close();
    return;

}