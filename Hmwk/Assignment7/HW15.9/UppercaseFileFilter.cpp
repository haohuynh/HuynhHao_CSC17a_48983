/* 
 * File:   UppercaseFileFilter.cpp
 * Author: HaoHuynh
 * 
 * Created on November 18, 2015, 6:28 PM
 */

#include "UppercaseFileFilter.h"

UppercaseFileFilter::UppercaseFileFilter() {
}

UppercaseFileFilter::UppercaseFileFilter(const UppercaseFileFilter& orig) {
}

UppercaseFileFilter::~UppercaseFileFilter() {
}

char UppercaseFileFilter::transform(char ch) {
    return toupper(ch);
}
