/* 
 * File:   PokerCardTable.h
 * Author: HaoHuynh
 *
 * Created on October 10, 2015, 10:49 AM
 */

#ifndef POKERCARDTABLE_H
#define	POKERCARDTABLE_H

#include <vector>
using namespace std;

/*
 * There are thirteen ranks per suit: from Ace to King.
 */
enum CARD_RANKS {
    ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING
};

/*
 * There are four suits in fifty two desk cards.  
 */
enum CARD_SUITS {
    HEARTS, DIAMONDS, CLUBS, SPADES
};

/*
 * A card is defined by a combination of rank and suit.
 * The id is the index of a card in fifty two desk cards
 */
typedef struct CARD {
    int id;
    CARD_SUITS suit;
    CARD_RANKS rank;

} Card;

/*              
 * This class is used for managing user's cards base on the below logical mapping table
 * 
 *              0   1   2   3   4   5   6   7   8   9   10   11    12
 * Suits/Ranks  Ace 2   3   4   5   6   7   8   9   10  Jack Queen King                         
 * 0 Hearts     0   1   2   3   4   5   6   7   8   9   10   11    12                      
 * 1 Diamonds   13  14  15  16  17  18  19  20  21  22  23   24    25                                                         
 * 2 Clubs      26  27  28  29  30  31  32  33  34  35  36   37    38                                         
 * 3 Spades     39  40  41  42  43  44  45  46  47  48  49   50    51                                     
 */
class PokerCardTable {
private:

    /*
     * There are thirteen ranks per suit.
     */
    const int RANKS_PER_SUIT = 13;

    /*
     * Maximum poker cards for each player.
     */
    static const int FIVE_POKER_CARDS = 5;

    /*
     * The first poker card index
     */
    static const int INDEX_0 = 0;

    /*
     * The second poker card index
     */
    static const int INDEX_1 = 1;

    /*
     * The third poker card index
     */
    static const int INDEX_2 = 2;

    /*
     * The fourth poker card index
     */
    static const int INDEX_3 = 3;

    /*
     * The fifth poker card index
     */
    static const int INDEX_4 = 4;

    /*
     * Vector contains all the user's current cards
     */
    vector<Card> crCards;

    /*
     * Vector contains all the user's current cards sorted by rank
     */
    vector<Card> crSRnks;

    /*
     * Vector contains all the user's current cards sorted by suit
     */
    vector<Card> crSSuits;

public:

    /**
     * The default constructor of PokerCardTable
     */
    PokerCardTable();

private:
    /**
     * This function create a Card by mapping the index to a Card structure through
     * the logical Card Table
     * @param index
     * @return Card
     */
    Card populateCardBy(int index);

    /**
     * This function uses the index to check if a card has been dealt
     * @param index : the Card Table index
     * @return true/false
     */
    bool isCardExistedBy(int index);

    /**
     * This function tries to dealt a new card to the current hand without
     * duplicating any existed one 
     * @param index : the Card Table index
     * @return true/false
     */
    bool insertCardBy(int index);


};


#endif	/* POKERCARDTABLE_H */

