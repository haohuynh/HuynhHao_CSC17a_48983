#include "PokerCardTable.h"
#include "PokerHelper.h"
#include <cstdlib>
#include <time.h>       
#include <iostream>

using namespace std;

/**
 * Reference to the declaration
 */
const string PokerCardTable::CARD_SUIT_LABELS[SUIT_MAX] = {"Hearts", "Diamonds", "Clubs", "Spades"};

/**
 * Reference to the declaration
 */
const string PokerCardTable::CARD_RANK_LABELS[RANKS_PER_SUIT] = {"Ace", "Two", "Three", "Four", "Five",
    "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

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
Card PokerCardTable::populateCardBy(int id) {
    Card card;
    card.id = id;
    card.suit = static_cast<CARD_SUITS> (id / RANKS_PER_SUIT);
    card.rank = static_cast<CARD_RANKS> (id % RANKS_PER_SUIT);
    return card;
}

/**
 * Reference to the declaration
 * @param index
 * @return 
 */
bool PokerCardTable::isCardExistedBy(int id) {

    int size = crCards.size();

    for (int i = 0; i < size; i++) {

        if (id == crCards[i].id) {
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
bool PokerCardTable::isCardInsertedBy(int id) {

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
void PokerCardTable::dealsCards() {

    for (int i = 0; i < FIVE_POKER_CARDS; i++) {
        while (!isCardInsertedBy(rand() % CARDS_TOTAL));
    }

}

/**
 * Reference to the declaration
 */
void PokerCardTable::displayPlayerCards() {

    cout << "The following cards are yours :\n";

    int size = crCards.size();
    for (int i = 0; i < size; i++) {
        cout << "Card " << i + 1 << ": " << CARD_SUIT_LABELS[crCards[i].suit] << "-"
                << CARD_RANK_LABELS[crCards[i].rank] << " \n";

    }

}

/**
 * Reference to the declaration
 */
Card PokerCardTable::dealsNewCard() {

    int randId;

    do {
        randId = rand() % CARDS_TOTAL;
    } while (isCardExistedBy(randId));

    return populateCardBy(randId);

}

/**
 * Reference to the declaration
 * @param index
 */
Card PokerCardTable::getNewCardForReplacement() {
    Card newCard = dealsNewCard();

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
    PokerHelper::validateValueOf(nRCards, INDEX_1, FIVE_POKER_CARDS);

    if (nRCards > 0) {

        //The on-screen index of a card needs replacing 
        int rIndex;

        //The list of on-screen indexes of cards need replacing 
        vector<int> rIndexes;

        /*
         * Create a copy of all current hand cards, because crCards will be used for 
         * containing the first five cards and new cards for the replacement process.
         */
        vector<Card> bkCrCds(crCards);

        if (nRCards < FIVE_POKER_CARDS) { //Replace any 1,2,3, or 4 cards

            cout << "What are they? Please enter the index(es) of "
                    << nRCards << " card(s) you want to replace: \n";

            //Collecting on-screen positions of cards need replacing
            for (int i = 0; i < nRCards; i++) {
                cout << "Index number " << i + 1 << ": ";
                PokerHelper::validateValueOf(rIndex, INDEX_1, FIVE_POKER_CARDS);
                rIndexes.push_back(rIndex);
            }

            //Do actual replacements on bkCrCds 
            //while use crCards to store all cards have been dealt
            for (int i = 0; i < nRCards; i++) {
                bkCrCds[rIndexes[i] - 1] = getNewCardForReplacement();
            }

        } else {//Replacing all five cards

            for (int i = 0; i < nRCards; i++) {
                bkCrCds[i] = getNewCardForReplacement();
            }

        }

        //The replacement process is done and crCards show have a new combination of only five cards
        crCards = bkCrCds;
    }

}

/**
 * Reference to the declaration
 */
void PokerCardTable::sortCardsByRank() {

    vector<Card>::iterator cardIt;

    for (int i = 0; i < FIVE_POKER_CARDS; i++) {

        for (cardIt = crSRnks.begin(); (cardIt != crSRnks.end())
                && (cardIt->rank < crCards[i].rank); cardIt++);

        crSRnks.insert(cardIt, crCards[i]);
    }
}

/**
 * Reference to the declaration
 */
void PokerCardTable::sortCardsBySuit() {

    vector<Card>::iterator cardIt;

    for (int i = 0; i < FIVE_POKER_CARDS; i++) {

        for (cardIt = crSSuits.begin(); (cardIt != crSSuits.end())
                && (cardIt->suit < crCards[i].suit); cardIt++);

        crSSuits.insert(cardIt, crCards[i]);
    }
}

/**
 * Reference to the declaration
 * @return true/false
 */
bool PokerCardTable::isFourOfAKind() {

    //Case: 4 + 1 
    if ((crSRnks[INDEX_0].rank == crSRnks[INDEX_1].rank)
            && (crSRnks[INDEX_1].rank == crSRnks[INDEX_2].rank)
            && (crSRnks[INDEX_2].rank == crSRnks[INDEX_3].rank)) {
        return true;
    }

    //Case 1 + 4
    if ((crSRnks[INDEX_1].rank == crSRnks[INDEX_2].rank)
            && (crSRnks[INDEX_2].rank == crSRnks[INDEX_3].rank)
            && (crSRnks[INDEX_3].rank == crSRnks[INDEX_4].rank)) {
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
    if ((crSRnks[INDEX_0].rank == crSRnks[INDEX_1].rank)
            && (crSRnks[INDEX_1].rank == crSRnks[INDEX_2].rank)
            && (crSRnks[INDEX_3].rank == crSRnks[INDEX_4].rank)) {
        return true;
    }

    //Case 2 + 3
    if ((crSRnks[INDEX_0].rank == crSRnks[INDEX_1].rank)
            && (crSRnks[INDEX_2].rank == crSRnks[INDEX_3].rank)
            && (crSRnks[INDEX_3].rank == crSRnks[INDEX_4].rank)) {
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
    if ((crSRnks[INDEX_0].rank == crSRnks[INDEX_1].rank)
            && (crSRnks[INDEX_1].rank == crSRnks[INDEX_2].rank)) {
        return true;
    }

    //Case 1 + 3 + 1
    if ((crSRnks[INDEX_1].rank == crSRnks[INDEX_2].rank)
            && (crSRnks[INDEX_2].rank == crSRnks[INDEX_3].rank)) {
        return true;
    }

    //Case 1 + 1 + 3
    if ((crSRnks[INDEX_2].rank == crSRnks[INDEX_3].rank)
            && (crSRnks[INDEX_3].rank == crSRnks[INDEX_4].rank)) {
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
    if ((crSRnks[INDEX_0].rank == crSRnks[INDEX_1].rank)
            && (crSRnks[INDEX_2].rank == crSRnks[INDEX_3].rank)) {
        return true;
    }

    //Case 2 + 1 + 2
    if ((crSRnks[INDEX_0].rank == crSRnks[INDEX_1].rank)
            && (crSRnks[INDEX_3].rank == crSRnks[INDEX_4].rank)) {
        return true;
    }

    //Case 1 + 2 + 2
    if ((crSRnks[INDEX_1].rank == crSRnks[INDEX_2].rank)
            && (crSRnks[INDEX_3].rank == crSRnks[INDEX_4].rank)) {
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
    if (crSRnks[INDEX_0].rank == crSRnks[INDEX_1].rank) {
        return true;
    }

    //Case: 1 + 2 + 1 + 1 
    if (crSRnks[INDEX_1].rank == crSRnks[INDEX_2].rank) {
        return true;
    }

    //Case: 1 + 1 + 2 + 1 
    if (crSRnks[INDEX_2].rank == crSRnks[INDEX_3].rank) {
        return true;
    }

    //Case: 1 + 1 + 1 + 2 
    if (crSRnks[INDEX_3].rank == crSRnks[INDEX_4].rank) {
        return true;
    }

    return false;
}
