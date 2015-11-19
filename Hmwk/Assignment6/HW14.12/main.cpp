/* 
 * File:   main.cpp
 * Author: HaoHuynh
 *
 * Created on November 18, 2015, 4:31 PM
 */

#include <cstdlib>
#include "LandTract.h"
using namespace std;

/*
 * The LandTract main thread
 */
int main(int argc, char** argv) {

    LandTract* first;
    LandTract* second;

    cout << "The first tract of land info:\n";
    first = new LandTract();

    cout << "The second tract of land info:\n";
    second = new LandTract();

    FeetInches fArea = first->getTractArea();
    FeetInches sArea = second->getTractArea();

    cout << "The area of the first tract of land is: " << fArea.getFeet() << "(feet^2)  "
            << fArea.getInches() << "(inch^2)\n";
    
    cout << "The area of the second tract of land is: " << sArea.getFeet() << "(feet^2)  "
            << sArea.getInches() << "(inch^2)\n";
    
    if (fArea == sArea){
        cout << "The tracts are of equal size.";
    }
    
    if (fArea != sArea){
        cout << "The tracts are of different size.";
    }

    return 0;
}

