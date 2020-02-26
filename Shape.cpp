//: Shape.cpp

/* 
 Title: Shape.cpp
 Description: Implementation file for a Shape Class
 Date: 07-Nov-2019
 Author: Andrew Shepherd
 Version: 1.0
 Copyright: 2019 Andrew Shepherd
 
 Purpose:  Implementation file for the operations of the Shape class,
           with nested Circle, Square and Triangle classes.
*/

// include and define statements
#include "Shape.h"
#include "Point.h"
#include <math.h>
#include <algorithm>
#include <iostream>
using namespace std;

// ------------------------------------------------------------------------
// Shape class functions
// ------------------------------------------------------------------------
Shape::Shape() {
}

Shape::~Shape() { 
}

double calcArea() {
   return 0;
}

double calcCirc() {
   return 0;
}

void boundBox() {
}

void Shape::display() {
}

// ------------------------------------------------------------------------
// Circle class functions
// ------------------------------------------------------------------------
Shape::Circle::Circle() {
   Point origin(0, 0);
   centre = origin;
   radius = 1.0;
}

Shape::Circle::Circle(Point a, int rad) {
   centre = a;
   radius = rad;
}

Shape::Circle::~Circle() { 
}

double Shape::Circle::calcArea(Circle a) {  // pi r squared
   return 3.14159 * a.radius * a.radius;   
}

double Shape::Circle::calcCirc(Circle a) {  // 2 pi r
   return 2.0 * 3.14159 * a.radius;  
}

void Shape::Circle::boundBox(Circle a) {
   //calculate the points
   Point one(a.centre.x - radius, a.centre.y - radius);
   Point two(a.centre.x - radius, a.centre.y + radius);
   Point three(a.centre.x + radius, a.centre.y + radius);
   Point four(a.centre.x + radius, a.centre.y - radius);

   //print the points
   cin >> one;
   cout << ", ";
   cin >> two;
   cout << ", ";
   cin >> three;
   cout << ", ";
   cin >> four;
}

void Shape::Circle::display(Circle a) {
   cout << "\nCircle details:" << endl;
   cout << "   Centre: ";
   cin >> a.centre;
   cout << "\n   Radius: " << a.radius << endl;
   cout << "   Area: " << a.calcArea(a) << endl;
   cout << "   Circumference: " << a.calcCirc(a) << endl;
   cout << "   Bounding Box: "; 
   a.boundBox(a);
   cout << endl;
}

// ------------------------------------------------------------------------
// Square class functions
// ------------------------------------------------------------------------
Shape::Square::Square() {
   Point a(0, 0), b(0, 1), c(1, 1), d(1, 0);
   one = a;
   two = b;
   three = c;
   four = d;
}

Shape::Square::Square(Point a, Point c) { 
   // two input points are diagonal corners
   // other two points are extrapolated to ensure a square is formed
   one = a;
   Point b(a.x, c.y);
   two = b;
   three = c;
   Point d(c.x, a.y);
   four = d;
}

Shape::Square::~Square() { 
}

int Shape::Square::calcArea(Square a) { // length x height
   Point tempX, tempY;
   int height, length;
   if(a.one.x > a.three.x) {
      tempX = a.one - a.three;
   } else {
      tempX = a.three - a.one;
   }
   height = tempX.x;
   if(a.one.y > a.three.y) {
      tempY = a.one - a.three;
   } else {
      tempY = a.three - a.one;
   }
   length = tempY.y;
   return length * height;
}

int Shape::Square::calcCirc(Square a) {  // 2 x (length + height)
   Point tempX, tempY;
   int height, length;
   if(a.one.x > a.three.x) {
      tempX = a.one - a.three;
   } else {
      tempX = a.three - a.one;
   }
   height = tempX.x;
   if(a.one.y > a.three.y) {
      tempY = a.one - a.three;
   } else {
      tempY = a.three - a.one;
   }
   length = tempY.y;
   cout << length << " + " << height << " + " << length << " + " <<
      height << " = ";
   return 2 * (length + height); 
}

