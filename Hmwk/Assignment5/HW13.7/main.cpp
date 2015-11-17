/* 
 * File:   main.cpp
 * Author: HaoHuynh
 *
 * Created on November 17, 2015, 12:27 PM
 */

#include <cstdlib>
#include <iostream>
#include "TestScores.h"

using namespace std;

/*
 * The TestScores main thread
 */
int main(int argc, char** argv) {

    TestScores* tstScr = new TestScores();
    
    int tmp;
    
    cout << "Please input the first test score:";
    cin >> tmp;
    tstScr->setFTstScr(tmp);
           
    cout << "Please input the second test score:";
    cin >> tmp;
    tstScr->setSTstScr(tmp);
    
    cout << "Please input the third test score:";
    cin >> tmp;
    tstScr->setTTstScr(tmp);
    
    cout << "The average value is: " << tstScr->getAverageScore();
        
    return 0;
}

