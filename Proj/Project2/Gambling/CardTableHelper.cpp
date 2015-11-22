#include "CardTableHelper.h"
#include "PokerCardTable.h"

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
        cleanCin();
        cout << "Invalid Input! Please reenter your number: ";
    }
}

/**
 *  Reference to the declaration 
 */
void CardTableHelper::cleanCin() {
    cin.clear();
    cin.ignore(MAX_MONITOR_LINES, '\n');
}
