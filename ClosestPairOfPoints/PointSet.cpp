//---------------------------------------------------------------------------
// POINTSET.H
// Declare members exclusive to PointSet class.
// Author(s): Poulami Das Ghosh
//---------------------------------------------------------------------------
// Point class: This class stores point sorted by x-Coordinates and 
//              y-Coordinates
// Assumptions: This class receives only valid input
//---------------------------------------------------------------------------

#include "PointSet.h"
#include <algorithm>

//-------------------------- Constructor -----------------------------------//
// Parameterized Constructor for the class PointSet
// Preconditions: None
// Postconditions: New object is created

PointSet::PointSet(vector<Point>& inputPoints) {
    this->sortByXCoordinates(inputPoints);
    this->sortByYCoordinates(inputPoints);
}

//-------------------------- sortByXCoordinates -----------------------------------//
// Sorts the coordinates by x - axis
// Preconditions: None
// Postconditions: New sorted vector is created

bool static compX(const Point& p1, const Point& p2) {
    return p1.getXCoordinate() < p2.getXCoordinate();
}

void PointSet::sortByXCoordinates(vector<Point>& points) {
    sort(points.begin(), points.end(), compX);
    sortedXCoordinate = points;
}

//-------------------------- sortByYCoordinates -----------------------------------//
// Sorts the coordinates by y - axis
// Preconditions: None
// Postconditions: New sorted vector is created 

bool compY(const Point& p1, const Point& p2) {
    return p1.getYCoordinate() < p2.getYCoordinate();
}

void PointSet::sortByYCoordinates(vector<Point>& points) {
    sort(points.begin(), points.end(), compY);
    sortedYCoordinate = points;
}

//-------------------------- getSortByYCoordinates -----------------------------------//
// Getter function to get the sorted list
// Preconditions: None
// Postconditions: New sorted vector is returned

vector<Point> PointSet::getSortByYCoordinates() const {
    return this->sortedYCoordinate;
}


//-------------------------- getSortByXCoordinates -----------------------------------//
// Getter function to get the sorted list
// Preconditions: None
// Postconditions: New sorted vector is created with numbering

vector<Point> PointSet::getSortByXCoordinates() const {
    return this->sortedXCoordinate;
}
