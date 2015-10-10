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

    int size = crSRnks.size();

    for (int i = 0; i < size; i++) {

        if (index == crSRnks[i].id) {
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
bool PokerCardTable::insertCardBy(int index) {

    //Do not insert any existing one 
    if (isCardExistedBy(index)) {
        return false;
    }

    //Insert a completely new one
    Card newCard = populateCardBy(index);

    crCards.push_back(newCard);
    crSRnks.push_back(newCard);

    return true;
}