#include "PokerHelper.h"
#include "PokerCardTable.h"
#include <iostream>
#include <string>
using namespace std;

const string PokerHelper::DEFAULT_FILE_NAME = "data.bin";

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

/**
 * Reference to the declaration 
 * @param crBkRoll
 * @param fName
 */
void PokerHelper::save(int crBkRoll) {
    fstream* fs = new fstream(DEFAULT_FILE_NAME.c_str(), ios::out | ios::binary);

    if (fs) {

        fs->write(reinterpret_cast<char*> (&crBkRoll), sizeof (crBkRoll));
        fs->close();

    } else {
        cerr << "File I/O error !";
    }
}

/**
 * Reference to the declaration  
 * @param crBkRoll
 * @param fName
 */
void PokerHelper::load(int& crBkRoll) {
    fstream* fs = new fstream(DEFAULT_FILE_NAME.c_str(), ios::in | ios::binary);

    if (fs) {

        fs->read(reinterpret_cast<char*> (&crBkRoll), sizeof (crBkRoll));
        fs->close();

    } else {
        cerr << "File I/O error !";
    }

}