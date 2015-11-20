/* 
 * File:   main.cpp
 * Author: HaoHuynh
 *
 * Created on October 10, 2015, 10:34 AM
 */

#include "PokerCardTable.h"
using namespace std;

/**
 * Prepare screen for any new game
 * @param crBkRoll : The current bank roll
 * @param crrBet : The current bet
 */
void setUpGameScreen(int crBkRoll, int& crrBet) {

    CardTableHelper::clearMonitor();

    cout << "You are playing five card Poker game." << endl;
    cout << "Your current bank roll is: " << crBkRoll << endl;
    cout << "How much you want to bet for the game: ";
    CardTableHelper::validateValueOf(crrBet, 1, crBkRoll);

    CardTableHelper::clearMonitor();

}

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


    //Initiated money a player can have
    const int MAX_BANK_ROLL = 100;

    //Out of money
    const int MIN_BANK_ROLL = 0;

    //The current bank roll
    int crBkRoll = MAX_BANK_ROLL;

    //The current money that a player wants to bet
    int crrBet;

    //A game option
    int gOption;

    //A player request
    string pReq;

    //A Poker game controller
    AbstractCardTable* pokCTab = new PokerCardTable();

    while (true) {

        cout << "Your current bank roll is: " << crBkRoll << endl;
        cout << MENU_CONTENT;
        CardTableHelper::validateValueOf(gOption, START_GAME, EXIT);

        do {
            switch (gOption) {

                case START_GAME:
                {
                    setUpGameScreen(crBkRoll, crrBet);

                    if (pokCTab->populateConsole() == 1) { //The player win a game
                        crBkRoll += crrBet;

                    } else if (pokCTab->populateConsole() == 0) {//The player lose a game
                        crBkRoll -= crrBet;
                    }

                    break;
                }
                case SAVE:
                {
                    CardTableHelper::save(crBkRoll);
                    break;
                }
                case LOAD:
                {
                    CardTableHelper::load(crBkRoll);
                    break;
                }
                case RESTART:
                {
                    crBkRoll = MAX_BANK_ROLL;
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

            // The player still have money and want to continue on the game
            if ((crBkRoll > MIN_BANK_ROLL) && (gOption == START_GAME)) {
                cout << "Your current bank roll is: " << crBkRoll << endl;
                cout << "\nWould you like to continue (y/n): ";
                cin >> pReq;

            } else { // Out of money

                pReq = "Stop!";

            }

        } while (tolower(pReq[0]) == 'y');

        //The player is out of money
        if (crBkRoll <= MIN_BANK_ROLL) {
            cout << "\nOut of money!! You have to start a new game (y/n): ";
            cin >> pReq;

            if (tolower(pReq[0]) != 'y') {
                return 0;
            }

            crBkRoll = MAX_BANK_ROLL;
        }

        CardTableHelper::clearMonitor();

        //Notifying players about the saving and loading process
        if (gOption == SAVE) {
            cout << "The current bank roll " << crBkRoll << " saved\n";

        } else if (gOption == LOAD) {
            cout << "The current bank roll " << crBkRoll << " loaded\n";
        }

    }
    return 0;
}

