/* 
 * File:   Circle.cpp
 * Author: HaoHuynh
 * 
 * Created on November 17, 2015, 2:57 PM
 */

#include "Circle.h"

/**
 * Reference to the function declaration
 */
Circle::Circle() {
    radius = 0.0;
    pi = 3.14159;
}

/**
 * Reference to the function declaration
 * @param radius
 */
Circle::Circle(double radius) {
    this->radius = radius;
    pi = 3.14159;
}

/**
 * Reference to the function declaration
 * @param radius
 */
void Circle::setRadius(double radius) {
    this->radius = radius;
}

/**
 * Reference to the function declaration
 * @return radius
 */
double Circle::getRadius() const {
    return radius;
}

/**
 * Reference to the function declaration
 * @return circle area
 */
double Circle::getArea() {
    return (pi * radius * radius);
}

/**
 * Reference to the function declaration
 * @return diameter
 */
double Circle::getDiameter() {
    return (2 * radius);
}

/**
 * Reference to the function declaration
 * @return circumference
 */
double Circle::getCircumference() {
    return (2 * pi * radius);
}