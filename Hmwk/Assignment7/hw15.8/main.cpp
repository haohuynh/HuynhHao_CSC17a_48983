/* 
 * File:   main.cpp
 * Author: HaoHuynh
 *
 * Created on November 18, 2015, 5:58 PM
 */

#include <cstdlib>
#include <iostream>
#include "PreferredCustomer.h"
using namespace std;

/*
 * The PreferredCustomer main thread
 */
int main(int argc, char** argv) {

    PreferredCustomer pCusData;

    pCusData.setAddress("123 ABC XYZ RSP");
    pCusData.setCity("FGH");
    pCusData.setCustomerNumber(1);
    pCusData.setFirstName("HHH");
    pCusData.setLastName("AAA");
    pCusData.setMailingList(false);
    pCusData.setPhone("a-bbb-ccc-dddd");
    pCusData.setState("CA");
    pCusData.setZip(99999);
    pCusData.setPurchasesAmount(3000);

    cout << "The current dump customer data:\n";
    cout << "Customer number: " << pCusData.getCustomerNumber() << endl;
    cout << "Last name: " << pCusData.getLastName() << endl;
    cout << "First name: " << pCusData.getFirstName() << endl;
    cout << "Address: " << pCusData.getAddress() << endl;
    cout << "City: " << pCusData.getCity() << endl;
    cout << "Sate: " << pCusData.getState() << endl;
    cout << "Zip: " << pCusData.getZip() << endl;
    cout << "Phone: " << pCusData.getPhone() << endl;
    cout << "Address: " << pCusData.getAddress() << endl;
    cout << "Mailing: " << pCusData.isMailingList() << endl;
    cout << "Purchases amount: " << pCusData.getPurchasesAmount() << endl;
    cout << "Discount level: " << pCusData.getDiscountLevel() << endl;
    
    return 0;
}

