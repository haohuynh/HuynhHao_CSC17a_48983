/* 
 * File:   main.cpp
 * Author: HaoHuynh
 *
 * Created on November 18, 2015, 2:00 PM
 */

#include <cstdlib>
#include "FeetInches.h"
using namespace std;

/*
 * The FeetInches main thread
 */
int main(int argc, char** argv) {

    FeetInches first, second; // Define two objects.

    // Get a distance for the first object.
    cout << "Enter a distance in feet and inches.\n";
    cin >> first;

    //Testing the copy constructor
    FeetInches third(first);
    
    // Get a distance for the second object. 
    cout << "Enter another distance in feet and inches.\n";
    cin >> second;

    // Display the values in the objects.
    cout << "The values you entered are:\n";
    cout << third << " and " << second << endl;
    
    cout << "Let first multiply second be:\n";
    cout << first.multiply(second);
            
    return 0;
}

