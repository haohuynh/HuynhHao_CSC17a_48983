/* 
 * File:   TestScores.h
 * Author: HaoHuynh
 *
 * Created on November 17, 2015, 12:27 PM
 */

#ifndef TESTSCORES_H
#define	TESTSCORES_H

class TestScores {
private:

    /*
     * The first test score
     */
    int fTstScr;

    /*
     * The second test score
     */
    int sTstScr;

    /*
     * The third test score
     */
    int tTstScr;

public:

    /**
     * The default constructor
     */
    TestScores();

    /**
     * The constructor initializes the three test scores 
     */
    TestScores(int fTstScr, int sTstScr, int tTstScr);

    /**
     * This function calculates the average value of those three test scores
     * @return the average value 
     */
    float getAverageScore();
    
    /**
     * The first test score getter
     * @return 
     */
    int getFTstScr() const;
    
    /**
     * The second test score getter
     * @return 
     */
    int getSTstScr() const;
    
    /**
     * The third test score getter
     * @return 
     */
    int getTTstScr() const;
    
    /**
     * The first test score setter
     * @param fTstScr
     */
    void setFTstScr(int fTstScr);
    
    /**
     * The second test score setter
     * @param sTstScr
     */
    void setSTstScr(int sTstScr);
    
    /**
     * The third test score setter
     * @param tTstScr
     */
    void setTTstScr(int tTstScr);

};

#endif	/* TESTSCORES_H */

