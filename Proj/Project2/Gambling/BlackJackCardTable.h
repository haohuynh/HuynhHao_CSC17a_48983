/* 
 * File:   BlackJackCardTable.h
 * Author: HaoHuynh
 *
 * Created on November 20, 2015, 10:05 AM
 */

#ifndef BLACKJACKCARDTABLE_H
#define	BLACKJACKCARDTABLE_H

#include "AbstractCardTable.h"

class BlackJackCardTable : public AbstractCardTable {
private:

    /*
     * Initiated BlackJack cards for each player.
     */
    static const int INIT_BJ_CARDS = 2;

    /*
     * Limit the number of BlackJack cards a player can have.
     */
    static const int BJ_PLAYER_CARD_LIMIT = 12;

    /*
     * BlackJack player request to hit
     */
    static const char BJ_PLAYER_HIT = 'h';

    /*
     * The highest BlackJack winning score
     */
    static const int BJ_UPPER_WINNER_LIMIT = 21;

    /*
     * The lowest BlackJack winning score
     */
    static const int BJ_LOWER_WINNER_LIMIT = 17;

    /*
     * BlackJack bust means the total score is over 21 and who has this score will be the loser
     */
    static const int BJ_BUST = 0;

    /*
     * The BlackJack hard value of a Ace
     */
    static const int BJ_HARD_ACE = 1;

    /*
     * The BlackJack soft value of a Ace
     */
    static const int BJ_SOFT_ACE = 11;

    /*
     * The BlackJack value of Jack, Queen, and King
     */
    static const int BJ_JACK_QUEEN_KING = 10;

    /*
     * Vector contains all the current dealer cards
     */
    vector<Card*> crDCrds;

    /*
     * Used for testing the soft-17 case in BlackJack 
     */
    bool isSAce;


public:
    /**
     * The default constructor of BlackJackCardTable
     */
    BlackJackCardTable();

    /**
     * The default destructor of BlackJackCardTable
     */
    ~BlackJackCardTable();

    /**
     * This function interacts with players to drive them through a game
     */
    virtual CardTableHelper::GAME_BOOL populateConsole();

private:

    /**
     * This function uses the id to check if a card has been dealt
     * @param id : the Card Table index
     * @return true/false : A card is existed or not
     */
    virtual bool isCardExistedBy(int id);

    /**
     * This function deals first four BlackJack cards for the player and the dealer, alternatively 
     */
    virtual void dealsCards();

    /**
     * This function checks if the current hand win or lose
     * @return  -1/0/1:  /drawn/lose/win/
     */
    virtual CardTableHelper::GAME_BOOL isPlayerWin();

    /**
     *  This function reset all the current cards for a new game
     */
    virtual void clean();

    /**
     * This function calculates the total BlackJack score of the current hand or the dealer
     * @param cards
     * @return BJ score
     */
    int calculateScore(vector<Card*> cards);

    /**
     * This function sends all current dealer cards to console 
     * @param isPF : is the player done his or her turn.
     */
    void displayDealerCards(bool isPD = false);


    /**
     * Process player's request for hitting or staying.
     * Calculate user's BJ score after the player's turn. 
     */
    void processPlayerTurn();

    /**
     * Try getting the BJ score of dealer between hard 17 and 21.
     * Calculate the actual BJ score. 
     */
    void processDealerTurn();


};

#endif	/* BLACKJACKCARDTABLE_H */

