/* 
 * File:   Car.cpp
 * Author: HaoHuynh
 * 
 * Created on November 17, 2015, 12:03 PM
 */

#include "Car.h"

/**
 * Reference to the function declaration
 */
Car::Car() {
}

/**
 * Reference to the function declaration
 * @param orig
 */
Car::Car(int yModel, string mk) {
    yearModel = yModel;
    make = mk;
    speed = 0;
}

/**
 * Reference to the function declaration
 * @return 
 */
int Car::getYearModel() const{
    return yearModel;
}

/**
 * Reference to the function declaration
 * @return 
 */
string Car::getMake() const{
    return make;
}

/**
 * Reference to the function declaration
 * @return 
 */
int Car::getSpeed() const{
    return speed;
}

