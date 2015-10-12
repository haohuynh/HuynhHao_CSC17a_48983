/* 
 * File:   PokerCardTable.h
 * Author: HaoHuynh
 *
 * Created on October 10, 2015, 10:49 AM
 */

#ifndef POKERCARDTABLE_H
#define	POKERCARDTABLE_H

#include <vector>
#include <string>
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
     * The total of cards are 52
     */
    static const int CARDS_TOTAL = 52;

    /*
     * There are thirteen ranks per suit.
     */
    static const int RANKS_PER_SUIT = 13;

    /*
     * Maximum poker cards for each player.
     */
    static const int FIVE_POKER_CARDS = 5;

    /*
     * There are 4 suits in 52 desk cards.
     */
    static const int SUIT_MAX = 4;

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

    /*
     * Vector contains all the user's current cards sorted by rank
     */
    vector<Card*> crSRnks;

    /*
     * Vector contains all the user's current cards sorted by suit
     */
    vector<Card*> crSSuits;

public:

    /**
     * The default constructor of PokerCardTable
     */
    PokerCardTable();

    /**
     * This function interacts with players to drive them through a game
     */
    bool populateConsole();

private:
    /**
     * This function create a Card by mapping the id to a Card structure through
     * the logical Card Table
     * @param id
     * @return Card
     */
    Card* populateCardBy(int id);

    /**
     * This function uses the id to check if a card has been dealt
     * @param id : the Card Table index
     * @return true/false : A card is existed or not
     */
    bool isCardExistedBy(int id);

    /**
     * This function tries to dealt a new card to the current hand without
     * duplicating any existed one 
     * @param id : the Card Table index
     * @return true/false : Insertion success or not
     */
    bool isCardInsertedBy(int id);

    /**
     * This function deals first five poker cards for the player
     */
    void dealsCards();

    /**
     *  This function sends all current hand cards to the console 
     */
    void displayPlayerCards();

    /**
     * This function generates a new card for the replacing process.
     * The new one should not be duplicated with any card in the current hand
     * @return a new Card structure
     */
    Card* dealsNewCard();

    /**
     * This function generates a new one that has not been dealt before
     * for the replacement process
     * @return a new Card structure
     */
    Card* getNewCardForReplacement();

    /**
     * This functions collects all the cards user want to replace and 
     * replaces them with new ones
     */
    void replaceCards();

    /**
     * This functions creates a list of current hand cards sorted by rank.
     */
    void sortCardsByRank();

    /**
     * This functions creates a list of current hand cards sorted by suit.
     */
    void sortCardsBySuit();

    /**
     * This functions check if there is an ACE, and all five poker cards are flush and straight
     * @return true/false
     */
    bool isRoyalFlush();

    /**
     * This functions check if all five poker card are flush and straight
     * @return true/false
     */
    bool isStraightFlush();

    /**
     * This function checks if all five poker cards have the same suit.
     * After sorting by suit, if the lowest card has the same suit as the highest one,
     * then all five poker cards will have the same suit.
     * @return true/false
     */
    bool isFlush();

    /**
     * This function checks if all five poker cards make a straight:
     * Case 1: There is an ACE and the other fours are {TEN, JACK, QUEEN, KING}
     *                                              or {TWO, THREE, FOUR, FIVE}
     * Case 2: The ranks of all cards are increasing continuously 
     * @return true/false
     */
    bool isStraight();

    /**
     * This function checks for four of the same card in a rank
     * Two cases: 4 + 1 or 1 + 4
     * @return true/false
     */
    bool isFourOfAKind();

    /**
     * This function checks for 3 of the same card in a rank
     * and 2 of the same card in another rank
     * Two cases: 3 + 2 or 2 + 3
     * @return true/false
     */
    bool isFullHouse();

    /**
     * This function checks for 3 of the same card after checking four of a kind and full house.
     * Three cases: 3 + 1 + 1 or 
     *              1 + 3 + 1 or
     *              1 + 1 + 3.    
     * @return true/false
     */
    bool isThreeOfAKind();

    /**
     * This function checks for 2 different pairs after checking four of a kind, full house, 
     * and three of a kind.
     * Three cases: 2 + 2 + 1 or
     *              2 + 1 + 2 or
     *              1 + 2 + 2.
     * @return true/false
     */
    bool isTwoPairs();

    /**
     * This function checks for two of the same card after checking four of a kind, full house,
     * three of a kind and two pairs
     * Four cases: 2 + 1 + 1 + 1 or
     *             1 + 2 + 1 + 1 or 
     *             1 + 1 + 2 + 1 or 
     *             1 + 1 + 1 + 2 or
     * @return true/false
     */
    bool isPair();

    /**
     * Check if the current hand win or lose
     * @return true/false:  win/lose
     */
    bool isPlayerWin();

    /**
     *  Reset all the current cards for a new game
     */
    void clean();

};

#endif	/* POKERCARDTABLE_H */

