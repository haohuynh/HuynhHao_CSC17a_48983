#include "CardTableHelper.h"
#include "PokerCardTable.h"
#include <iostream>
#include <string>
using namespace std;

const string CardTableHelper::DEFAULT_FILE_NAME = "data.bin";

/**
 * Reference to the declaration
 */
void CardTableHelper::clearMonitor() {
    cout << string(MAX_MONITOR_LINES, '\n');
}

/**
 * Reference to the declaration 
 * @param number
 * @param lowerLimit
 * @param upperLimit
 */
void CardTableHelper::validateValueOf(int& number, int lowerLimit, int upperLimit) {
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
void CardTableHelper::save(int crBkRoll) {
    fstream* fs = new fstream(DEFAULT_FILE_NAME.c_str(), ios::out | ios::binary);

    fs->exceptions(fstream::failbit | fstream::badbit);

    try {
        fs->write(reinterpret_cast<char*> (&crBkRoll), sizeof (crBkRoll));
    } catch (fstream::failure e) {
        cerr << "File IO exception!!! \n";
    }

    fs->close();

}

/**
 * Reference to the declaration  
 * @param crBkRoll
 * @param fName
 */
void CardTableHelper::load(int& crBkRoll) {
    fstream* fs = new fstream(DEFAULT_FILE_NAME.c_str(), ios::in | ios::binary);

    fs->exceptions(fstream::failbit | fstream::badbit);

    try {
        fs->read(reinterpret_cast<char*> (&crBkRoll), sizeof (crBkRoll));
    } catch (fstream::failure e) {
        cerr << "File IO exception!!! \n";
    }

    fs->close();

}