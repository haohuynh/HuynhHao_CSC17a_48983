/* 
 * File:   main.cpp
 * Author: HaoHuynh
 *
 * Created on October 3, 2015, 8:47 AM
 */

#include <iostream>
#include <cctype>
#include <cstring>
#include <string.h>
#include <limits.h>
#include <stdio.h>

using namespace std;

/**
 * This function accepts a pointer to a C-string as its argument.Then, it counts 
 * the number of vowels appearing in the string and return that number.
 * @param string
 * @return the number of vowels
 */
int countVowels(const char* string);

/**
 * This function accepts a pointer to a C-string as its argument.Then, it counts 
 * the number of consonants appearing in the string and return that number.
 * @param string
 * @return the number of consonants 
 */
int countConsonants(const char* string);

/**
 * Clean up cin buffer to get a new input exactly
 */
void cleanCBuffer();

/*
 * Vowels and Consonants
 * 1. The user is asked to enter a string.
 * 2. The program displays the following menu:
 *  A) Count the number of vowels in the string
 *  B) Count the number of consonants in the string
 *  C) Count both the vowels and consonants in the string
 *  D) Enter another string
 *  E) Exit the program
 * 3. The program performs the operation selected by the user and repeats until the user
 *    selects E to exit the program. 
 */
int main(int argc, char** argv) {

    string str;
    
    /*An option character*/
    char opChar;

    cout << "Please enter a string: ";
    getline(cin, str);

    do {

        cout << " A) Count the number of vowels in the string\n"
                " B) Count the number of consonants in the string\n"
                " C) Count both the vowels and consonants in the string\n"
                " D) Enter another string\n"
                " E) Exit the program\n";

        opChar = toupper(cin.get());
        cleanCBuffer();

        if (opChar == 'A') {
            cout << "The number of vowels: " << countVowels(str.c_str()) << endl;

        } else if (opChar == 'B') {
            cout << "The number of consonants: " << countConsonants(str.c_str()) << endl;

        } else if (opChar == 'C') {
            cout << "The number of vowels: " << countVowels(str.c_str()) << endl;
            cout << "The number of consonants: " << countConsonants(str.c_str()) << endl;

        } else if (opChar == 'D') {
            cout << "Please enter another string: ";
            getline(cin, str);
        }

    } while (opChar != 'E');

    return 0;
}

/**
 * Reference to the function declaration
 * @param string
 * @return the number of vowels
 */
int countVowels(const char* string) {

    /*A collection of all vowels*/
    static const char vowels[] = "AEIOUaeiou";

    /*The number of vowels*/
    int nVowels = 0;

    //Check if each char of string is appeared in vowels, then increase the counter
    for (int i = 0; i < strlen(string); i++) {
        if (strchr(vowels, string[i]) != NULL) {
            nVowels++;
        }
    }

    return nVowels;
}

/**
 * Reference to the function declaration
 * @param string
 * @return the number of consonants 
 */
int countConsonants(const char* string) {

    /*A collection of all vowels*/
    static const char vowels[] = "AEIOUaeiou";

    /*The number of consonants*/
    int nOfCon = 0;

    //Check if each char of string is an alpha but not appeared in vowels
    //, then increase the counter
    for (int i = 0; i < strlen(string); i++) {
        if (isalpha(string[i]) && (strchr(vowels, string[i]) == NULL)) {
            nOfCon++;
        }
    }

    return nOfCon;
}

/**
 * Reference to the function declaration
 */
void cleanCBuffer() {
    cin.ignore();
    cin.clear();
}