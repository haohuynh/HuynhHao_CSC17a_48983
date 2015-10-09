/* 
 * File:   main.cpp
 * Author: Hao Huynh
 *
 * Created on October 8, 2015, 11:18 AM
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * The Weather Data Structure of a Month
 */
typedef struct WEATHERDATA {
    /*The total rain fall in a month*/
    float totRain;

    /*The highest temperature in a month*/
    float hTemp;

    /*The lowest temperature in a month*/
    float lTemp;

    /*The average temperature in a month*/
    float aveTemp;

} WeatherData;

/**
 * This input validation function only accepts temperatures within the range between –100 and +140
 * degrees Fahrenheit. In case of an error happens, it reassigns the temp to zero.
 * @param temp
 */
void validateTemp(float& temp) {
    //The minimum of a degree in Fahrenheit
    static const int MIN_FAH_DEGREE = -100;

    //The maximum of a degree in Fahrenheit
    static const int MAX_FAH_DEGREE = 140;

    if ((temp < MIN_FAH_DEGREE) || (temp > MAX_FAH_DEGREE)) {
        temp = 0;
    }

}

/**
 * This function asks the user to enter the rain fall and temperature data for each month
 * @param weaData : weather data of a month
 */
void getWeatherData(WeatherData* weaData) {
    cout << "Please enter the total rain fall: ";
    cin >> weaData->totRain;

    cout << "Please enter the highest temperature: ";
    cin >> weaData->hTemp;
    validateTemp(weaData->hTemp);

    cout << "Please enter the lowest temperature: ";
    cin >> weaData->lTemp;
    validateTemp(weaData->lTemp);

    //Calculating the average temperature in a month
    weaData->aveTemp = (weaData->hTemp + weaData->lTemp) / 2;

}

/*The helper is used for comparing temperatures of a vector of pairs<month, high temperature>
 *The temperature are sorted in a descending order
 */
bool cmpHTemp(const pair<int, int> &v1, const pair<int, int> &v2) {
    return v1.second > v2.second;
}

/*The helper is used for comparing temperatures of a vector of pairs<month, low temperature>
 *The temperature are sorted in a ascending order
 */
bool cmpLTemp(const pair<int, int> &v1, const pair<int, int> &v2) {
    return v1.second < v2.second;
}

/**
 * This function show a set of months on the console by their names
 * @param months : A list of months
 * @param mNames : The names of months in a year
 */
void showMonths(vector<int> months, const char* mNames[]) {

    for (int i = 0; i < months.size(); i++) {
        cout << mNames[months[i]] << " ";
    }
    cout << endl;
}

/**
 * This function calculates and displays: 
 *  the average monthly rainfall
 *  the total rainfall for the year
 *  
 * @param weaDats: The weather data for an entire year 
 * @param mNames : The names of months in a year
 * @param nMonths: The number of months in a year
 */
void calWeatherStats(WeatherData** weaDats, const char* mNames[], int nMonths = 12) {
    //The total rain fall in a year
    float yTotRain = 0;

    //The highest temperature in a year
    float yMaxTmp;

    //The lowest temperature in a year
    float yMinTmp;

    //The sorted (by temperature descending order) vector of pairs of months and their high temperatures
    vector< pair<int, float> > sorHTmp;

    //The sorted (by temperature ascending order) vector of pairs of months and their low temperatures
    vector< pair<int, float> > sorLTmp;

    //The iterator is used for traveling sorHTmp and sorLTmp
    vector< pair<int, float> > ::iterator sTmpIt;

    //List of the months having the highest temperature in a year
    vector<int> hTMons;

    //List of the months having the lowest temperature in a year
    vector<int> lTMons;

    //The total of monthly average temperatures
    float yTotATm = 0;

    for (int i = 0; i < nMonths; i++) {
        //Accumulating the total rain
        yTotRain += weaDats[i]->totRain;

        //Initializing sorHTmp and sorLTmp
        sorHTmp.push_back(pair<int, float>(i, weaDats[i]->hTemp));
        sorLTmp.push_back(pair<int, float>(i, weaDats[i]->lTemp));

        //Accumulating the average temperatures 
        yTotATm += weaDats[i]->aveTemp;
    }

    //Sort all high temperatures in a year by descending order
    sort(sorHTmp.begin(), sorHTmp.end(), cmpHTemp);

    //Sort all low temperatures in a year by ascending order
    sort(sorLTmp.begin(), sorLTmp.end(), cmpLTemp);

    yMaxTmp = sorHTmp.begin()->second;
    yMinTmp = sorLTmp.begin()->second;

    //Collecting months that have the highest temperature
    for (sTmpIt = sorHTmp.begin(); sTmpIt != sorHTmp.end(); sTmpIt++) {
        if (yMaxTmp == sTmpIt->second) {
            hTMons.push_back(sTmpIt->first);
        } else {
            break;
        }
    }

    //Collecting months that have the lowest temperature
    for (sTmpIt = sorLTmp.begin(); sTmpIt != sorLTmp.end(); sTmpIt++) {
        if (yMinTmp == sTmpIt->second) {
            lTMons.push_back(sTmpIt->first);
        } else {
            break;
        }
    }

    cout << "Weather Statistics\n";
    cout << "The average monthly rainfall is: " << (yTotRain / nMonths) << endl;
    cout << "The total rainfall for the year is: " << yTotRain << endl;
    cout << "The month(s) that has(have) the highest valid temperature (" << yMaxTmp << " F) is(are):\n";
    showMonths(hTMons, mNames);
    cout << "The month(s) that has(have) the lowest valid temperature (" << yMinTmp << " F) is(are):\n";
    showMonths(lTMons, mNames);
    cout << "The average of all the monthly average temperatures is: " << (yTotATm / nMonths) << endl;
}

/*
 * Weather Statistics
 * Write a program that uses a structure to store the following weather data for a particular
 * month:
 *      Total Rainfall
 *      High Temperature
 *      Low Temperature
 *      Average Temperature
 * This program has an array of 12 structures to hold weather data for an entire year. 
 * When the program runs, it asks the user to enter data for each month. 
 * (The average temperature is calculated.) 
 * Once the data are entered for all the months, the program should calculate and display 
 *  the average monthly rainfall, 
 *  the total rainfall for the year, 
 *  the highest and lowest temperatures for the year (and the months they occurred in), 
 *  and the average of all the monthly average temperatures.
 * Input Validation: Only accept temperatures within the range between –100 and +140
 * degrees Fahrenheit.
 */
int main(int argc, char** argv) {

    //The total months in a year
    const int MONTHS_IN_YEAR = 12;

    //The names of months in a year
    const char* months[MONTHS_IN_YEAR] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    //The 12 structures that holds weather data for an entire year
    WeatherData * weaDats[MONTHS_IN_YEAR];

    for (int i = 0; i < MONTHS_IN_YEAR; i++) {
        cout << "\nPlease enter the weather data of " << months[i] << endl;
        weaDats[i] = new WeatherData;
        getWeatherData(weaDats[i]);
    }

    calWeatherStats(weaDats, months);

    return 0;
}

