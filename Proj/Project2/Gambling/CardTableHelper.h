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
#include <iostream>
using namespace std;

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
     * The bool type for this program
     */
    static enum GAME_BOOL {
        DRAWN = -1, LOSE = 0, WIN = 1
    } GameBool;

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
     * Clean up the cin buffer
     */
    static void cleanCin();

    /**
     * This function saves the current bank roll to a file 
     * @param crBkRoll : the current bank roll 
     * @param fName : a file name
     */
    template <typename T>
    static void save(T crBkRoll) {

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
     * This function loads the current bank roll from a file
     * @param crBkRoll : the current bank roll 
     * @param fName : a file name
     */
    template <typename T>
    static void load(T& crBkRoll) {

        fstream* fs = new fstream(DEFAULT_FILE_NAME.c_str(), ios::in | ios::binary);

        fs->exceptions(fstream::failbit | fstream::badbit);

        try {
            fs->read(reinterpret_cast<char*> (&crBkRoll), sizeof (crBkRoll));
        } catch (fstream::failure e) {
            cerr << "File IO exception!!! \n";
        }

        fs->close();

    }
};


#endif	/* POKERHELPER_H */

