/* 
 * File:   FeetInches.h
 * Author: HaoHuynh
 *
 * Created on November 18, 2015, 10:01 AM
 */

#ifndef FEETINCHES_H
#define	FEETINCHES_H

#include <cstdlib>
#include <iostream>
using namespace std;

class FeetInches; // Forward Declaration

// Function Prototypes for Overloaded Stream Operators
ostream &operator <<(ostream &, const FeetInches &);
istream &operator >>(istream &, FeetInches &);

// The FeetInches class holds distances or measurements
// expressed in feet and inches.

class FeetInches {
private:

    int feet; // To hold a number of feet
    int inches; // To hold a number of inches
    void simplify(); // Defined in FeetInches.cpp    

public:

    // Constructor

    FeetInches(int f = 0, int i = 0) {

        feet = f;
        inches = i;
        simplify();

    }

    /**
     * Add a copy constructor to the FeetInches class. This constructor should accept
     * a FeetInches object as an argument. The constructor should assign to the feet
     * attribute the value in the argument’s feet attribute, and assign to the inches attribute
     * the value in the argument’s inches attribute. As a result, the new object will be a copy
     * of the argument object
     * @param fInches
     */
    FeetInches(const FeetInches& fInches) {
        feet = fInches.feet;
        inches = fInches.inches;
        simplify();
    }


    // Mutator functions

    void setFeet(int f) {
        feet = f;
    }

    void setInches(int i) {
        inches = i;
        simplify();
    }

    // Accessor functions

    int getFeet() const {
        return feet;
    }

    int getInches() const {
        return inches;
    }

    // Overloaded operator functions
    FeetInches operator +(const FeetInches &); // Overloaded +
    FeetInches operator -(const FeetInches &); // Overloaded -
    FeetInches operator ++(); // Prefix ++
    FeetInches operator ++(int); // Postfix ++
    bool operator>(const FeetInches &); // Overloaded >
    bool operator<(const FeetInches &); // Overloaded <
    bool operator ==(const FeetInches &); // Overloaded ==
    bool operator<=(const FeetInches &); // Overloaded <=
    bool operator>=(const FeetInches &); // Overloaded >=
    bool operator !=(const FeetInches &); // Overloaded ==

    FeetInches multiply(const FeetInches&);

    // Friends
    friend ostream &operator <<(ostream &, const FeetInches &);
    friend istream &operator >>(istream &, FeetInches &);
};

#endif	/* FEETINCHES_H */

