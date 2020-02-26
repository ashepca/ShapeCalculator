//: Shape.h

/* 
 Title: Shape.h
 Description: Header file for a Shape Class
 Date: 07-Npv-2019
 Author: Andrew Shepherd
 Version: 1.0
 Copyright: 2019 Andrew Shepherd

 Purpose:  Interface file for the data and operations of the Shape class, with 
           nested Circle, Square and Triangle classes.
*/

// include and define statements
#ifndef SHAPE_H
#define SHAPE_H
#include "Point.h"

class Shape {

public:
   Shape(); // Constructor
   ~Shape(); // Destructor
   double calcArea();
   double calcCirc();
   void boundBox();
   void display();

   class Circle {
      Point centre;
      int radius;
   public:
      Circle(); // default Constructor
      Circle(Point a, int rad); // constructor with input
      ~Circle(); // Destructor
      double calcArea(Circle a);
      double calcCirc(Circle a);
      void boundBox(Circle a);
      void display(Circle a);
   };

   class Square {
      Point one, two, three, four;
   public:
      Square(); // default Constructor
      Square(Point a, Point c); // constructor with input
      ~Square(); // Destructor
      int calcArea(Square a);
      int calcCirc(Square a);
      void boundBox(Square a);
      void display(Square a);
   };

   class Triangle {
      Point one, two, three;
   public:
      Triangle(); // default Constructor
      Triangle(Point a, Point b, Point c); // constructor with input
      ~Triangle(); // Destructor   
      double calcArea(Triangle a);
      double calcCirc(Triangle a);
      void boundBox(Triangle a);
      void display(Triangle a);
   };
};
#endif // SHAPE_H ///:~
