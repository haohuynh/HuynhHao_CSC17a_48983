/* 
 * File:   CustomerData.h
 * Author: HaoHuynh
 *
 * Created on November 18, 2015, 5:19 PM
 */

#ifndef CUSTOMERDATA_H
#define	CUSTOMERDATA_H

#include "PersonData.h"

class CustomerData : public PersonData {
private:
    int customerNumber;
    bool mailingList;
public:
    CustomerData();

    void setMailingList(bool mailingList); 

    bool isMailingList() const; 

    void setCustomerNumber(int customerNumber); 
    
    int getCustomerNumber() const;



};

#endif	/* CUSTOMERDATA_H */

