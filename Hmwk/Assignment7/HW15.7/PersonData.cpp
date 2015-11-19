/* 
 * File:   PersonData.cpp
 * Author: HaoHuynh
 * 
 * Created on November 18, 2015, 5:18 PM
 */

#include "PersonData.h"

PersonData::PersonData() {
}

void PersonData::setPhone(string phone) {
    this->phone = phone;
}

string PersonData::getPhone() const {
    return phone;
}

void PersonData::setZip(int zip) {
    this->zip = zip;
}

int PersonData::getZip() const {
    return zip;
}

void PersonData::setState(string state) {
    this->state = state;
}

string PersonData::getState() const {
    return state;
}

void PersonData::setCity(string city) {
    this->city = city;
}

string PersonData::getCity() const {
    return city;
}

void PersonData::setAddress(string address) {
    this->address = address;
}

string PersonData::getAddress() const {
    return address;
}

void PersonData::setFirstName(string firstName) {
    this->firstName = firstName;
}

string PersonData::getFirstName() const {
    return firstName;
}

void PersonData::setLastName(string lastName) {
    this->lastName = lastName;
}

string PersonData::getLastName() const {
    return lastName;
}



