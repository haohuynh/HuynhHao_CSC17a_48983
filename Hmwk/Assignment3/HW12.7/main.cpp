/* 
 * File:   main.cpp
 * Author: HaoHuynh
 *
 * Created on October 3, 2015, 4:03 PM
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**
 * This function changes all the letters to lowercase except the first letter of each sentence
 * ,which should be made uppercase. 
 * @param str
 * @return the standard sentence
 */
string converseCase(string str) {

    int i = 0;

    //Making upper case for the first letter in a sentence
    while ((i < str.length()) && !isalpha(str[i])){
        i++;
    }
    str[i] = toupper(str[i]);

    //Making lower case for the rest of that sentence
    for (i = i + 1; i < str.length(); i++) {
        str[i] = tolower(str[i]);
    }

    return str;
}

/*
 * Sentence Filter
 * This program asks the user for two file names. The first file will be opened for
 * input and the second file will be opened for output. (It will be assumed that the first file
 * contains sentences that end with a period.) The program will read the contents of the first
 * file and change all the letters to lowercase except the first letter of each sentence, which
 * should be made uppercase. The revised contents should be stored in the second file.
 */
int main(int argc, char** argv) {

    /*The delimiter of each sentence*/
    const char DELIMITER = '.';

    /*The delimiter of each sentence*/
    const string SDELIMITER = ".";

    /*The Input File Name*/
    string iFName;

    /*The Output File Name*/
    string oFName;

    /*The Input File Object*/
    fstream iFile;

    /*The Output File Object*/
    fstream oFile;

    /*The sentence needs to be standardized*/
    string cSentence;

    cout << "Please enter the name of a file contains sentences: ";
    getline(cin, iFName);

    cout << "Please enter the name of an outputted file: ";
    getline(cin, oFName);

    iFile.open(iFName.c_str(), ios::in);
    oFile.open(oFName.c_str(), ios::out);

    if (iFile && oFile) {

        while (getline(iFile, cSentence, DELIMITER)) {
            cSentence.append(SDELIMITER);
            oFile << converseCase(cSentence);
        }

        iFile.close();
        oFile.close();

    } else {
        cerr << "File IO issues !";
    }

    return 0;
}

