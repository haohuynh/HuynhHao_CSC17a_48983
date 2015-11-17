/* 
 * File:   main.cpp
 * Author: HaoHuynh
 *
 * Created on November 17, 2015, 12:03 PM
 */

#include <cstdlib>
#include <iostream>
#include "Car.h"
using namespace std;

/*
 * The Car main thread
 */
int main(int argc, char** argv) {

    Car* car = new Car(2020, "Toyota");

    for (int i = 0; i < 5; i++) {
        car->accelerate();
        cout << car->getSpeed() << " ";
    }

    cout << endl;

    for (int i = 0; i < 5; i++) {
        car->brake();
        cout << car->getSpeed() << " ";
    }

    return 0;
}