void Shape::Square::boundBox(Square a) {
   // bounding box is same as square, so just print square points
   cin >> a.one;
   cout << ", ";
   cin >> a.two;
   cout << ", ";
   cin >> a.three;
   cout << ", ";
   cin >> a.four;
}

void Shape::Square::display(Square a) {
   cout << "\nSquare details:" << endl;
   cout << "   Point One: ";
   cin >> a.one;
   cout << "\n   Point Two: ";
   cin >> a.two;
   cout << "\n   Point Three: ";
   cin >> a.three;
   cout << "\n   Point Four: ";
   cin >> a.four;
   cout << "\n   Area: " << a.calcArea(a) << endl;
   cout << "   Perimeter: " << a.calcCirc(a) << endl;
   cout << "   Bounding Box: "; 
   a.boundBox(a);
   cout << endl;
}

// ------------------------------------------------------------------------
// Triangle class functions
// ------------------------------------------------------------------------
Shape::Triangle::Triangle() {
   Point a(0, 0), b(1, 1), c(2, 0);
   one = a;
   two = b;
   three = c;
}

Shape::Triangle::Triangle(Point a, Point b, Point c) {
   one = a;
   two = b;
   three = c;
}

Shape::Triangle::~Triangle() { 
}

double Shape::Triangle::calcArea(Triangle a) {  // Heron's forumla for SSS
   double length12, length23, length31, s;
   length12 = sqrt (((a.two.x - a.one.x) * (a.two.x - a.one.x)) +
        ((a.two.y - a.one.y) * (a.two.y - a.one.y)));
   length23 = sqrt (((a.three.x - a.two.x) * (a.three.x - a.two.x)) +
        ((a.three.y - a.two.y) * (a.three.y - a.two.y)));
   length31 = sqrt (((a.one.x - a.three.x) * (a.one.x - a.three.x)) +
        ((a.one.y - a.three.y) * (a.one.y - a.three.y)));
   s = (length12 + length23 + length31) / 2;
   return sqrt (s * (s - length12) * (s - length23) * (s - length31));
}

double Shape::Triangle::calcCirc(Triangle a) {  // add three side lengths
   double length12, length23, length31;
   length12 = sqrt (((a.two.x - a.one.x) * (a.two.x - a.one.x)) +
        ((a.two.y - a.one.y) * (a.two.y - a.one.y)));
   length23 = sqrt (((a.three.x - a.two.x) * (a.three.x - a.two.x)) +
        ((a.three.y - a.two.y) * (a.three.y - a.two.y)));
   length31 = sqrt (((a.one.x - a.three.x) * (a.one.x - a.three.x)) +
        ((a.one.y - a.three.y) * (a.one.y - a.three.y)));
   cout << length12 << " + " << length23 << " + " << length31 << " = ";
   return length12 + length23 + length31;
}

void Shape::Triangle::boundBox(Triangle a) {
   //calculate the points
   int xLow, xHigh, yLow, yHigh;
   xLow = min(a.one.x, a.two.x);
   xLow = min(xLow, a.three.x); 
   xHigh = max(a.one.x, a.two.x);
   xHigh = max(xHigh, a.three.x);
   yLow = min(a.one.y, a.two.y);
   yLow = min(yLow, a.three.y);
   yHigh = max(a.one.y, a.two.y);
   yHigh = max(yHigh, a.three.y);

   Point one(xLow, yLow);
   Point two(xLow, yHigh);
   Point three(xHigh, yHigh);
   Point four(xHigh, yLow);

   //print the points
   cin >> one;
   cout << ", ";
   cin >> two;
   cout << ", ";
   cin >> three;
   cout << ", ";
   cin >> four;
}

void Shape::Triangle::display(Triangle a) {
   cout << "\nTriangle details:" << endl;
   cout << "   Point One: ";
   cin >> a.one;
   cout << "\n   Point Two: ";
   cin >> a.two;
   cout << "\n   Point Three: ";
   cin >> a.three;
   cout << "\n   Area: " << a.calcArea(a) << endl;
   cout << "   Perimeter: " << a.calcCirc(a) << endl;
   cout << "   Bounding Box: "; 
   a.boundBox(a);
   cout << endl;

}///:~