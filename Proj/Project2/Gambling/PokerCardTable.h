/* 
 * File:   PokerCardTable.h
 * Author: HaoHuynh
 *
 * Created on October 10, 2015, 10:49 AM
 */

#ifndef POKERCARDTABLE_H
#define	POKERCARDTABLE_H

#include <set>
#include "AbstractCardTable.h"
#include "CardTableHelper.h"
using namespace std;

/*
 * This class manages the table of a Poker Game
 */
class PokerCardTable : public AbstractCardTable {
private:

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
     * The default destructor of PokerCardTable
     */
    ~PokerCardTable();

    /**
     * This function interacts with players to drive them through a game
     */
    virtual short populateConsole();

private:
    
    /**
     * This function uses the id to check if a card has been dealt
     * @param id : the Card Table index
     * @return true/false : A card is existed or not
     */
    virtual bool isCardExistedBy(int id);

    /**
     * This function deals first five poker cards for the player
     */
    virtual void dealsCards();
    
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
     * This function checks if the current hand win or lose
     * @return  1/0/-1:  win/lose/drawn
     */
    virtual short isPlayerWin();

    /**
     * This function deallocates the memories of a set of elements in cards and clears the cards
     * @param cards : a vector of Card Structure pointers
     * @param poss : a set of positions in cards
     */
    void deleteCardsBy(vector<Card*>& cards, const set<int>& poss);
   
    /**
     *  This function reset all the current cards for a new game
     */
    virtual void clean();

};

#endif	/* POKERCARDTABLE_H */

