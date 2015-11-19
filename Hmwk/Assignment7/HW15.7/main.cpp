/* 
 * File:   main.cpp
 * Author: HaoHuynh
 *
 * Created on November 18, 2015, 5:18 PM
 */

#include <cstdlib>
#include <iostream>
#include "CustomerData.h"

using namespace std;

/*
 * Design a class named PersonData with the following member variables:
• lastName
• firstName
• address
• city
• state
• zip
• phone
Write the appropriate accessor and mutator functions for these member variables.
Next, design a class named CustomerData , which is derived from the PersonData
class. The CustomerData class should have the following member variables:
• customerNumber
• mailingList
The customerNumber variable will be used to hold a unique integer for each customer.
The mailingList variable should be a bool . It will be set to true if the customer
wishes to be on a mailing list, or false if the customer does not wish to be on a mailing
list. Write appropriate accessor and mutator functions for these member variables.
Demonstrate an object of the CustomerData class in a simple program.
 */
int main(int argc, char** argv) {

    CustomerData customerData;

    customerData.setAddress("123 ABC XYZ RSP");
    customerData.setCity("FGH");
    customerData.setCustomerNumber(1);
    customerData.setFirstName("HHH");
    customerData.setLastName("AAA");
    customerData.setMailingList(false);
    customerData.setPhone("a-bbb-ccc-dddd");
    customerData.setState("CA");
    customerData.setZip(99999);


    cout << "The current dump customer data:\n";
    cout << "Customer number: " << customerData.getCustomerNumber() << endl;
    cout << "Last name: " << customerData.getLastName() << endl;
    cout << "First name: " << customerData.getFirstName() << endl;
    cout << "Address: " << customerData.getAddress() << endl;
    cout << "City: " << customerData.getCity() << endl;
    cout << "Sate: " << customerData.getState() << endl;
    cout << "Zip: " << customerData.getZip() << endl;
    cout << "Phone: " << customerData.getPhone() << endl;
    cout << "Address: " << customerData.getAddress() << endl;
    cout << "Mailing: " << customerData.isMailingList() << endl;







    return 0;
}

