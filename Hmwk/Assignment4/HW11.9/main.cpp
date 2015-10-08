/* 
 * File:   main.cpp
 * Author: Hao Huynh
 *
 * Created on October 8, 2015, 3:38 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

/**
 * Speakers’ Bureau Data Structure
 */
typedef struct SPEAKERSDATA {
    /*A speaker's name*/
    string name;

    /*The speaker's telephone number*/
    string telNum;

    /*The speaker's speaking topic*/
    string spTopic;

    /*A required fee*/
    float fee;

} SpeakersData;

/**
 * This function asks the user to enter all the data about a speaker
 * @param spkBur : A Speaker Data record
 */
void getSpeakerData(SpeakersData* spkData) {
    cout << "Please enter a speaker's name: ";
    getline(cin, spkData->name);

    cout << "Please enter the speaker's telephone number: ";
    getline(cin, spkData->telNum);

    cout << "Please enter the speaker's speaking topic: ";
    getline(cin, spkData->spTopic);

    cout << "Please enter a required fee: ";
    cin >> spkData->fee;

}

/**
 * 
 * @param spkBur : A list of all data about speakers 
 * @param nSpkers : The number of recorded speakers
 */
void displaySpeakersData(SpeakersData** spkData, const int nSpkers = 10) {

    for (int i = 0; i < nSpkers; i++) {
        cout << "------------------------------------\n";
        cout << "This is speaker number: " << i + 1 << endl;
        cout << "The speaker's name is: " << spkData[i]->name << endl;
        cout << "The telephone number is: " << spkData[i]->telNum << endl;
        cout << "The speaking topic is: " << spkData[i]->spTopic << endl;
        cout << "The required fee is: " << spkData[i]->fee << endl;
        cout << "------------------------------------\n";
    }

}

/*
 * Speakers’ Bureau
 * Write a program that keeps track of a speakers’ bureau. The program should use a
 * structure to store the following data about a speaker:
 *      Name
 *      Telephone Number
 *      Speaking Topic
 *      Fee Required
 * The program should use an array of at least 10 structures. It should let the user enter
 * data into the array, change the contents of any element, and display all the data stored
 * in the array. The program should have a menu-driven user interface.
 * Input Validation: When the data for a new speaker is entered, be sure the user enters
 * data for all the fields. No negative amounts should be entered for a speaker’s fee.
 */
int main(int argc, char** argv) {

    // The number of speakers
    const int NUM_SPEAKERS = 10;

    // The array of all data about speakers
    SpeakersData * spkDtAr[NUM_SPEAKERS];

    // A
    char uOp;
    
    for (int i = 0; i < NUM_SPEAKERS; i++) {
        cout << "Please enter the following data for the speaker number " << i + 1 << endl;
        spkDtAr[i] = new SpeakersData;
        getSpeakerData(spkDtAr[i]);
    }
    
    
    
    displaySpeakersData(spkDtAr);

    do{
        
    }while ();
    
    return 0;
}

