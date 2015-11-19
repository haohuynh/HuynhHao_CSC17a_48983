/* 
 * File:   main.cpp
 * Author: HaoHuynh
 *
 * Created on November 18, 2015, 6:25 PM
 */

#include <cstdlib>

#include "AbstractFileFilter.h"
#include "CopyFileFilter.h"
#include "UppercaseFileFilter.h"
#include "EncryptionFileFilter.h"

using namespace std;

/*
 * File Filter main thread
 */
int main(int argc, char** argv) {

    AbstractFileFilter* copyFF = new CopyFileFilter();
    AbstractFileFilter* upFF = new UppercaseFileFilter();
    AbstractFileFilter* enFF = new EncryptionFile();

    ifstream in("FileFilter.txt");
    ofstream outCopy("CopyFileFilter.txt");
    ofstream outUp("UpperFileFilter.txt");
    ofstream outEn("EncryptionFileFilter.txt");

    copyFF->doFilter(in, outCopy);

    in.open("FileFilter.txt");
    upFF->doFilter(in, outUp);

    in.open("FileFilter.txt");
    enFF->doFilter(in, outEn);

    cout << "Please check the three below files for results:\n"
            "1.CopyFileFilter.txt\n"
            "2.UpperFileFilter.txt\n"
            "3.EncryptionFileFilter.txt\n";
    
    return 0;
}

