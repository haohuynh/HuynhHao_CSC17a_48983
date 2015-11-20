/* 
 * File:   PokerHelper.h
 * Author: HaoHuynh
 *
 * Created on October 10, 2015, 10:35 AM
 */

#ifndef POKERHELPER_H
#define	POKERHELPER_H

#include <string>
#include <fstream>

class CardTableHelper {
private:
    /*
     * Relative maximum lines of a monitor
     */
    static const int MAX_MONITOR_LINES = 200;

    /**
     * The default file that stores the current bank roll
     */
    static const std::string DEFAULT_FILE_NAME;

public:

    /**
     * Clear the screen after a certain event. 
     */
    static void clearMonitor();

    /**
     * Validate input of an integer number from lowerLimit to upperLimit
     * @param number
     * @param lowerLimit
     * @param upperLimit
     */
    static void validateValueOf(int& number, int lowerLimit, int upperLimit);

    /**
     * This function saves the current bank roll to a file 
     * @param crBkRoll : the current bank roll 
     * @param fName : a file name
     */
    static void save(int crBkRoll);

    /**
     * This function loads the current bank roll from a file
     * @param crBkRoll : the current bank roll 
     * @param fName : a file name
     */
    static void load(int& crBkRoll);
};


#endif	/* POKERHELPER_H */

