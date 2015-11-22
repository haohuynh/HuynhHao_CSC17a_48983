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

class CardTableHelper; // Forward Declaration

// Function Prototypes for Overloaded Stream Operators
ostream &operator <<(ostream &, const CardTableHelper &);

/*
 * Class Helper
 */
class CardTableHelper {
private:
    /*
     * Relative maximum lines of a monitor
     */
    static const int MAX_MONITOR_LINES = 200;

    //The content of menu options
    static const char* MENU_CONTENT;

    /**
     * The default file that stores the current bank roll
     */
    static const string DEFAULT_FILE_NAME;

    /*
     * Singleton instance
     */
    static const CardTableHelper cTHelper;
    
public:
    //Initiated money a player can have
    static const int MAX_BANK_ROLL = 100;

    //Out of money
    static const int MIN_BANK_ROLL = 0;

    //Gambling Menu Options

    static enum GAMBLING_MENU {
        POKER_GAME = 1, BLACK_JACK = 2, SAVE = 3, LOAD = 4, RESTART = 5, EXIT = 6
    } GamblingMenu;

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
    
    //Singleton pattern
    static CardTableHelper getInstance();
    
    // Friend function
    friend ostream &operator <<(ostream &, const CardTableHelper &);
    
};


#endif	/* POKERHELPER_H */

