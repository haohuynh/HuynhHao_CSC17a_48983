/* 
 * File:   main.cpp
 * Author: HaoHuynh
 *
 * Created on October 3, 2015, 12:12 PM
 */

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <cstring>

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
 * QUARTERS
 */
typedef struct QUARTER {
    const static int NUM_QUARTER = 4;

    const static int QUATERS[NUM_QUARTER];

    int quater;

} Quarter;

const int Quarter::QUATERS[] = {1, 2, 3, 4};

/**
 * 
 * The Sales Data Structure is used to store the following data on a company division:
 * Division Name (such as East, West, North, or South)
 * Quarter (1, 2, 3, or 4)
 * Quarterly Sales
 */
typedef struct SALEDATA {
    Divsion div;

    Quarter quar;

    float quaSale;

} SaleData;

/*
 * Corporate Sales Data Output
 * This program uses The Sales Data Structure to ask users for the four quarters’ sales figures 
 * for the East, West, North, and South divisions. The data for each quarter for each division 
 * will be written to a file.
 * Input Validation: Do not accept negative numbers for any sales figures.
 */
int main(int argc, char** argv) {

    const string SALE_FILE_NAME = "Sales.dat";

    fstream saleFile(SALE_FILE_NAME.c_str(), ios::out | ios::binary);

    SaleData curSDat;

    if (saleFile) {

        for (int i = 0; i < Divsion::NUM_DIVISION; i++) {

            strcpy(curSDat.div.divName, Divsion::NAMES[i]);

            for (int j = 0; j < Quarter::NUM_QUARTER; j++) {

                curSDat.quar.quater = Quarter::QUATERS[j];

                cout << "Please enter the quarterly sales for division "
                        << curSDat.div.divName
                        << " in quarter " << curSDat.quar.quater << ": ";
                cin >> curSDat.quaSale;

                if (curSDat.quaSale < 0) {
                    curSDat.quaSale = 0;
                }

                saleFile.write(reinterpret_cast<char*> (&curSDat), sizeof (curSDat));

            }
        }

        saleFile.close();
    } else {
        cerr << "File I/O problem !!!";
    }

    /*Testing*/
    fstream tSaFile(SALE_FILE_NAME.c_str(), ios::in | ios::binary);

    SaleData tSalDat;

    if (tSaFile) {

        while (tSaFile.read(reinterpret_cast<char*> (&tSalDat), sizeof (tSalDat))) {
            cout << tSalDat.div.divName << " "
                    << tSalDat.quar.quater << " "
                    << tSalDat.quaSale << endl;
        }

        tSaFile.close();
    }

    return 0;
}

