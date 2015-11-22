/* 
 * File:   AbstractCardTable.cpp
 * Author: HaoHuynh
 * 
 * Created on November 20, 2015, 10:03 AM
 */

#include "AbstractCardTable.h"

/**
 * Reference to the declaration
 */
const string AbstractCardTable::CARD_SUIT_LABELS[SUIT_MAX] = {"Hearts", "Diamonds", "Clubs", "Spades"};

/**
 * Reference to the declaration
 */
const string AbstractCardTable::CARD_RANK_LABELS[RANKS_PER_SUIT] = {"Two", "Three", "Four", "Five",
    "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"};

/**
 * Reference to the method declaration
 */
AbstractCardTable::AbstractCardTable() {
    //Seeding a value for the random function
    srand(time(NULL));
}

/**
 * Reference to the declaration
 * @param index
 * @return 
 */
AbstractCardTable::Card* AbstractCardTable::populateCardBy(int id) {
    Card* card = new Card;
    card->id = id;
    card->suit = static_cast<CARD_SUITS> (id / RANKS_PER_SUIT);
    card->rank = static_cast<CARD_RANKS> (id % RANKS_PER_SUIT);
    return card;
}

/**
 * Reference to the declaration
 */
void AbstractCardTable::displayCards(vector<Card*> cards, string subject) {

    cout << "The following cards are belong to " << subject << ":\n";

    int size = cards.size();
    //Applying pointer of array structure technique
    Card** cPointer = &cards[0];

    for (int i = 0; i < size; i++) {
        cout << "Card " << i + 1 << ": " << CARD_SUIT_LABELS[(*(cPointer + i))->suit] << "-"
                << CARD_RANK_LABELS[(*(cPointer + i))->rank] << " \n";

    }

}

/**
 * Reference to the declaration
 */
AbstractCardTable::Card* AbstractCardTable::dealsNewCard() {

    int randId;

    do {
        randId = rand() % CARDS_TOTAL;
    } while (isCardExistedBy(randId));

    return populateCardBy(randId);

}

/**
 * Reference to the declaration
 * @param cards : a vector of Card Structure pointers
 */
void AbstractCardTable::deleteCards(vector<Card*>& cards) {
    int size = cards.size();

    for (int i = 0; i < size; i++) {
        delete cards[i];
    }

    cards.clear();
}

/**
 * Reference to the declaration
 * @param index
 * @return 
 */
bool AbstractCardTable::isCardExistedBy(int id) {

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
 * @param nOfCds
 */
void AbstractCardTable::dealsCards(int nOfCds) {

    for (int i = 0; i < nOfCds; i++) {
        crDCrds.push_back(dealsNewCard());
        crCards.push_back(dealsNewCard());
    }

}