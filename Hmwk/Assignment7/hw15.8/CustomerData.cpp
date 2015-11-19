/* 
 * File:   CustomerData.cpp
 * Author: HaoHuynh
 * 
 * Created on November 18, 2015, 5:19 PM
 */

#include "CustomerData.h"

CustomerData::CustomerData() {
}

void CustomerData::setMailingList(bool mailingList) {
    this->mailingList = mailingList;
}

bool CustomerData::isMailingList() const {
    return mailingList;
}

void CustomerData::setCustomerNumber(int customerNumber) {
    this->customerNumber = customerNumber;
}

int CustomerData::getCustomerNumber() const {
    return customerNumber;
}

