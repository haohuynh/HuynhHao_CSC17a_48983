#include "PokerCardTable.h"
#include <cstdlib>
#include <time.h>       

/**
 * Reference to the declaration
 */
PokerCardTable::PokerCardTable() {
    srand(time(NULL));
}

/**
 * Reference to the declaration
 * @param index
 * @return 
 */
Card PokerCardTable::populateCardBy(int index) {
    Card card;
    card.id = index;
    card.suit = static_cast<CARD_SUITS> (index / RANKS_PER_SUIT);
    card.rank = static_cast<CARD_RANKS> (index % RANKS_PER_SUIT);
    return card;
}

/**
 * Reference to the declaration
 * @param index
 * @return 
 */
bool PokerCardTable::isCardExistedBy(int index) {

    int size = crCards.size();

    for (int i = 0; i < size; i++) {

        if (index == crCards[i].id) {
            return true;
        }
    }

    return false;
}

/**
 * Reference to the declaration
 * @param index
 * @return 
 */
bool PokerCardTable::isCardInsertedBy(int index) {

    //Do not insert any existing card 
    if (isCardExistedBy(index)) {
        return false;
    }

    //Insert a completely new card
    crCards.push_back(populateCardBy(index));
    return true;
}

/**
 * Reference to the declaration
 */
void PokerCardTable::dealtCards() {

    for (int i = 0; i < FIVE_POKER_CARDS; i++) {
        while (!isCardInsertedBy(rand() % CARDS_TOTAL));
    }

}