/* 
 * File:   main.cpp
 * Author: Hao Huynh
 *
 * Created on October 1, 2015, 12:51 PM
 */

#include <map>  // Map Library
#include <vector> // Vector Library
#include <algorithm> //Algorithm Library
#include <iostream>
#include <string.h> // Input/Output Stream Library

using namespace std;

/*The helper is used for comparing frequencies of a vector of pairs<value, frequency>
 *The frequencies are sorted in a decreasing order
 */
bool cmpValue(const pair<int, int> &v1, const pair<int, int> &v2) {
    return v1.second > v2.second;
}

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
        sum += a[i];
    }

    // Return the mean
    return sum / static_cast<float> (n);

}

/**
 * 
 * @param a : an array of integer values 
 * @param n : the size of a
 * @return the median of the array a
 */
float findMedian(int *a, int n) {

    //Making a copy of the array a for manipulating data
    vector<int> vectorA(a, a + n);

    //Sorting the vector in ascending order
    sort(vectorA.begin(), vectorA.end());

    if ((n % 2) != 0) { //If n is an odd number
        // then return the middle element 
        return vectorA[n / 2];

    } else {// If n is an even number
        // then return the average of the two middle numbers
        return ( vectorA[n / 2] + vectorA[(n / 2) - 1]) / static_cast<float> (2);
    }
}

/**
 * 
 * @param a : an array of integer values 
 * @param n : the size of a
 * @param m : the size of the return array
 * @return the array containing the number of modes, the max frequency, and all the mode values of a
 */
int* findMode(int* a, int n) {

    // The input array a should have more than a element
    if (n <= 1) {
        return NULL;
    }

    /*This map containing pairs of values (in the array a) and their frequencies*/
    map<int, int> afreq;

    /*An iterator of the afreq map */
    map<int, int>::iterator afreqi;

    /*This vector of pairs is parallel to the map afreq*/
    vector< pair<int, int> > afreqv;

    /*An iterator of the afreqv vector */
    vector< pair<int, int> > ::iterator afreqvi;

    //Finding the frequency of each value in the array a
    for (int i = 0; i < n; i++) {

        afreqi = afreq.find(a[i]); // Check if a value has already existed in the map

        // Increasing the frequency of an existing value
        if (afreqi != afreq.end()) {
            afreqi->second++;

        } else {// Start the frequency of a new value with 1
            afreq.insert(pair<int, int> (a[i], 1));
        }

    }

    // Binding all map entries into a vector of pairs (values, frequencies))
    copy(afreq.begin(), afreq.end(), back_inserter(afreqv));

    /*
     * Take advantage of the build-in sort algorithm for vectors
     * Sort the vector of pairs<value, frequency> by a decreasing order of frequencies
     */
    sort(afreqv.begin(), afreqv.end(), cmpValue);

    // If the highest frequency of a value in the array a is equal to 1, then that array has no mode
    if (afreqv.begin()->second == 1) {
        return NULL;
    }

    //This vector contains all the values having the same highest frequency in the array a
    vector<int> result;

    //Finding values that have the same highest frequency
    for (afreqvi = afreqv.begin(); afreqvi != afreqv.end(); afreqvi++) {
        if (afreqvi->second == afreqv.begin()->second) {
            result.push_back(afreqvi->first);
        } else {
            break;
        }
    }

    //The size of a result array
    int rSize = result.size() + 2;

    //The formated result array in form of {number of modes, max frequency, mode1, mode2, .... , moden}
    int* fresult = new int[rSize];
    fresult[0] = result.size(); // The number of modes
    fresult[1] = afreqv.begin()->second; // The max frequency

    //Copy {mode1, mode2, ..., moden} from the vector result to the rest of the memory belonging to the pointer fresult
    memcpy((fresult + 2), &result[0], result.size() * sizeof (int));

    //Returning the formated pointer
    return fresult;
}

/*
 * This program is used for finding the mean, median, and mode of a set of data
 */
int main(int argc, char** argv) {

    // The size of an array
    const int SIZE = 24;

    //Test data
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3};

    // The mode array 
    int* result;

    cout << "The mean value is " << findMean(a, SIZE) << endl;

    cout << "The median value is " << findMedian(a, SIZE) << endl;

    result = findMode(a, SIZE);

    if (result == NULL) {
        cout << "There is no mode of the input array !";

    } else {

        cout << "The number of modes is: " << result[0] << endl;

        cout << "The max frequency is: " << result[1] << endl;

        cout << "The mode array: " << endl;

        for (int j = 2; j < result[0] + 2; j++) {
            cout << result[j] << " ";
        }
    }

    return 0;
}