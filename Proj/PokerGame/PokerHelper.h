/* 
 * File:   PokerHelper.h
 * Author: HaoHuynh
 *
 * Created on October 10, 2015, 10:35 AM
 */

#ifndef POKERHELPER_H
#define	POKERHELPER_H

class PokerHelper {
private:
    /*
     * Relative maximum lines of a monitor
     */
    static const int MAX_MONITOR_LINES = 200;

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

};


#endif	/* POKERHELPER_H */

