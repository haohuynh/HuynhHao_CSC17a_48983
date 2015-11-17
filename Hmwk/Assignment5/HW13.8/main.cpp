/* 
 * File:   main.cpp
 * Author: HaoHuynh
 *
 * Created on November 17, 2015, 2:57 PM
 */

#include <cstdlib>
#include <iostream>
#include "Circle.h"
using namespace std;

/*
 * The Circle main thread
 */
int main(int argc, char** argv) {

    double radius;
    
    cout << "Please enter the radius of a circle: ";
    cin >> radius;
    
    Circle* circle = new Circle(radius);
    
    cout << "The area of this circle is: " << circle->getArea() << endl;
    cout << "The diameter of this circle is: " << circle->getDiameter() << endl;
    cout << "The circumference of this circle is: " << circle->getCircumference() << endl;
    return 0;
}

