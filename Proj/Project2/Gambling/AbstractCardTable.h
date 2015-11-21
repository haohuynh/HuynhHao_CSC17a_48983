/* 
 * File:   AbstractCardTable.h
 * Author: HaoHuynh
 *
 * Created on November 20, 2015, 10:03 AM
 */

#ifndef ABSTRACTCARDTABLE_H
#define	ABSTRACTCARDTABLE_H

#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include "CardTableHelper.h"
using namespace std;

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
class AbstractCardTable {
protected:

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
     * The total of cards are 52
     */
    static const int CARDS_TOTAL = 52;

    /*
     * There are thirteen ranks per suit.
     */
    static const int RANKS_PER_SUIT = 13;

    /*
     * There are 4 suits in 52 desk cards.
     */
    static const int SUIT_MAX = 4;

    /*
     * Labels for displaying a card suit.
     */
    static const string CARD_SUIT_LABELS[SUIT_MAX];

    /*
     * Labels for displaying a card rank.
     */
    static const string CARD_RANK_LABELS[RANKS_PER_SUIT];

    /*
     * Vector contains all the user's current cards
     */
    vector<Card*> crCards;


public:

    /**
     * The default constructor of AbstractCardTable
     */
    AbstractCardTable();

    /**
     * This function interacts with players to drive them through a game
     */
    virtual CardTableHelper::GAME_BOOL populateConsole() = 0;

protected:

    /**
     * This function create a Card by mapping the id to a Card structure through
     * the logical Card Table
     * @param id
     * @return Card
     */
    Card* populateCardBy(int id);

    /**
     * This function tries to dealt a new card to the current hand without
     * duplicating any existed one 
     * @param id : the Card Table index
     * @return true/false : Insertion success or not
     */
    bool isCardInsertedBy(int id);

    /**
     *  This function sends all current hand cards to the console 
     */
    void displayPlayerCards();

    /**
     * This function generates a new card for the replacing process.
     * The new one should not be duplicated with any existing card.
     * @return a new Card structure
     */
    Card* dealsNewCard();

    /**
     * This function deallocates the memories of all elements in cards and clears the cards
     * @param cards : a vector of Card Structure pointers
     */
    void deleteCards(vector<Card*>& cards);

    /**
     * This function uses the id to check if a card has been dealt
     * @param id : the Card Table index
     * @return true/false : A card is existed or not
     */
    virtual bool isCardExistedBy(int id) = 0;

    /**
     * This function deals first five poker cards for the player
     */
    virtual void dealsCards() = 0;

    /**
     * This function checks if the current hand win or lose
     * @return -1/0/1:  /drawn/lose/win/
     */
    virtual CardTableHelper::GAME_BOOL isPlayerWin() = 0;

    /**
     *  This function reset all the current cards for a new game
     */
    virtual void clean() = 0;
};

#endif	/* ABSTRACTCARDTABLE_H */

