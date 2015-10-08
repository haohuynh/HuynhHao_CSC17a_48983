/* 
 * File:   main.cpp
 * Author: Hao Huynh
 *
 * Created on October 8, 2015, 11:18 AM
 */

#include <cstdlib>
#include <iostream>

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

    if ((temp < MIN_FAH_DEGREE) || (temp > <MAX_FAH_DEGREE)) {
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

/**
 * This function calculates and displays the average monthly rainfall and 
 * the total rainfall for the year.
 * @param weaDats : The weather data for an entire year 
 * @param size : Months in a year
 */
void calRainStat(WeatherData** weaDats, const char** months, int size = 12) {
    //The total rain fall in a year
    float yTotRain = 0;

    //The maximum temperature in a year
    float yMaxTemp;

    //The month that has the yMaxTemp
    int mMaxTemp;

    //The minimum temperature in a year
    float yMinTemp;

    //The month that has the yMinTemp
    int mMinTemp;

    //The total of monthly average temperatures
    float yTotATm = 0;

    yMaxTemp = weaDats[0]->hTemp;
    mMaxTemp = 0;

    yMinTemp = weaDats[0]->lTemp;
    mMinTemp = 0;

    for (int i = 0; i < size; i++) {
        yTotRain += weaDats[i]->totRain;

        //Using map ?? to find the min and max temperature months

        yTotATm += weaDats[i]->aveTemp;
    }

    cout << "The total rainfall for the year is: " << yTotRain << endl;
    cout << "The average monthly rainfall for the year is: " << (yTotRain / size) << endl;
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

    //The 12 structures that holds weather data for an entire year
    WeatherData * weaDats[MONTHS_IN_YEAR];

    //The names of months in a year
    char* months[MONTHS_IN_YEAR] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    for (int i = 0; i < MONTHS_IN_YEAR; i++) {
        cout << "Please enter the weather data of " << months[i] << endl;
        weaDats[i] = new WeatherData;
        getWeatherData(weaDats[i]);
    }

    calRainStat(weaDats);



    return 0;
}

