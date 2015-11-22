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
    dealsCards(FIVE_POKER_CARDS);

    //Show the first five cards on console
    displayCards(crCards);

    //Interact with the player to change the existing cards if possible
    replaceCards();

    // Display new cards after the replacing process
    displayCards(crCards);

    // Display dealer 's cards
    displayCards(crDCrds, "Dealer");

    //Check if the player win or not
    return isPlayerWin();

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
void PokerCardTable::sortCardsByRank(const vector<Card*>& cards) {

    vector<Card*>::iterator cardIt;
    crSRnks.clear();

    for (int i = 0; i < FIVE_POKER_CARDS; i++) {

        for (cardIt = crSRnks.begin(); (cardIt != crSRnks.end())
                && ((*cardIt)->rank < cards[i]->rank); cardIt++);

        crSRnks.insert(cardIt, cards[i]);
    }
}

/**
 * Reference to the declaration
 */
void PokerCardTable::sortCardsBySuit(const vector<Card*>& cards) {

    vector<Card*>::iterator cardIt;
    crSSuits.clear();

    for (int i = 0; i < FIVE_POKER_CARDS; i++) {

        for (cardIt = crSSuits.begin(); (cardIt != crSSuits.end())
                && ((*cardIt)->suit < cards[i]->suit); cardIt++);

        crSSuits.insert(cardIt, cards[i]);
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

    cout << "\nThe player's result:\n";
    int plyrScr = calPokerScore(crCards); //Calculate the final score of the player
    cout << "Poker score: " << plyrScr << endl;

    cout << "\nThe dealer 's result:\n";
    int dlerScr = calPokerScore(crDCrds); //Calculate the final score of the dealer
    cout << "Poker score: " << dlerScr << "\n\n";

    if (plyrScr > dlerScr) {
        cout << "Congratulation! You are the winner !!!\n";
        return CardTableHelper::WIN;

    } else if (plyrScr < dlerScr) {
        cout << "You lose!\n";
        return CardTableHelper::LOSE;
    }
    cout << "Drawn game!!\n";
    return CardTableHelper::DRAWN;
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

    //Clean up crCards & cdDCards for a new game
    deleteCards(crCards);
    deleteCards(crDCrds);

    //Both crSRnks and crSSuits reference to the same memories in crCards
    crSRnks.clear();
    crSSuits.clear();
}

/**
 * Reference to the declaration
 * @return 
 */
int PokerCardTable::getHandScore() {

    int sum = crSRnks[INDEX_0]->rank;
    int e = BASE_SCORE;

    for (int i = 1; i < crSRnks.size(); i++) {
        sum += e * crSRnks[i]->rank;
        e *= BASE_SCORE;
    }

    return sum;
}

/**
 * Reference to the declaration
 * @return 
 */
int PokerCardTable::getRoyalFlushScore() {
    return ROYAL_FLUSH_SCORE + getHandScore();
}

/**
 * Reference to the declaration
 * @return 
 */
int PokerCardTable::getStraightFlushScore() {
    return STRAIGHT_FLUSH_SCORE + getHandScore();
}

/**
 * Reference to the declaration
 * @return 
 */
int PokerCardTable::getFlushScore() {
    return FLUSH_SCORE + getHandScore();
}

/**
 * Reference to the declaration
 * @return 
 */
int PokerCardTable::getStraightScore() {
    return STRAIGHT_SCORE + getHandScore();
}

/**
 * Reference to the declaration
 * @return 
 */
int PokerCardTable::getFourOfAKindScore() {
    return FOUR_OF_A_KIND_SCORE + crSRnks[INDEX_2]->rank;
}

/**
 * Reference to the declaration
 * @return 
 */
int PokerCardTable::getFullHouseScore() {
    return FULL_HOUSE_SCORE + crSRnks[INDEX_2]->rank;
}

/**
 * Reference to the declaration
 * @return 
 */
int PokerCardTable::getThreeOfAKindScore() {
    return THREE_OF_A_KIND_SCORE + crSRnks[INDEX_2]->rank;
}

/**
 * Reference to the declaration
 * @return 
 */
int PokerCardTable::getTwoPairScore() {
    int sum = 0;

    if ((crSRnks[INDEX_0]->rank == crSRnks[INDEX_1]->rank)
            && (crSRnks[INDEX_2]->rank == crSRnks[INDEX_3]->rank)) {
        //Case 2 + 2 + 1
        sum = crSRnks[INDEX_4]->rank + (BASE_SCORE * crSRnks[INDEX_0]->rank)
                + (BASE_SCORE * BASE_SCORE * crSRnks[INDEX_2]->rank);

    } else if ((crSRnks[INDEX_0]->rank == crSRnks[INDEX_1]->rank)
            && (crSRnks[INDEX_3]->rank == crSRnks[INDEX_4]->rank)) {
        //Case 2 + 1 + 2
        sum = crSRnks[INDEX_2]->rank + (BASE_SCORE * crSRnks[INDEX_0]->rank)
                + (BASE_SCORE * BASE_SCORE * crSRnks[INDEX_3]->rank);
        ;
    } else {//Case 1 + 2 + 2

        sum = crSRnks[INDEX_0]->rank + (BASE_SCORE * crSRnks[INDEX_1]->rank)
                + (BASE_SCORE * BASE_SCORE * crSRnks[INDEX_3]->rank);

    }

    return TWO_PAIR_SCORE + sum;
}

/**
 * Reference to the declaration
 * @return 
 */
int PokerCardTable::getAPairScore() {

    int sum = 0;
    //Case: 2 + 1 + 1 + 1
    if (crSRnks[INDEX_0]->rank == crSRnks[INDEX_1]->rank) {

        sum = crSRnks[INDEX_2]->rank + BASE_SCORE * crSRnks[INDEX_3]->rank
                + BASE_SCORE * BASE_SCORE * crSRnks[INDEX_4]->rank
                + BASE_SCORE * BASE_SCORE * BASE_SCORE * crSRnks[INDEX_1]->rank;

    } else if (crSRnks[INDEX_1]->rank == crSRnks[INDEX_2]->rank) {
        //Case: 1 + 2 + 1 + 1 
        sum = crSRnks[INDEX_0]->rank + BASE_SCORE * crSRnks[INDEX_3]->rank
                + BASE_SCORE * BASE_SCORE * crSRnks[INDEX_4]->rank
                + BASE_SCORE * BASE_SCORE * BASE_SCORE * crSRnks[INDEX_1]->rank;

    } else if (crSRnks[INDEX_2]->rank == crSRnks[INDEX_3]->rank) {
        //Case: 1 + 1 + 2 + 1 
        sum = crSRnks[INDEX_0]->rank + BASE_SCORE * crSRnks[INDEX_1]->rank
                + BASE_SCORE * BASE_SCORE * crSRnks[INDEX_4]->rank
                + BASE_SCORE * BASE_SCORE * BASE_SCORE * crSRnks[INDEX_2]->rank;

    } else {
        //Case: 1 + 1 + 1 + 2 
        sum = crSRnks[INDEX_0]->rank + BASE_SCORE * crSRnks[INDEX_1]->rank
                + BASE_SCORE * BASE_SCORE * crSRnks[INDEX_2]->rank
                + BASE_SCORE * BASE_SCORE * BASE_SCORE * crSRnks[INDEX_3]->rank;
    }

    return A_PAIR_SCORE + sum;
}

/**
 * Reference to the declaration
 * @param cards
 * @return 
 */
int PokerCardTable::calPokerScore(const vector<Card*>& cards) {
    //Sorting the current cards for checking a result
    sortCardsByRank(cards);
    sortCardsBySuit(cards);

    if (isRoyalFlush()) {
        cout << "A Royal Flush!!!\n";
        return getRoyalFlushScore();

    }

    if (isStraightFlush()) {
        cout << "A Straight Flush!!\n";
        return getStraightFlushScore();

    }

    if (isFlush()) {
        cout << "A Flush!\n";
        return getFlushScore();
    }

    if (isStraight()) {
        cout << "A Straight!\n";
        return getStraightScore();
    }

    if (isFourOfAKind()) {
        cout << "Four of the same kind!\n";
        return getFourOfAKindScore();
    }

    if (isFullHouse()) {
        cout << "Full house!\n";
        return getFullHouseScore();

    }

    if (isThreeOfAKind()) {
        cout << "Three of the same kind!\n";
        return getThreeOfAKindScore();
    }

    if (isTwoPairs()) {
        cout << "Two pairs!\n";
        return getTwoPairScore();
    }

    if (isPair()) {
        cout << "A pair!\n";
        return getAPairScore();
    }

    return CardTableHelper::LOSE;

}