/* 
 * File:   AbstractFileFilter.h
 * Author: HaoHuynh
 *
 * Created on November 18, 2015, 6:27 PM
 */

#ifndef ABSTRACTFILEFILTER_H
#define	ABSTRACTFILEFILTER_H

#include <fstream>
#include <iostream>
using namespace std;

class AbstractFileFilter {
public:
    AbstractFileFilter();
    AbstractFileFilter(const AbstractFileFilter& orig);
    virtual ~AbstractFileFilter();
    
    void doFilter(ifstream &in, ofstream &out);

protected:    
    virtual char transform(char ch) = 0;
};

#endif	/* ABSTRACTFILEFILTER_H */

