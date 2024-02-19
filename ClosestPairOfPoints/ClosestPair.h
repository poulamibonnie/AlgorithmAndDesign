//---------------------------------------------------------------------------
// CLOSESTPAIR.H
// Declare members exclusive to Closest Pair class.
// Author(s): Poulami Das Ghosh
//---------------------------------------------------------------------------
// Point class: This class is used to find the closest pair of points
// Assumptions: This class receives only valid input. It will have presorted
//              x-coordinates and y-coordinates list.
//---------------------------------------------------------------------------


#ifndef CLOSESTPAIR_H
#define CLOSESTPAIR_H

#include <iostream>
#include <vector>
#include <math.h>
#include "Point.h"

using namespace std;

class ClosestPair {
private:

//-------------------------- getDistance -----------------------------------//
// This function gives the eqilidean distance between two points
// Preconditions: None.
// Postconditions: None.

    double getDistance(const Point& p1, const Point& p2) const;

//-------------------------- bruteForceDistance -----------------------------------//
// This function is used to find the closest pair of points by brute force 
// comparisions. (s - e <= 3)
// Preconditions: The fuction should receive a list sorted by X-Coordinate .
// Postconditions: This function returns the minimum distance between the closest
//                 pair of points.

    double bruteForceDistance(const int& s, const int& e, const vector<Point>& xSorted) const;

//-------------------------- printResult -----------------------------------//
// This function is used to print the closest pair of ponts in each 
// recursive call 
// Preconditions: None
// Postconditions: The output should return values with maximum precision 
//                 of 4 decimal places.

    void printResult(const int& s, const int& e, const double& value) const;

//-------------------------- buildStripe -----------------------------------//
// This function is used to build the strip across the partition boundary
// Preconditions: Received presorted list based on y - coordinate. 
// Postconditions: Returns y-coordinate sorted strip.

    vector<Point> buildStripe(const double& mn,const Point &midPoint, const vector<Point>& ySorted);

//-------------------------- calculateBoundaryMin -----------------------------------//
// This function is used to compute the closest pair across boundary. 
// Preconditions: None. 
// Postconditions: None.

    void calculateBoundaryMin(double& mn, const vector<Point>& stripe);

//-------------------------- splitYsortedList -----------------------------------//
// This function divides the ysorted list to left and right half. 
// Preconditions: Requires a y-coordinate Sorted list. 
// Postconditions: None.

    void splitYsortedList(vector<Point> &ySortedLeft, vector<Point> &ySortedRight, const vector<Point> &ySorted, const Point &midPoint);

public:

//-------------------------- splitYsortedList -----------------------------------//
// This is the main solver function to compute the closest pair of points. 
// Preconditions: Receives pre-sorted list by x-coordinates & y-coordinates
// Postconditions: None.

    double findClosestPair(int s, int e, vector<Point>& xSorted, vector<Point> ySorted);
};


#endif