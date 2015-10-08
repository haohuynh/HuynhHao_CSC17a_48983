/* 
 * File:   main.cpp
 * Author: Hao Huynh
 *
 * Created on October 7, 2015, 5:24 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/**
 * Division Names 
 */
typedef struct DIVISION {
    const static int NUM_DIVISION = 4;

    const static char* NAMES[NUM_DIVISION];

    char divName[5];

} Divsion;

const char* Divsion::NAMES[] = {"East", "West", "North", "South"};

/**
 * The Corporate Sales Data
 */
typedef struct SALESDATA {
    /*Division Name (such as East, West, North, or South)*/
    Divsion div;

    /*   First-Quarter Sales */
    float fQSales;

    /*  Second-Quarter Sales */
    float sQSales;

    /*  Third-Quarter Sales */
    float tQSales;

    /*  Fourth-Quarter Sales */
    float foQSals;

    /*  Total Annual Sales */
    float totASls;

    /*  Average Quarterly Sales */
    float aveQSls;

} SalesData;

/**
 * This function shows the Corporate Sales Data of a Division on the console
 * @param salData
 */
void showSales(SalesData* salData) {

    cout << endl << "--------------------------\n";
    cout << "Division Name: " << salData->div.divName << endl;
    cout << "First-Quarter Sales: " << salData->fQSales << endl;
    cout << "Second-Quarter Sales: " << salData->sQSales << endl;
    cout << "Third-Quarter Sales: " << salData->tQSales << endl;
    cout << "Fourth-Quarter Sales: " << salData->foQSals << endl;
    cout << "Total Annual Sales: " << salData->totASls << endl;
    cout << "Average Quarterly Sales : " << salData->totASls << endl;
    cout << "--------------------------" << endl;
}

void calSales(SalesData* salData){
    
}

/*
 * Corporate Sales Data
 * This uses a structure to store the following data on a company division:
 *  Division Name (such as East, West, North, or South)
 *  First-Quarter Sales
 *  Second-Quarter Sales
 *  Third-Quarter Sales
 *  Fourth-Quarter Sales
 *  Total Annual Sales
 *  Average Quarterly Sales
 * The program uses four variables of this structure. Each variable should represent
 * one of the following corporate divisions: East, West, North, and South. The
 * user should be asked for the four quarters’ sales figures for each division. Each
 * division’s total and average sales should be calculated and stored in the appropriate
 * member of each structure variable. These figures should then be displayed on the
 * screen.
 * Input Validation: Do not accept negative numbers for any sales figures.
 */
int main(int argc, char** argv) {




    return 0;
}

