/* 
 * File:   main.cpp
 * Author: HaoHuynh
 *
 * Created on November 19, 2015, 10:08 AM
 */

#include <cstdlib>

#include "DoubleSpacer.h"

using namespace std;

/*
 * Double Spacer main thread
 */
int main(int argc, char** argv) {


    AbstractFileFilter* dSFF = new DoubleSpacer();

    ifstream in("SingleSpacer.txt");
    ofstream out("DoubleSpacer.txt");

    (static_cast<DoubleSpacer*> (dSFF))->doFilter(in, out);

    cout << "Please user NotePad++ or WordPad to check the file DoubleSpacer.txt !\n";
    return 0;
}

