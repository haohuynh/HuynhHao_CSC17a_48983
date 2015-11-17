/* 
 * File:   Circle.h
 * Author: HaoHuynh
 *
 * Created on November 17, 2015, 2:57 PM
 */

#ifndef CIRCLE_H
#define	CIRCLE_H

class Circle {
    
private:
    
    /*
     * The R of this circle
     */
    double radius;
    
    /*
     * The value 3.14159
     */
    double pi;
    
public:
    
    /**
     * This default constructor sets radius to 0.0.
     */
    Circle();
    
    /**
     * Accepts the radius of the circle as an argument
     * @param radius
     */
    Circle(double radius);

    /**
     * A mutator function for the radius variable.
     * @param radius
     */
    void setRadius(double radius);
    
    /**
     * An getter for the radius variable
     * @return 
     */
    double getRadius() const;
    
    /**
     * Returns the area of the circle.
     * @return area = pi * radius * radius
     */
    double getArea();
    
    /**
     * Returns the diameter of the circle.
     * @return diameter = radius * 2
     */
    double getDiameter();
    
    /**
     * Returns the circumference of the circle.
     * @return circumference = 2 * pi * radius
     */
    double getCircumference();
    
};

#endif	/* CIRCLE_H */

