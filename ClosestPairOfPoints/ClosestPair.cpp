//---------------------------------------------------------------------------
// CLOSESTPAIR.CPP
// Define members exclusive to Closest Pair class.
// Author(s): Poulami Das Ghosh
//---------------------------------------------------------------------------
// Point class: This class is used to find the closest pair of points
// Assumptions: This class receives only valid input. It will have presorted
//              x-coordinates and y-coordinates list.
//---------------------------------------------------------------------------

#include <iomanip>
#include <limits>
#include <float.h>
#include "ClosestPair.h"

//-------------------------- getDistance -----------------------------------//
// This function gives the eqilidean distance between two points
// Preconditions: None.
// Postconditions: None.

double ClosestPair::getDistance(const Point& p1, const Point& p2) const
{
    double p1_x = p1.getXCoordinate();
    double p1_y = p1.getYCoordinate();
    double p2_x = p2.getXCoordinate();
    double p2_y = p2.getYCoordinate();

    return sqrt(pow(p2_x - p1_x, 2) + pow(p2_y - p1_y, 2));
}

//-------------------------- bruteForceDistance -----------------------------------//
// This function is used to find the closest pair of points by brute force 
// comparisions. (s - e <= 3)
// Preconditions: The fuction should receive a list sorted by X-Coordinate .
// Postconditions: This function returns the minimum distance between the closest
//                 pair of points.

double ClosestPair::bruteForceDistance(const int& s, const int& e, const vector<Point>& xSorted) const {
    double mn = DBL_MAX;

    for (int i = s; i <= e; i++) {
        for (int j = i + 1; j <= e; j++) {
            mn = min(mn, this->getDistance(xSorted[i], xSorted[j]));
        }
    }
    return mn;
}

//-------------------------- printResult -----------------------------------//
// This function is used to print the closest pair of ponts in each 
// recursive call 
// Preconditions: None
// Postconditions: The output should return values with maximum precision 
//                 of 4 decimal places.

void ClosestPair::printResult(const int& s, const int& e, const double& value) const {
    cout << "D[" << s << "," << e << "]: " << round(value * 10000.0) / 10000.0 << endl;
    return;
}

//-------------------------- buildStripe -----------------------------------//
// This function is used to build the strip across the partition boundary
// Preconditions: Received presorted list based on y - coordinate. 
// Postconditions: Returns y-coordinate sorted strip.

vector<Point> ClosestPair::buildStripe(const double& mn,const Point &midPoint, const vector<Point>& ySorted) {
    vector<Point> stripe;
    int size = (int) ySorted.size();

    for (int i = 0; i < size; i++) {
        if (abs(ySorted[i].getXCoordinate() - midPoint.getXCoordinate()) < mn) {
            stripe.push_back(ySorted[i]);
        }
    }

    return stripe;

}

//-------------------------- calculateBoundaryMin -----------------------------------//
// This function is used to compute the closest pair across boundary. 
// Preconditions: None. 
// Postconditions: None.

void ClosestPair::calculateBoundaryMin(double &mn, const vector<Point>& stripe)
{

    int size = (int)stripe.size();

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < min(i + 7, size); j++) {
            double dis = this->getDistance(stripe[i], stripe[j]);
            if (mn > dis) {
                mn = dis;
            }
        }
    }

    return;
}

//-------------------------- splitYsortedList -----------------------------------//
// This function divides the ysorted list to left and right half. 
// Preconditions: Requires a y-coordinate Sorted list. 
// Postconditions: None.

void ClosestPair::splitYsortedList(vector<Point> &ySortedLeft, vector<Point> &ySortedRight, const vector<Point> &ySorted, const Point &midPoint)
{
    int size = (int) ySorted.size();
    for (int i = 0; i < size; i++) {
        if (ySorted[i].getXCoordinate() <= midPoint.getXCoordinate()) {
            ySortedLeft.push_back(ySorted[i]);
        }
        else {
            ySortedRight.push_back(ySorted[i]);
        }
    }
}

//-------------------------- splitYsortedList -----------------------------------//
// This is the main solver function to compute the closest pair of points. 
// Preconditions: Receives pre-sorted list by x-coordinates & y-coordinates
// Postconditions: None.

double ClosestPair::findClosestPair(int s, int e, vector<Point>& xSorted, vector<Point> ySorted)
{
    if (e - s + 1 <= 3) {
        //Since only 3 points we apply brute force.
        double mn_dis = bruteForceDistance(s, e, xSorted);
        printResult(s, e, mn_dis);
        return mn_dis;
    }

    int mid = s + (e - s) / 2;
    Point midPoint = xSorted[mid];

    // Build the left and right ySortedList
    vector<Point> ySortedLeft;
    vector<Point> ySortedRight;
    this->splitYsortedList(ySortedLeft, ySortedRight, ySorted, midPoint);

    // Find minimum distance in left half and right half
    double mn_l = findClosestPair(s, mid, xSorted, ySortedLeft);
    double mn_r = findClosestPair(mid + 1, e, xSorted, ySortedRight);
    double mn = min(mn_l, mn_r);

    // Find if the closest pair lies accross boundary.
    vector<Point> stripe = buildStripe(mn, midPoint, ySorted);
    calculateBoundaryMin(mn, stripe);

    printResult(s, e, mn);
    return mn;
}
