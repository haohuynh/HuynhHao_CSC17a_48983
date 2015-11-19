/* 
 * File:   LandTract.h
 * Author: HaoHuynh
 *
 * Created on November 18, 2015, 4:32 PM
 */

#ifndef LANDTRACT_H
#define	LANDTRACT_H

#include "FeetInches.h"

/**
 * Make a LandTract class that is composed of two FeetInches objects, one for the
 * tract’s length and one for the width. The class should have a member function that
 * returns the tract’s area. Demonstrate the class in a program that asks the user to enter
 * the dimensions for two tracts of land. The program should display the area of each
 * tract of land and indicate whether the tracts are of equal size.
 * 
 */
class LandTract {

private:
    FeetInches length;
    FeetInches width;
    
public:
    LandTract();
    FeetInches getTractArea();


};

#endif	/* LANDTRACT_H */

