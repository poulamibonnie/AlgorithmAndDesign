//---------------------------------------------------------------------------
// POINT.CPP
// Define members exclusive to Point class.
// Author(s): Poulami Das Ghosh
//---------------------------------------------------------------------------
// Point class: This class is used to create a point object
// Assumptions: This class receives only valid input
//---------------------------------------------------------------------------

#include "Point.h"

//-------------------------- Constructor -----------------------------------//
//Parametrized Constructor for the class Point. 
// Preconditions: Valid real number x and y - coordinates
// Postconditions: New points created in the plane.

Point::Point(const double& xCor, const double& yCor) {
    this->xCoordinate = xCor;
    this->yCoordinate = yCor;
}


//-------------------------- Getter -----------------------------------//
// Get the x-cordinate. 
// Preconditions: None.
// Postconditions: None.

double Point::getXCoordinate() const {
    return this->xCoordinate;
}

//-------------------------- Getter -----------------------------------//
// Get the y-cordinate. 
// Preconditions: None.
// Postconditions: None.

double Point::getYCoordinate() const {
    return this->yCoordinate;
}
