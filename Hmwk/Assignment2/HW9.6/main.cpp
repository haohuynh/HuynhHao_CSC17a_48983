/* 
 * File:   main.cpp
 * Author: Hao Huynh
 *
 * Created on October 1, 2015, 4:05 PM
 */

// This program shows the donations made to the United Cause
// by the employees of CK Graphics, Inc. It displays
// the donations in order from lowest to highest
// and in the original order they were received.
#include <iostream>
using namespace std;

// Function prototypes
void arrSelectSort(int *[], int);
void showArray(const int [], int);
void showArrPtr(int *[], int);

/*
 * Case Study Modification #1
 * Modify Program 9-19(the United Cause case study program) so it can be used with
 * any set of donations. The program should dynamically allocate the donations array
 * and ask the user to input its values. 
 */
int main(int argc, char** argv) {

    int n; // Number of donations

    // An array containing the donation amounts.
    int *donations;

    // An array of pointers to int
    int **arrPtr;
    
    cout << "Please enter the number of donations: ";
    cin >> n;

    if (n < 1) {
        n = 2;
        cout << "The total was automatically resize to " << n << endl;
    }
    
    donations = new int[n];
    arrPtr = new int*[n];

    cout << "Please enter the donation: \n";
    for (int i = 0; i < n; i++) {
        cout << "Donation #" << i + 1 << ": ";
        ;
        cin >> *(donations + i);

        if (*(donations + i) < 0) {
            *(donations + i) = 0;
            cout << "The donation was automatically resize to 0" << endl;
        }

    }

    // Each element of arrPtr is a pointer to int. Make each
    // element point to an element in the donations array.
    for (int count = 0; count < n; count++)
        arrPtr[count] = &donations[count];

    // Sort the elements of the array of pointers.
    arrSelectSort(arrPtr, n);

    // Display the donations using the array of pointers. This
    // will display them in sorted order.
    cout << "The donations, sorted in ascending order are: \n";
    showArrPtr(arrPtr, n);

    // Display the donations in their original order.
    cout << "The donations, in their original order are: \n";
    showArray(donations, n);
    return 0;

}

//****************************************************************
// Definition of function arrSelectSort. *
// This function performs an ascending order selection sort on *
// arr, which is an array of pointers. Each element of array *
// points to an element of a second array. After the sort, *
// arr will point to the elements of the second array in *
// ascending order. *
//****************************************************************

void arrSelectSort(int *arr[], int size) {
    int startScan, minIndex;
    int *minElem;

    for (startScan = 0; startScan < (size - 1); startScan++) {
        minIndex = startScan;
        minElem = arr[startScan];
        for (int index = startScan + 1; index < size; index++) {
            if (*(arr[index]) < *minElem) {
                minElem = arr[index];
                minIndex = index;
            }
        }
        arr[minIndex] = arr[startScan];
        arr[startScan] = minElem;
    }
}

//***********************************************************
// Definition of function showArray. *
// This function displays the contents of arr. size is the *
// number of elements. *
//***********************************************************

void showArray(const int arr[], int size) {
    for (int count = 0; count < size; count++)
        cout << arr[count] << " ";
    cout << endl;
}

//***************************************************************
// Definition of function showArrPtr. *
// This function displays the contents of the array pointed to *
// by arr. size is the number of elements. *
//*************************************************************** 

void showArrPtr(int *arr[], int size) {
    for (int count = 0; count < size; count++)
        cout << *(arr[count]) << " ";
    cout << endl;
}