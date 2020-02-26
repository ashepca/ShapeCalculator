//: Point.h

/* 
 Title: Point.h
 Description: Header file for a Point Class
 Date: 07-Nov-2019
 Author: Andrew Shepherd
 Version: 1.0
 Copyright: 2019 Andrew Shepherd

 Purpose: Interface file for the data and operations of the Point class.
*/

// include and define statements
#ifndef POINT_H
#define POINT_H
#include <iostream>
using namespace std; 

class Point {
 
public:
   int x;
   int y;  
   Point(); // Default Constructor to point (0,0)
   Point(int xPoint, int yPoint); // Constructor with x, y value input
   ~Point(); // Destructor
   friend void operator>> (istream& input, Point& a);
   friend Point operator+(Point a, Point b); // add 2 point coordinates
   friend Point operator-(Point a, Point b); // subtract 2 point coordinates
};
#endif // POINT_H ///:~
