//---------------------------------------------------------------------------
// DATAREADER.H
// Declaration of DATAREADER class members
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

#ifndef DATAREADER_H
#define DATAREADER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "Point.h"

using namespace std;

class DataReader {
private:
    vector<Point> points;
    int numPoints;

    //-------------------------- readNumPoint ---------------------------------//
    // Method to read the number of points
    // Preconditions:  None
    // Postconditions: Return valid number of points int the size or else 
    //                 throw exception. A valid input can only be an integer

    void readNumPoint(const string& inputText);

    //-------------------------- readAndCreatePoints ------------------------//
    // Method to read and create 'Point' type object.
    // Preconditions:  None
    // Postconditions: Reads and create new 'Point' type object for each entry of 
    //                 valid points in the file and store them in vector 'points'

    void readAndCreatePoint(const string& inputText);

    //-------------------------- getCleanseString -------------------------------//
    // Method to ensure the input string is valid and the points are real number
    // Preconditions:  None
    // Postconditions: This function will return remove special charaters and 
    //                 check for real number (integer for point list size and 
    //                 double for coordinates)

    string getCleanseString(const string& inputText) const;

    //-------------------------- splitStrOnSpace -------------------------------//
    // Method to split data by space
    // Preconditions:  None
    // Postconditions: Returns splitted text 

    vector<string> splitStrOnSpace(const string& inputText) const;

public:
    //-------------------------- Constructor -----------------------------------//
    // Default Constructor for the class DataReader
    // Preconditions: None
    // Postconditions: New object is created

    DataReader();

    //-------------------------- Getter Method -----------------------------------//
    // Getter method 'getPoints()' to return the list of points.
    // Preconditions: None
    // Postconditions: Returns the list of points in a vector

    vector<Point> getPoints() const;

    //-------------------------- Setter Method -----------------------------------//
    // Setter method 'setPoints()' to append point to the end of the list.
    // Preconditions: None
    // Postconditions: None

    void setPoints(const Point& currPoint);

    //-------------------------- Getter Method -----------------------------------//
    // Getter method 'getNumPoints()' to return the size of the point list.
    // Preconditions: None
    // Postconditions: Returns the list size

    int getNumPoints() const;

    //-------------------------- Setter Method -----------------------------------//
    // Setter method 'setNumPoints()' to set the size of the point list.
    // Preconditions: None
    // Postconditions: None

    void setNumPoints(const int& numLine);

    //-------------------------- fileRead ---------------------------------------//
    // Method to read the file line by line
    // Preconditions:   An input file with name program2data.txt needs to be
    //                  available in the same location as the source files with
    //                  the input data in the desired format.
    // Postconditions:  Read a validly formatted file. If the file is empty or
    //                  the program is unable to open the file, an error is
    //                  returned.

    void fileRead(const string& filename);

};

#endif