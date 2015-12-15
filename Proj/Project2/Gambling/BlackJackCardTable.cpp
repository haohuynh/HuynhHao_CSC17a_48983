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
CardTableHelper::GAME_BOOL BlackJackCardTable::populateConsole() {

    //Clean up the lists of cards 
    clean();

    //Dealing first four cards for the player and the dealer, alternatively
    dealsCards(BJ_INIT_N_CARDS);

    //Show the dealer 's second card on console
    displayDealerCards();

    //Show the player's first two cards on console
    displayCards(crCards);

    //Interact with the player for the hit-or-stay process
    processPlayerTurn();

    //Try to make deal win the game
    processDealerTurn();

    return isPlayerWin();
}

/**
 * Reference to the declaration
 * @return  -1/0/1:  /drawn/lose/win/
 */
CardTableHelper::GAME_BOOL BlackJackCardTable::isPlayerWin() {

    //Getting the dealer 's and the player's BJ score
    int plyScre = calculateScore(crCards);
    int dlrScre = calculateScore(crDCrds);

    if (plyScre > BJ_UPPER_WINNER_LIMIT) {
        plyScre = BJ_BUST;
    }

    if ((dlrScre > BJ_UPPER_WINNER_LIMIT) && (plyScre != BJ_BUST)) {
        dlrScre = BJ_BUST;
    }

    if (plyScre > dlrScre) {

        cout << "You are the winner!!";
        return CardTableHelper::WIN;

    } else if (plyScre < dlrScre) {

        cout << "You lose!!!";
        return CardTableHelper::LOSE;

    } else {
        cout << "Drawn game!";
        return CardTableHelper::DRAWN;
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
int BlackJackCardTable::calculateScore(vector<Card*> cards) {

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

        } else {// The gap between a managed rank and a real rank is 2
            result += cards[index]->rank + 2;
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

/**
 * Reference to the function declaration 
 * @param isPD : is the player done.
 */
void BlackJackCardTable::displayDealerCards(bool isPD) {

    if (!isPD) {

        cout << "Dealer has:\n";

        //Display only the second card being occupied the dealer
        cout << "Card 1: Secret!!!\n";
        cout << "Card 2: " << CARD_SUIT_LABELS[crDCrds[1]->suit] << "-";
        cout << CARD_RANK_LABELS[crDCrds[1]->rank] << " " << endl;
        return;

    }

    //After the player finished his or her turn, show all dealer 's cards
    displayCards(crDCrds, "Dealer");
}

/**
 * Reference to the function declaration 
 */
void BlackJackCardTable::processPlayerTurn() {

    int usrReq; //user request
    bool isHOS; //is hit over stay

    do {

        isHOS = false;

        cout << "Would you like to hit(1) or stay(2) ? ";
        CardTableHelper::validateValueOf(usrReq, BJ_PLAYER_HIT, BJ_PLAYER_HIT + 1);

        if (usrReq == BJ_PLAYER_HIT) {

            crCards.push_back(dealsNewCard());

            CardTableHelper::clearMonitor();

            displayDealerCards();

            displayCards(crCards);

            isHOS = true;
        }


    } while (isHOS && (crCards.size() < BJ_PLAYER_CARD_LIMIT));
}

/**
 *  Reference to the function declaration 
 */
void BlackJackCardTable::processDealerTurn() {

    isSAce = false;

    // Get the current dealer 's score
    int dlrScre = calculateScore(crDCrds);

    //Dealer must hit on at least a soft 17
    while (dlrScre < BJ_LOWER_WINNER_LIMIT) {

        crDCrds.push_back(dealsNewCard());
        dlrScre = calculateScore(crDCrds);

    }

    //If the score of dealer is soft 17,
    //the dealer must then continue to hit until it has a hard 17 or higher
    if ((dlrScre == BJ_LOWER_WINNER_LIMIT) && (isSAce)) {

        crDCrds.push_back(dealsNewCard());
        dlrScre = calculateScore(crDCrds);

    }
    while (dlrScre < BJ_LOWER_WINNER_LIMIT) {

        crDCrds.push_back(dealsNewCard());
        dlrScre = calculateScore(crDCrds);

    }

    //Show all cards belonging to the dealer
    displayDealerCards(true);
}