/* 
 * File:   main.cpp
 * Author: HaoHuynh
 *
 * Created on October 10, 2015, 10:34 AM
 */

#include "PokerCardTable.h"
#include "BlackJackCardTable.h"
using namespace std;

/**
 * Prepare screen for any new game
 * @param crBkRoll : The current bank roll
 * @param crrBet : The current bet
 * @param crGame : The current game (Poker/BlackJack)
 */
void setUpGameScreen(int crBkRoll, int& crrBet, string crGame = "five poker game.") {

    CardTableHelper::clearMonitor();

    cout << "You are playing " << crGame << endl;
    cout << "Your current bank roll is: " << crBkRoll << endl;
    cout << "How much you want to bet for the game: ";
    CardTableHelper::validateValueOf(crrBet, 1, crBkRoll);

    CardTableHelper::clearMonitor();

}

/*
 * The Poker Game main thread
 */
int main(int argc, char** argv) {

    //The current bank roll
    int crBkRoll = CardTableHelper::MAX_BANK_ROLL;

    //The current money that a player wants to bet
    int crrBet;

    //A game option
    int gOption;

    //A player request
    string pReq;

    //A Poker game controller
    AbstractCardTable* pokCTab = new PokerCardTable();

    //A BlackJack game controller
    AbstractCardTable* bJCTab = new BlackJackCardTable();

    //A game result
    CardTableHelper::GAME_BOOL result;

    while (true) {

        cout << "Your current bank roll is: " << crBkRoll << endl;
        cout << CardTableHelper::getInstance(); //Operator << overriding
        CardTableHelper::validateValueOf(gOption, CardTableHelper::POKER_GAME, CardTableHelper::EXIT);

        do {
            switch (gOption) {

                case CardTableHelper::POKER_GAME:
                {
                    setUpGameScreen(crBkRoll, crrBet);
                    result = pokCTab->populateConsole();

                    if (result == CardTableHelper::WIN) { //The player win a game
                        crBkRoll += crrBet;

                    } else if (result == CardTableHelper::LOSE) {//The player lose a game
                        crBkRoll -= crrBet;
                    }

                    break;
                }
                case CardTableHelper::BLACK_JACK:
                {
                    setUpGameScreen(crBkRoll, crrBet, "BlackJack.");
                    result = bJCTab->populateConsole();

                    if (result == CardTableHelper::WIN) { //The player win a game
                        crBkRoll += crrBet;

                    } else if (result == CardTableHelper::LOSE) {//The player lose a game
                        crBkRoll -= crrBet;
                    }

                    break;

                }
                case CardTableHelper::SAVE:
                {
                    CardTableHelper::save(crBkRoll);
                    break;
                }
                case CardTableHelper::LOAD:
                {
                    CardTableHelper::load(crBkRoll);
                    break;
                }
                case CardTableHelper::RESTART:
                {
                    crBkRoll = CardTableHelper::MAX_BANK_ROLL;
                    break;
                }
                case CardTableHelper::EXIT:
                {
                    return 0;
                }
                default:
                {
                    break;

                }
            }

            // The player still have money and want to continue on the game
            if ((crBkRoll > CardTableHelper::MIN_BANK_ROLL)
                    && ((gOption == CardTableHelper::POKER_GAME) || (gOption == CardTableHelper::BLACK_JACK))) {
                cout << "Your current bank roll is: " << crBkRoll << endl;
                cout << "\nWould you like to continue (y/n): ";
                CardTableHelper::cleanCin();
                cin >> pReq;

            } else { // Out of money

                pReq = "Stop!";

            }

        } while (tolower(pReq[0]) == 'y');

        //The player is out of money
        if (crBkRoll <= CardTableHelper::MIN_BANK_ROLL) {
            cout << "\nOut of money!! You have to start a new game (y/n): ";
            CardTableHelper::cleanCin();
            cin >> pReq;

            if (tolower(pReq[0]) != 'y') {
                return 0;
            }

            crBkRoll = CardTableHelper::MAX_BANK_ROLL;
        }

        CardTableHelper::clearMonitor();

        //Notifying players about the saving and loading process
        if (gOption == CardTableHelper::SAVE) {
            cout << "The current bank roll " << crBkRoll << " saved\n";

        } else if (gOption == CardTableHelper::LOAD) {
            cout << "The current bank roll " << crBkRoll << " loaded\n";
        }

    }
    return 0;
}

