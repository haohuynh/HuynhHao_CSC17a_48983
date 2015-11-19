/* 
 * File:   AbstractFileFilter.cpp
 * Author: HaoHuynh
 * 
 * Created on November 18, 2015, 6:27 PM
 */

#include "AbstractFileFilter.h"

AbstractFileFilter::AbstractFileFilter() {
}

AbstractFileFilter::AbstractFileFilter(const AbstractFileFilter& orig) {
}

AbstractFileFilter::~AbstractFileFilter() {
}

void AbstractFileFilter::doFilter(ifstream& in, ofstream& out) {

    char ch;

    if (in.is_open() && out.is_open()) {

        while (in.get(ch) && (ch != -1)) {
            out << transform(ch);
        }

        in.close();
        out.close();

    } else {
        cerr << "File IO error !!!";
    }

}

