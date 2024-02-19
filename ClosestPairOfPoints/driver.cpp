//---------------------------------------------------------------------------
// DRIVER.CPP
// This is the driver function that will be used to run the application.
// Author(s): Poulami Das Ghosh
//---------------------------------------------------------------------------
// This file contains the main() method that will execute all other methods.
//
// Assumptions:
//   -- The input file name will be program2data.txt
//   -- The input file will be available in the same location.
//---------------------------------------------------------------------------

#include "DataReader.h"
#include "PointSet.h"
#include "ClosestPair.h"
#include "Point.h"
#include <vector>

using namespace std;

//---------------------------- Main -------------------------------------------
// Main function for getting the closest pair of point by divide and
// conquer method
// Preconditions:   An input file with name program2data.txt needs to be
//                  available in the same location as the source files with
//                  the input data in the desired format.
// Postconditions:  The closest pair should be displayed on the console with
//                  each line  as per indices. The indices are after sorting by 
//                  x-coordinate and the distances include all points in between 
//                  the two indices. The output should also have 4 digits of 
//                  precision and must not contain leading or trailing spaces.

int main() {

    try {
        // Read input from the file
        DataReader reader;
        reader.fileRead("program2data.txt");

        vector<Point> points;
        points = reader.getPoints();

        if (reader.getNumPoints() != points.size()) {
            std::cerr << "Error: Number of points defined doesnot match the number of coordinates provided" << std::endl;
            throw 0;
        }

        PointSet sorter(points);

        // Sort by X-Coordinates
        vector<Point> XSortedList = sorter.getSortByXCoordinates();

        // Sort by Y-Cordunates
        vector<Point>  YSortedList = sorter.getSortByYCoordinates();

        //Get the closest pair of points
        ClosestPair solver;

        int start = 0;
        int end = (int) points.size() - 1;

        solver.findClosestPair(start, end, XSortedList, YSortedList);

    }
    catch (...) {
        std::cerr << "Finding Closest Pair Failed" << std::endl;
        return 0;
    }

    return 0;
}