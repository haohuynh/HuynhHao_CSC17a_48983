#include "PokerCardTable.h"

using namespace std;

/**
 * Reference to the declaration
 */
PokerCardTable::PokerCardTable() {
}

/**
 * Reference to the declaration
 */
PokerCardTable::~PokerCardTable() {
    //Free all the allocated memories
    clean();
}

/**
 * Reference to the declaration
 */
CardTableHelper::GAME_BOOL PokerCardTable::populateConsole() {

    //Clean up the lists of cards 
    clean();

    //Dealing first five cards
    dealsCards();

    //Show the first five cards on console
    displayPlayerCards();

    //Interact with the player to change the existing cards if possible
    replaceCards();

    // Display new cards after the replacing process
    displayPlayerCards();

    //Check if the player win or not
    return isPlayerWin();

}

/**
 * Reference to the declaration
 * @param index
 * @return 
 */
bool PokerCardTable::isCardExistedBy(int id) {

    int size = crCards.size();

    for (int i = 0; i < size; i++) {

        if (id == crCards[i]->id) {
            return true;
        }
    }

    return false;
}

/**
 * Reference to the declaration
 */
void PokerCardTable::dealsCards() {

    for (int i = 0; i < FIVE_POKER_CARDS; i++) {
        while (!isCardInsertedBy(rand() % CARDS_TOTAL));
    }

}

/**
 * Reference to the declaration
 * @param index
 */
AbstractCardTable::Card* PokerCardTable::getNewCardForReplacement() {
    Card* newCard = dealsNewCard();

    //Collecting all cards that have been dealt to assure that there is no duplication happens
    crCards.push_back(newCard);

    return newCard;
}

/**
 * Reference to the declaration
 */
void PokerCardTable::replaceCards() {

    // The number of cards the player want to replace
    int nRCards;

    cout << "How many cards you want to replace? ";
    CardTableHelper::validateValueOf(nRCards, INDEX_0, FIVE_POKER_CARDS);

    if (nRCards > 0) {

        //The on-screen index of a card needs replacing 
        int rIndex;

        //The list of on-screen indexes of cards need replacing 
        set<int> rIndexes;

        //The return value is used for checking duplicated on-screen indexes
        pair < set<int>::iterator, bool> ret;

        /*
         * Create a copy of all current hand cards, because crCards will be used for 
         * containing the first five cards and new cards for the replacement process.
         */
        vector<Card*> bkCrCds(crCards);

        if (nRCards < FIVE_POKER_CARDS) { //Replace any 1,2,3, or 4 cards

            cout << "What are they? Please enter the index(es) of "
                    << nRCards << " card(s) you want to replace: \n";

            //Collecting on-screen positions of cards need replacing
            for (int i = 0; i < nRCards; i++) {
                cout << "Index number " << i + 1 << ": ";

                do {
                    CardTableHelper::validateValueOf(rIndex, INDEX_1, FIVE_POKER_CARDS);
                    ret = rIndexes.insert(rIndex);

                    if (!ret.second) { //rIndex was already existed
                        cout << "The index was duplicated !!! Please enter another one: ";
                    }

                } while (!ret.second);

            }

            //Do actual replacements on bkCrCds 
            //while use crCards to store all cards have been dealt
            for (set<int>::iterator rIdIt = rIndexes.begin(); rIdIt != rIndexes.end(); rIdIt++) {
                bkCrCds[(*rIdIt) - 1] = getNewCardForReplacement();
            }

            //Deallocate the memories of the replaced cards
            deleteCardsBy(crCards, rIndexes);

        } else {//Replacing all five cards

            //Add new five poker cards
            for (int i = 0; i < nRCards; i++) {
                bkCrCds[i] = getNewCardForReplacement();
            }

            //Deallocate the memories of the first five poker cards
            for (int i = 0; i < nRCards; i++) {
                delete crCards[i];
            }
            crCards.clear();
        }

        //The replacement process is done and crCards show have a new combination of only five cards
        crCards = bkCrCds;
    }

}

/**
 * Reference to the declaration
 */
