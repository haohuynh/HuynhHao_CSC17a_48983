/* 
 * File:   UppercaseFileFilter.h
 * Author: HaoHuynh
 *
 * Created on November 18, 2015, 6:28 PM
 */

#ifndef UPPERCASEFILEFILTER_H
#define	UPPERCASEFILEFILTER_H

#include "AbstractFileFilter.h"

class UppercaseFileFilter : public AbstractFileFilter {
public:
    UppercaseFileFilter();
    UppercaseFileFilter(const UppercaseFileFilter& orig);
    virtual ~UppercaseFileFilter();

    virtual char transform(char ch);

};

#endif	/* UPPERCASEFILEFILTER_H */

