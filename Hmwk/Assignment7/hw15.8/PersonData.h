/* 
 * File:   PersonData.h
 * Author: HaoHuynh
 *
 * Created on November 18, 2015, 5:18 PM
 */

#ifndef PERSONDATA_H
#define	PERSONDATA_H

#include <string>
using namespace std;

class PersonData {
private:

    string lastName;
    string firstName;
    string address;
    string city;
    string state;
    int zip;
    string phone;

public:
    PersonData();

    void setPhone(string phone);

    string getPhone() const;

    void setZip(int zip);

    int getZip() const;

    void setState(string state);

    string getState() const;

    void setCity(string city);

    string getCity() const;

    void setAddress(string address);

    string getAddress() const;

    void setFirstName(string firstName);

    string getFirstName() const;

    void setLastName(string lastName);

    string getLastName() const;



};

#endif	/* PERSONDATA_H */