void PokerCardTable::sortCardsByRank() {

    vector<Card*>::iterator cardIt;

    for (int i = 0; i < FIVE_POKER_CARDS; i++) {

        for (cardIt = crSRnks.begin(); (cardIt != crSRnks.end())
                && ((*cardIt)->rank < crCards[i]->rank); cardIt++);

        crSRnks.insert(cardIt, crCards[i]);
    }
}

/**
 * Reference to the declaration
 */
void PokerCardTable::sortCardsBySuit() {

    vector<Card*>::iterator cardIt;

    for (int i = 0; i < FIVE_POKER_CARDS; i++) {

        for (cardIt = crSSuits.begin(); (cardIt != crSSuits.end())
                && ((*cardIt)->suit < crCards[i]->suit); cardIt++);

        crSSuits.insert(cardIt, crCards[i]);
    }
}

/**
 * Reference to the declaration
 * @return true/false
 */
bool PokerCardTable::isRoyalFlush() {
    return ((crSRnks[INDEX_0]->rank == ACE) && isStraightFlush());
}

/**
 * Reference to the declaration
 * @return true/false
 */
bool PokerCardTable::isStraightFlush() {
    return (isFlush() && isStraight());
}

/**
 * Reference to the declaration
 * @return true/false
 */
bool PokerCardTable::isFlush() {
    return (crSSuits[INDEX_0]->suit == crSSuits[INDEX_4]->suit);
}

/**
 * Reference to the declaration
 * @return true/false
 */
bool PokerCardTable::isStraight() {

    if (crSRnks[INDEX_0]->rank == ACE) { //Case 1 {ACE, TEN, JACK, QUEEN, KING} 
        //or {ACE, TWO, THREE, FOUR, FIVE}

        if (crSRnks[INDEX_1]->rank == TEN && crSRnks[INDEX_2]->rank == JACK
                && crSRnks[INDEX_3]->rank == QUEEN && crSRnks[INDEX_4]->rank == KING) {
            return true;
        }

        if (crSRnks[INDEX_1]->rank == TWO && crSRnks[INDEX_2]->rank == THREE
                && crSRnks[INDEX_3]->rank == FOUR && crSRnks[INDEX_4]->rank == FIVE) {
            return true;
        }

        return false;

    } else {//Case 2 Continuously Increasing
        //rc: A rank counter
        for (int rc = (crSRnks[INDEX_0]->rank + 1), i = 1; i < FIVE_POKER_CARDS; rc++, i++) {
            if (rc != crSRnks[i]->rank) {
                return false;
            }
        }
        return true;
    }

}

/**
 * Reference to the declaration
 * @return true/false
 */
bool PokerCardTable::isFourOfAKind() {

    //Case: 4 + 1 
    if ((crSRnks[INDEX_0]->rank == crSRnks[INDEX_1]->rank)
            && (crSRnks[INDEX_1]->rank == crSRnks[INDEX_2]->rank)
            && (crSRnks[INDEX_2]->rank == crSRnks[INDEX_3]->rank)) {
        return true;
    }

    //Case 1 + 4
    if ((crSRnks[INDEX_1]->rank == crSRnks[INDEX_2]->rank)
            && (crSRnks[INDEX_2]->rank == crSRnks[INDEX_3]->rank)
            && (crSRnks[INDEX_3]->rank == crSRnks[INDEX_4]->rank)) {
        return true;
    }

    return false;
}

/**
 * Reference to the declaration
 * @return true/false
 */
bool PokerCardTable::isFullHouse() {

    //Case 3 + 2
    if ((crSRnks[INDEX_0]->rank == crSRnks[INDEX_1]->rank)
            && (crSRnks[INDEX_1]->rank == crSRnks[INDEX_2]->rank)
            && (crSRnks[INDEX_3]->rank == crSRnks[INDEX_4]->rank)) {
        return true;
    }

    //Case 2 + 3
    if ((crSRnks[INDEX_0]->rank == crSRnks[INDEX_1]->rank)
            && (crSRnks[INDEX_2]->rank == crSRnks[INDEX_3]->rank)
            && (crSRnks[INDEX_3]->rank == crSRnks[INDEX_4]->rank)) {
        return true;
    }

    return false;
}

/**
 * Reference to the declaration
 * @return true/false
 */
