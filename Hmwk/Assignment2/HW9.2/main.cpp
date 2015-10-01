/* 
 * File:   main.cpp
 * Author: Hao Huynh
 *
 * Created on October 1, 2015, 2:14 PM
 */

#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

/**
 * 
 * @param a : an array of integer values 
 * @param n : the size of a
 * @return the mean of the array a
 */
float findMean(int *a, int n) {

    int sum = 0;

    //Find the sum of all values of the array
    for (int i = 0; i < n; i++) {
        sum += *(a + i);
    }

    // Return the mean
    return sum / static_cast<float> (n);

}

/*
 *This program dynamically allocates an array large enough to hold a user defined
 *number of test scores. Once all the scores are entered, the array will be
 *passed to a function that sorts them in ascending order. Another function will be
 *called that calculates the average score. The program will display the sorted list of
 *scores and averages with appropriate headings. Use pointer notation rather than array
 *notation whenever possible.
 *Input Validation: Do not accept negative numbers for test scores.
 */
int main(int argc, char** argv) {

    /*The total test score*/
    int n;

    /*The dynamic array of all test scores*/
    int *testScore;

    cout << "Please enter the number of test score: ";
    cin >> n;

    if (n < 1) {
        n = 2;
        cout << "The total was automatically resize to " << n << endl;
    }

    testScore = new int[n];

    cout << "Please enter the test score: \n";
    for (int i = 0; i < n; i++) {
        cout << "Test score [" << i + 1 << "]: ";
        cin >> *(testScore + i);

        if (*(testScore + i) < 0) {
            *(testScore + i) = 0;
            cout << "The test score was automatically resize to 0" << endl;
        }

    }

    //Sorting test scores in ascending order
    sort(testScore, testScore + n);
    
    //Display the sorted array 
    cout << "The sorted list of scores: \n";
    for (int i = 0; i < n; i++) {
        cout << *(testScore + i) << " ";
    }
    
    //Display the average
    cout << "\nThe average score is: " << findMean(testScore,n);
    
    return 0;
}

