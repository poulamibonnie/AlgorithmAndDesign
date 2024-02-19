//---------------------------------------------------------------------------
// POINTSET.H
// Declare members exclusive to PointSet class.
// Author(s): Poulami Das Ghosh
//---------------------------------------------------------------------------
// Point class: This class stores point sorted by x-Coordinates and 
//              y-Coordinates
// Assumptions: This class receives only valid input
//---------------------------------------------------------------------------

#ifndef POINTSET_H
#define POINTSET_H

#include <iostream>
#include <vector>
#include "Point.h"

using namespace std;

class PointSet
{
private:
    vector<Point> sortedXCoordinate;
    vector<Point> sortedYCoordinate;

    //-------------------------- sortByXCoordinates -----------------------------------//
    // Sorts the coordinates by x - axis
    // Preconditions: None
    // Postconditions: New sorted vector is created with numbering

    void sortByXCoordinates(vector<Point>& points);

    //-------------------------- sortByYCoordinates -----------------------------------//
    // Sorts the coordinates by y - axis
    // Preconditions: None
    // Postconditions: None

    void sortByYCoordinates(vector<Point>& points);

public:

    //-------------------------- Constructor -----------------------------------//
    // Default Constructor for the class PointSet
    // Preconditions: None
    // Postconditions: New object is created

    PointSet() {};

    //-------------------------- Constructor -----------------------------------//
    // Parameterized Constructor for the class PointSet
    // Preconditions: None
    // Postconditions: New object is created

    PointSet(vector<Point>& inputPoints);

    //-------------------------- getSortByXCoordinates -----------------------------------//
    // Getter function to get the sorted list
    // Preconditions: None
    // Postconditions: New sorted vector is returned
    vector<Point> getSortByXCoordinates() const;

    //-------------------------- getSortByYCoordinates -----------------------------------//
    // Getter function to get the sorted list
    // Preconditions: None
    // Postconditions: New sorted vector is returned

    vector<Point> getSortByYCoordinates() const;
};

#endif