/* 
 * File:   main.cpp
 * Author: HaoHuynh
 *
 * Created on November 17, 2015, 4:27 PM
 */

#include <cstdlib>
#include "Month.h"
using namespace std;

/*
 * The Month main thread
 */
int main(int argc, char** argv) {
    
    Month feb("February");
    Month mar(3);
    Month month;
    Month iM("Invalid Month Name");
    Month iMN(129);
    ++iMN;
    
    cout << feb--;
    cout << feb;
    cout << mar++;
    cout << mar;
    cout << month--;
    cout << month++;
    cout << month;
    cout << iM;
    cout << iMN;
    
    cin >> month;
    cout << ++month;
    cout << --month;
    
    return 0;
}

