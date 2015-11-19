/* 
 * File:   DoubleSpacer.cpp
 * Author: HaoHuynh
 * 
 * Created on November 19, 2015, 10:09 AM
 */

#include "DoubleSpacer.h"

DoubleSpacer::DoubleSpacer() {
}

DoubleSpacer::DoubleSpacer(const DoubleSpacer& orig) {
}

DoubleSpacer::~DoubleSpacer() {
}

void DoubleSpacer::doFilter(ifstream& in, ofstream& out) {
    char ch;

    if (in.is_open() && out.is_open()) {

        while (in.get(ch) && (ch != -1)) {
            if (ch == '\n') {
                out << ch;
            }
            out << ch;
        }

        in.close();
        out.close();

    } else {
        cerr << "File IO error !!!";
    }
}

char DoubleSpacer::transform(char ch) {
    return ch;
}

