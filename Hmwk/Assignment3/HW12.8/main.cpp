/* 
 * File:   main.cpp
 * Author: HaoHuynh
 *
 * Created on October 3, 2015, 11:38 AM
 */

#include <iostream>
#include <fstream>

using namespace std;

/**
 * The function opens the specified file in binary mode, 
 * write the contents of the array to the file,
 * and then close the file.
 * @param fileName : the name of a file
 * @param a : the pointer to an int array
 * @param n : the size of the array
 */
void arrayToFile(const char* fileName, int* a, const int n);

/**
 * The function opens the specified file in binary mode, 
 * read its contents into the array,
 * and then close the file.
 * @param fileName : the name of a file
 * @param a : the pointer to an int array
 * @param n : the size of the array
 */
void fileToArray(const char* fileName, int* a, const int n);

/*
 * Array/File Functions
 * Write a complete program that demonstrates these functions by using the arrayToFile
 * function to write an array to a file, and then using the fileToArray function to read
 * the data from the same file. After the data are read from the file into the array, display
 * the array’s contents on the screen.
 */
int main(int argc, char** argv) {

    const char* DATA_FILE_NAME = "data.dat";

    const int SIZE = 10;

    int a[SIZE] = {10, 21, 32, 43, 54, 65, 76, 87, 98, 109};

    int *result;

    arrayToFile(DATA_FILE_NAME, a, SIZE);

    fileToArray(DATA_FILE_NAME, result, SIZE);

    for (int i = 0; i < SIZE; i++) {
        cout << result[i] << " ";
    }

    return 0;
}

/**
 * Reference to the function declaration
 * @param fileName
 * @param a
 * @param n
 */
void arrayToFile(const char* fileName, int* a, const int n) {

    /*The array to file object*/
    fstream aTF(fileName, ios::out | ios::binary);

    if (aTF) {

        aTF.write(reinterpret_cast<char*> (a), n * sizeof (int));
        aTF.close();

    } else {
        cerr << "File I/O issue !!";
    }
}

/**
 * Reference to the function declaration
 * @param fileName
 * @param a
 * @param n
 */
void fileToArray(const char* fileName, int* a, const int n) {

    /*The file to array object*/
    fstream fTA(fileName, ios::in | ios::binary);

    if (fTA) {

        fTA.read(reinterpret_cast<char*> (a), n * sizeof (int));
        fTA.close();

    } else {
        cerr << "File I/O issue !!";
    }
}