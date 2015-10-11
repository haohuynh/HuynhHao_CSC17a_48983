/* 
 * File:   main.cpp
 * Author: HaoHuynh
 *
 * Created on October 10, 2015, 10:34 AM
 */

#include <cstdlib>
#include <iostream>

#include "PokerHelper.h"
#include "PokerCardTable.h"

using namespace std;

/*
 * The Poker Game main thread
 */
int main(int argc, char** argv) {

    //Poker Game Options

    enum POKERMENU {
        START_GAME = 1, SAVE = 2, LOAD = 3, RESTART = 4, EXIT = 5
    };

    //The content of menu options
    const char* MENU_CONTENT = "Poker Game Menu:\n"
            "1. Start Game.\n"
            "2. Save Game.\n"
            "3. Load Game.\n"
            "4. Restart.\n"
            "5. Exit.\n"
            "Please enter your option: ";

    // A game option
    int gOption;

    //A Poker game controller
    PokerCardTable* pokCTab = new PokerCardTable();

    while (true) {

        cout << MENU_CONTENT;
        PokerHelper::validateValueOf(gOption, START_GAME, EXIT);
        switch (gOption) {

            case START_GAME:
            {
                PokerHelper::clearMonitor();
                pokCTab->populateConsole();
                break;
            }
            case SAVE:
            {

                break;
            }
            case LOAD:
            {

                break;
            }
            case RESTART:
            {

                break;
            }
            case EXIT:
            {
                return 0;
            }
            default:
            {
                break;

            }
        }
    }
    return 0;
}