bool PokerCardTable::isThreeOfAKind() {

    //Case 3 + 1 + 1
    if ((crSRnks[INDEX_0]->rank == crSRnks[INDEX_1]->rank)
            && (crSRnks[INDEX_1]->rank == crSRnks[INDEX_2]->rank)) {
        return true;
    }

    //Case 1 + 3 + 1
    if ((crSRnks[INDEX_1]->rank == crSRnks[INDEX_2]->rank)
            && (crSRnks[INDEX_2]->rank == crSRnks[INDEX_3]->rank)) {
        return true;
    }

    //Case 1 + 1 + 3
    if ((crSRnks[INDEX_2]->rank == crSRnks[INDEX_3]->rank)
            && (crSRnks[INDEX_3]->rank == crSRnks[INDEX_4]->rank)) {
        return true;
    }

    return false;
}

/**
 * Reference to the declaration
 * @return true/false
 */
bool PokerCardTable::isTwoPairs() {

    //Case 2 + 2 + 1
    if ((crSRnks[INDEX_0]->rank == crSRnks[INDEX_1]->rank)
            && (crSRnks[INDEX_2]->rank == crSRnks[INDEX_3]->rank)) {
        return true;
    }

    //Case 2 + 1 + 2
    if ((crSRnks[INDEX_0]->rank == crSRnks[INDEX_1]->rank)
            && (crSRnks[INDEX_3]->rank == crSRnks[INDEX_4]->rank)) {
        return true;
    }

    //Case 1 + 2 + 2
    if ((crSRnks[INDEX_1]->rank == crSRnks[INDEX_2]->rank)
            && (crSRnks[INDEX_3]->rank == crSRnks[INDEX_4]->rank)) {
        return true;
    }

    return false;
}

/**
 * Reference to the declaration
 * @return true/false
 */
bool PokerCardTable::isPair() {

    //Case: 2 + 1 + 1 + 1
    if (crSRnks[INDEX_0]->rank == crSRnks[INDEX_1]->rank) {
        return true;
    }

    //Case: 1 + 2 + 1 + 1 
    if (crSRnks[INDEX_1]->rank == crSRnks[INDEX_2]->rank) {
        return true;
    }

    //Case: 1 + 1 + 2 + 1 
    if (crSRnks[INDEX_2]->rank == crSRnks[INDEX_3]->rank) {
        return true;
    }

    //Case: 1 + 1 + 1 + 2 
    if (crSRnks[INDEX_3]->rank == crSRnks[INDEX_4]->rank) {
        return true;
    }

    return false;
}

/**
 * Reference to the declaration
 * @return  -1/0/1:  /drawn/lose/win/
 */
CardTableHelper::GAME_BOOL PokerCardTable::isPlayerWin() {

    //Sorting the current cards for checking a result
    sortCardsByRank();
    sortCardsBySuit();

    if (isRoyalFlush()) {
        cout << "A Royal Flush!!!\n";

    } else if (isStraightFlush()) {
        cout << "A Straight Flush!!\n";

    } else if (isFlush()) {
        cout << "A Flush!\n";

    } else if (isStraight()) {
        cout << "A Straight!\n";

    } else if (isFourOfAKind()) {
        cout << "Four of the same kind!\n";

    } else if (isFullHouse()) {
        cout << "Full house!\n";

    } else if (isThreeOfAKind()) {
        cout << "Three of the same kind!\n";

    } else if (isTwoPairs()) {
        cout << "Two pairs!\n";

    } else if (isPair()) {
        cout << "A pair!\n";

    } else {
        cout << "You lose !!!\n";
        return CardTableHelper::LOSE;
    }

    cout << "Congratulation! You are the winner !!!\n";
    return CardTableHelper::WIN;
}

/**
 * Reference to the declaration
 * @param cards : a vector of Card Structure pointers
 * @param poss : a set of positions in cards
 */
void PokerCardTable::deleteCardsBy(vector<Card*>& cards, const set<int>& poss) {

    for (set<int>::iterator posIt = poss.begin(); posIt != poss.end(); posIt++) {
        delete cards[(*posIt) - 1];
    }

    cards.clear();
}

/**
 * Reference to the declaration
 */
void PokerCardTable::clean() {

    //Clean up crCards for a new game
    deleteCards(crCards);

    //Both crSRnks and crSSuits reference to the same memories in crCards
    crSRnks.clear();
    crSSuits.clear();
}

