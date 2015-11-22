#include "CardTableHelper.h"
#include "PokerCardTable.h"

/**
 * Reference to the declaration
 */

const string CardTableHelper::DEFAULT_FILE_NAME = "data.bin";

/**
 * Reference to the declaration
 */
const char* MENU_CONTENT = "Gambling Menu Options:\n"
        "1. Poker (v2).\n"
        "2. BlackJack.\n"
        "3. Save Game.\n"
        "4. Load Game.\n"
        "5. Restart.\n"
        "6. Exit.\n"
        "Please enter your option: ";

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

/**
 *  Reference to the declaration 
 */
CardTableHelper CardTableHelper::getInstance() {
    return cTHelper;
}

/**
 *  Reference to the declaration 
 */
ostream &operator <<(ostream &strm, const CardTableHelper & obj) {
    strm << MENU_CONTENT;
    return strm;
}