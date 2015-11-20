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
const string AbstractCardTable::CARD_RANK_LABELS[RANKS_PER_SUIT] = {"Ace", "Two", "Three", "Four", "Five",
    "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

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
 * @param index
 * @return 
 */
bool AbstractCardTable::isCardInsertedBy(int id) {

    //Do not insert any existing card 
    if (isCardExistedBy(id)) {
        return false;
    }

    //Insert a completely new card
    crCards.push_back(populateCardBy(id));
    return true;
}

/**
 * Reference to the declaration
 */
void AbstractCardTable::displayPlayerCards() {

    cout << "The following cards are yours :\n";

    int size = crCards.size();
    //Applying pointer of array structure technique
    Card** cPointer = &crCards[0];

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
