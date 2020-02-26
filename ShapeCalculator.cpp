//: ShapeCalculator.cpp

/* 
 Title: ShapeCalculator.cpp
 Description: Program that creates shape objects and displays information 
 Date: 07-Nov-2019
 Author: Andrew Shepherd
 Version: 1.0
 Copyright: 2019 Andrew Shepherd
 
 Purpose:  The program is intended to create shapes - circles, squares and
           triangles - and display information about each object.

 Compile (with GNU C++):  g++ -o ShapeCalculator.cpp Point.cpp Shape.cpp
 
 Classes: Point, Shape

 Variables:   inputRadius - integer - holds value of circle radius
              inputX - integer - holds value of input point coordinate X
              inputY - integer - holds value of input point coordinate Y
*/

// include and define statements
#include "Point.h"
#include "Shape.h"
#include <iostream>
using namespace std;

// ------------------------------------------------------------------------
// Function: main()
// Purpose:  Main execution of the program
// Inputs:  none
// ------------------------------------------------------------------------

int main(void) {

   //variables
   int inputRadius = -1;
   int inputX, inputY;

   // request input for a circle
   cout << "\nLet's make a circle. Enter radius (integer value, e.g. 23): ";
   cin >> inputRadius;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
   while(inputRadius < 0) {
      cout << "Value must be a positive integer.  Try again: ";
      cin >> inputRadius;
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
   }
   cout << "Enter centre point x coordinate (integer value, e.g. 1): ";
   cin >> inputX;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
   cout << "Enter centre point y coordinate (integer value, e.g. 2): ";
   cin >> inputY;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
   Point inputCentre(inputX, inputY);

   //create and display circle
   Shape::Circle inputCircle(inputCentre, inputRadius);
   inputCircle.display(inputCircle);

   // request input for a square
   cout << "\nLet's make a square. Provide 2 diagonal corner points." << endl;
   cout << "Enter point one x coordinate (integer value, e.g. 1): ";
   cin >> inputX;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
   cout << "Enter point one y coordinate (integer value, e.g. 2): ";
   cin >> inputY;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
   Point inputOne(inputX, inputY);
   cout << "Enter point two x coordinate (integer value, e.g. 3): ";
   cin >> inputX;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
   cout << "Enter point two y coordinate (integer value, e.g. 4): ";
   cin >> inputY;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
   Point inputTwo(inputX, inputY);

   //create and display square
   Shape::Square inputSquare(inputOne, inputTwo);
   inputSquare.display(inputSquare);

   // request input for a triangle
   cout << "\nNow let's make a triangle. Provide 3 points." << endl;
   cout << "Enter point one x coordinate (integer value, e.g. 1): ";
   cin >> inputX;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
   cout << "Enter point one y coordinate (integer value, e.g. 2): ";
   cin >> inputY;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
   Point input1(inputX, inputY);
   cout << "Enter point two x coordinate (integer value, e.g. 3): ";
   cin >> inputX;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
   cout << "Enter point two y coordinate (integer value, e.g. 4): ";
   cin >> inputY;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
   Point input2(inputX, inputY);
   cout << "Enter point three x coordinate (integer value, e.g. 5): ";
   cin >> inputX;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
   cout << "Enter point three y coordinate (integer value, e.g. 6): ";
   cin >> inputY;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
   Point input3(inputX, inputY);

   //create and display triangle
   Shape::Triangle inputTriangle(input1, input2, input3);
   inputTriangle.display(inputTriangle);

   cout << endl;

} ///:~
