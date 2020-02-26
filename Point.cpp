//: Point.cpp

/* 
 Title: Point.cpp
 Description: Implementation file for a Point Class
 Date: 07-Nov-2019
 Author: Andrew Shepherd
 Version: 1.0
 Copyright: 2019 Andrew Shepherd

 Purpose:  Implementation file for the operations of the Point class.
 
*/

// include and define statements
#include "Point.h"
#include <iostream>
using namespace std;

Point::Point() {}

Point::Point(int xPoint, int yPoint) {
   x = xPoint;
   y = yPoint;  
} 

Point::~Point() {  
}

void operator>> (istream& input, Point& a) {
   cout << "(" << a.x << ", " << a.y << ")";
}

Point operator+(Point a, Point b) {
   Point newPoint;
   newPoint.x = a.x + b.x;
   newPoint.y = a.y + b.y;
   return newPoint;
}

Point operator-(Point a, Point b) {
   Point newPoint;
   newPoint.x = a.x - b.x;
   newPoint.y = a.y - b.y;
   return newPoint;
}///:~
