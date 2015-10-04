/* 
 * File:   main.cpp
 * Author: HaoHuynh
 *
 * Created on October 3, 2015, 4:56 PM
 */

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

/**
 * This function accepts a pointer to a C-string as an argument and returns the
 * average number of letters in each word
 * @param str : an input sentence.
 * @return the average number of letters in each word
 */
int calAverage(const char* str) {
    
    int sum = 0;
    
    int counter = 0;
    
    char* word;
    
    word = strtok(const_cast<char*>(str), " ");
    
    while ( word != NULL){
        sum += strlen(word);
        counter++;
        word = strtok(NULL, " ");
    }
    
    return sum/counter;
}

/**
 * Average Number of Letters
 * This program displays the average number of letters in each word.
 */
int main(int argc, char** argv) {

    const string TEST_DATA = "Four score and seven years ago";

    cout << calAverage(TEST_DATA.c_str());
    
    return 0;
}

