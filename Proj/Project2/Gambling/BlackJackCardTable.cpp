/* 
 * File:   BlackJackCardTable.cpp
 * Author: HaoHuynh
 * 
 * Created on November 20, 2015, 10:05 AM
 */

#include "BlackJackCardTable.h"

/**
 * Reference to the declaration
 */
BlackJackCardTable::BlackJackCardTable() {
}

/**
 * Reference to the declaration
 */
BlackJackCardTable::~BlackJackCardTable() {
    //Free all the allocated memories
    clean();
}

/**
 * Reference to the declaration
 */
short BlackJackCardTable::populateConsole() {

}

/**
 * Reference to the declaration
 * @param index
 * @return 
 */
bool BlackJackCardTable::isCardExistedBy(int id) {

    int index;
    int size = crCards.size();
    //Check all current player's cards
    for (index = 0; index < size; index++) {

        if (id == crCards[index]->id) {
            return true;
        }
    }

    size = crDCrds.size();
    //Check all current dealer 's cards
    for (index = 0; index < size; index++) {

        if (id == crDCrds[index]->id) {
            return true;
        }
    }

    return false;
}

/**
 * Reference to the declaration
 */
void BlackJackCardTable::dealsCards() {

    for (int i = 0; i < INIT_BJ_CARDS; i++) {
        crDCrds.push_back(dealsNewCard());
        crCards.push_back(dealsNewCard());
    }

}

/**
 * Reference to the declaration
 * @return  1/0/-1:  win/lose/drawn
 */
short BlackJackCardTable::isPlayerWin() {

    //Getting the dealer 's and the player's BJ score
    int plyScre = calculateBJScore(crCards);
    int dlrScre = calculateBJScore(crDCrds);

    if (plyScre > BJ_UPPER_WINNER_LIMIT) {
        plyScre = BJ_BUST;
    }

    if (dlrScre > BJ_UPPER_WINNER_LIMIT) {
        dlrScre = BJ_BUST;
    }


    if (plyScre > dlrScre) {

        cout << "You are the winner!!";
        return 1;

    } else if (plyScre < dlrScre) {

        cout << "You lose!!!";
        return 0;

    } else {
        cout << "Drawn game!";
        return -1;
    }

}

/**
 * Reference to the declaration
 */
void BlackJackCardTable::clean() {

    //Clean up crCards for a new game
    deleteCards(crCards);

    //Clean up crDCrds for a new game
    deleteCards(crDCrds);

}

/**
 * Reference to the declaration 
 * @param cards
 * @return 
 */
int BlackJackCardTable::calculateBJScore(vector<Card*> cards) {

    int size = cards.size();

    int index;

    int result = 0;

    vector<Card*> aces;

    // Adding up all type of cards except for the Aces
    for (index = 0; index < size; index++) {
        if (cards[index]->rank == ACE) {

            aces.push_back(cards[index]);

        } else if ((cards[index]->rank == JACK) || (cards[index]->rank == QUEEN)
                || (cards[index]->rank == KING)) {

            result += BJ_JACK_QUEEN_KING;

        } else {
            result += cards[index]->rank + 1;
        }
    }

    // Determine the value of the Aces; then add them to the total
    size = aces.size();

    for (index = 0; index < size; index++) {

        if ((result + BJ_SOFT_ACE) <= BJ_UPPER_WINNER_LIMIT) {

            isSAce = true;
            result += BJ_SOFT_ACE;

        } else {

            result += BJ_HARD_ACE;

        }
    }

    return result;
}