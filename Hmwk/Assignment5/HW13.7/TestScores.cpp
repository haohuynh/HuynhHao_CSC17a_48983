/* 
 * File:   TestScores.cpp
 * Author: HaoHuynh
 * 
 * Created on November 17, 2015, 12:27 PM
 */

#include "TestScores.h"

/**
 * Reference to the function declaration
 */
TestScores::TestScores() {
    fTstScr = sTstScr = tTstScr = 0;
}

/**
 * Reference to the function declaration
 * @param fTstScr
 * @param sTstScr
 * @param tTstScr
 */
TestScores::TestScores(int fTstScr, int sTstScr, int tTstScr) {

    this->fTstScr = fTstScr;
    this->sTstScr = sTstScr;
    this->tTstScr = tTstScr;
}

/**
 * Reference to the function declaration
 * @return 
 */
float TestScores::getAverageScore() {
    return ((fTstScr + sTstScr + tTstScr) / static_cast<float> (3));
}

/**
 * Reference to the function declaration
 * @return 
 */
int TestScores::getFTstScr() const{
    return fTstScr;
}

/**
 * Reference to the function declaration
 * @return 
 */
int TestScores::getSTstScr() const{
    return sTstScr;
}

/**
 * Reference to the function declaration
 * @return 
 */
int TestScores::getTTstScr() const{
    return tTstScr;
}

/**
 * Reference to the function declaration
 * @param fTstScr
 */
void TestScores::setFTstScr(int fTstScr){
    this->fTstScr = fTstScr;
}

/**
 * Reference to the function declaration
 * @param sTstScr
 */
void TestScores::setSTstScr(int sTstScr){
    this->sTstScr = sTstScr;
}
/**
 * Reference to the function declaration
 * @param tTstScr
 */
void TestScores::setTTstScr(int tTstScr){
    this->tTstScr = tTstScr;
}