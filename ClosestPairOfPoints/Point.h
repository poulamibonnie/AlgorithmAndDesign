//---------------------------------------------------------------------------
// POINT.H
// Declare members exclusive to Point class.
// Author(s): Poulami Das Ghosh
//---------------------------------------------------------------------------
// Point class: This class is used to create a point object
// Assumptions: This class receives only valid input
//---------------------------------------------------------------------------

#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <vector>

using namespace std;

class Point {
private:
    double xCoordinate;
    double yCoordinate;

public:
    //-------------------------- Constructor -----------------------------------//
    //Default Constructor for the class Point
    // Preconditions: None
    // Postconditions: New object is created
    Point() {}

    //-------------------------- Constructor -----------------------------------//
    //Parametrized Constructor for the class Point. 
    // Preconditions: Valid real number x and y - coordinates
    // Postconditions: New points created in the plane.

    Point(const double& xCor, const double& yCor);

    //-------------------------- Getter -----------------------------------//
    // Get the x-cordinate. 
    // Preconditions: None.
    // Postconditions: None.

    double getXCoordinate() const;

    //-------------------------- Getter -----------------------------------//
    // Get the y-cordinate. 
    // Preconditions: None.
    // Postconditions: None.

    double getYCoordinate() const;

};

#endif