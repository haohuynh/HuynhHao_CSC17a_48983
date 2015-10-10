#include "PokerHelper.h"
#include <iostream>
#include <string>
using namespace std;

/**
 * Reference to the declaration
 */
void PokerHelper::clearMonitor() {
    cout << string(MAX_MONITOR_LINES, '\n');
}

/**
 * Reference to the declaration 
 * @param number
 * @param lowerLimit
 * @param upperLimit
 */
void PokerHelper::validateValueOf(int& number, int lowerLimit, int upperLimit) {
    while (!(cin >> number) || (number < lowerLimit) || (number > upperLimit)) {
        cin.clear();
        cin.ignore(MAX_MONITOR_LINES, '\n');
        cout << "Invalid Input! Please reenter your number: ";
    }
}