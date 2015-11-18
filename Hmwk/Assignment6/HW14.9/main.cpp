/* 
 * File:   main.cpp
 * Author: HaoHuynh
 *
 * Created on November 18, 2015, 9:59 AM
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

    // Get a distance for the second object.
    cout << "Enter another distance in feet and inches.\n";
    cin >> second;

    // Display the values in the objects.
    cout << "The values you entered are:\n";
    cout << first << " and " << second << endl;

    // Compare the two objects.
    if (first != second)
        cout << "first is different from second.\n";
    if (first >= second)
        cout << "first is greater than or equal to second.\n";
    if (first <= second)
        cout << "first is less than or equal to second.\n";

    return 0;
}

