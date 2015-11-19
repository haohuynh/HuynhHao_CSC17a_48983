/* 
 * File:   LandTract.cpp
 * Author: HaoHuynh
 * 
 * Created on November 18, 2015, 4:32 PM
 */

#include "LandTract.h"

LandTract::LandTract() {

    cout << "Please enter the length of this land tract:\n";
    cin >> length;

    cout << "Please enter the width of this land tract:\n";
    cin >> width;

}

FeetInches LandTract::getTractArea() {
    return length.multiply(width);
}


