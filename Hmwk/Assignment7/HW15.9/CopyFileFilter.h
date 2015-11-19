/* 
 * File:   CopyFileFilter.h
 * Author: HaoHuynh
 *
 * Created on November 18, 2015, 6:29 PM
 */

#ifndef COPYFILEFILTER_H
#define	COPYFILEFILTER_H

#include "AbstractFileFilter.h"

class CopyFileFilter : public AbstractFileFilter {
public:
    CopyFileFilter();
    CopyFileFilter(const CopyFileFilter& orig);
    virtual ~CopyFileFilter();

    virtual char transform(char ch);

};

#endif	/* COPYFILEFILTER_H */

