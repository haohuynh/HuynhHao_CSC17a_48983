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

    char* divName;

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
    cout << "Average Quarterly Sales : " << salData->aveQSls << endl;
    cout << "--------------------------" << endl;
}

/**
 * This function calculated the total annual and averages quarterly sales
 * @param salData
 */
void calSales(SalesData* salData) {

    salData->totASls = salData->fQSales + salData->sQSales
            + salData->tQSales + salData->foQSals;

    salData->aveQSls = salData->totASls / 4;

}

/**
 * This Input Validation function does not accept negative numbers 
 * for any sales figures. In case of the error, it reassigns sales to zero
 * @param sales
 */
void validateSales(float& sales) {
    if (sales < 0) {
        sales = 0;
    }
}

/**
 * This function asks for the four quarters’ sales figures for each division
 * @param salData
 */
void getQSales(SalesData* salData) {

    cout << "This is division: " << salData->div.divName << endl;

    cout << "Please enter the First-Quarter Sales: ";
    cin >> salData->fQSales;
    validateSales(salData->fQSales);

    cout << "Please enter the Second-Quarter Sales: ";
    cin >> salData->sQSales;
    validateSales(salData->sQSales);

    cout << "Please enter the Third-Quarter Sales: ";
    cin >> salData->tQSales;
    validateSales(salData->tQSales);

    cout << "Please enter the Fourth-Quarter Sales: ";
    cin >> salData->foQSals;
    validateSales(salData->foQSals);
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

    SalesData * salDats[Divsion::NUM_DIVISION];

    for (int i = 0; i < Divsion::NUM_DIVISION; i++) {
        salDats[i] = new SalesData;
        salDats[i]->div.divName = const_cast<char*> (Divsion::NAMES[i]);
        getQSales(salDats[i]);
        calSales(salDats[i]);
    }

    for (int i = 0; i < Divsion::NUM_DIVISION; i++) {
        showSales(salDats[i]);
    }

    return 0;
}

