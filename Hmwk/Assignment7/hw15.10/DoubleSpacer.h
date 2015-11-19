/* 
 * File:   DoubleSpacer.h
 * Author: HaoHuynh
 *
 * Created on November 19, 2015, 10:09 AM
 */

#ifndef DOUBLESPACER_H
#define	DOUBLESPACER_H

#include "AbstractFileFilter.h"

class DoubleSpacer : public AbstractFileFilter {
public:
    DoubleSpacer();
    DoubleSpacer(const DoubleSpacer& orig);
    virtual ~DoubleSpacer();

    virtual void doFilter(ifstream &in, ofstream &out);
    virtual char transform(char ch);

};

#endif	/* DOUBLESPACER_H */

