/* 
 * File:   Month.cpp
 * Author: HaoHuynh
 * 
 * Created on November 17, 2015, 4:27 PM
 */

#include "Month.h"

/*
 * Reference to the constant declaration
 */
Month const Month::JANUARY("January", 1);

/*
 * Reference to the constant declaration
 */
Month const Month::FEBRUARY("February", 2);

/*
 * Reference to the constant declaration
 */
Month const Month::MARCH("March", 3);

/*
 * Reference to the constant declaration
 */
Month const Month::APRIL("April", 4);

/*
 * Reference to the constant declaration
 */
Month const Month::MAY("May", 5);

/*
 * Reference to the constant declaration
 */
Month const Month::JUNE("June", 6);

/*
 * Reference to the constant declaration
 */
Month const Month::JULY("July", 7);

/*
 * Reference to the constant declaration
 */
Month const Month::AUGUST("August", 8);

/*
 * Reference to the constant declaration
 */
Month const Month::SEPTEMBER("September", 9);

/*
 * Reference to the constant declaration
 */
Month const Month::OCTOBER("October", 10);

/*
 * Reference to the constant declaration
 */
Month const Month::NOVEMBER("November", 11);

/*
 * Reference to the constant declaration
 */
Month const Month::DECEMBER("December", 12);

/*
 * Reference to the constant declaration
 */
Month const Month::months[] = {JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER};

/**
 * Reference to the function declaration
 * @param name
 * @param mNumber
 */
Month::Month(string name, int mNumber) {
    this->name = name;
    this->monthNumber = mNumber;
};

/**
 * Reference to the function declaration
 */
Month::Month() {
    this->name = JANUARY.name;
    this->monthNumber = JANUARY.monthNumber;
}

/**
 * Reference to the function declaration
 * @param name
 */
Month::Month(string name) {

    for (int i = 0; i < MONTH_SIZE; i++) {
        if (name == months[i].name) {
            this->name = months[i].name;
            this->monthNumber = months[i].monthNumber;
            return;
        }
    }

    this->name = JANUARY.name;
    this->monthNumber = JANUARY.monthNumber;
    
}

/**
 * Reference to the function declaration
 * @param monthNumber
 */
Month::Month(int monthNumber) {

    for (int i = 0; i < MONTH_SIZE; i++) {
        if (monthNumber == months[i].monthNumber) {
            this->name = months[i].name;
            this->monthNumber = months[i].monthNumber;
            return;
        }
    }

    this->name = JANUARY.name;
    this->monthNumber = JANUARY.monthNumber;
}

/**
 * Reference to the function declaration
 * @return the name of a month
 */
string Month::getName() const {
    return name;
}

/**
 * Reference to the function declaration
 * @return the number of a month
 */
int Month::getMonthNumber() const {
    return monthNumber;
}

/**
 * Reference to the function declaration
 * @param name
 */
void Month::setName(string name) {

    for (int i = 0; i < MONTH_SIZE; i++) {
        if (name == months[i].name) {
            this->name = months[i].name;
            this->monthNumber = months[i].monthNumber;
            return;
        }
    }

}

/**
 * Reference to the function declaration
 * @param monthNumber
 */
void Month::setMonthNumber(int monthNumber) {

    for (int i = 0; i < MONTH_SIZE; i++) {
        if (monthNumber == months[i].monthNumber) {
            this->name = months[i].name;
            this->monthNumber = months[i].monthNumber;
            return;
        }
    }

}

/**
 * Reference to the function declaration
 * @return 
 */
Month Month::operator ++() {

    int i;

    //Identify the current month
    for (i = 0; i < MONTH_SIZE && name != months[i].name; i++);

    //Go back to January if the current month is December
    if (i == (MONTH_SIZE - 1)) {
        i = 0;
    } else {
        i++; //Go to the next month
    }

    name = months[i].name;
    monthNumber = months[i].monthNumber;

    return *this;
}

/**
 * Reference to the function declaration
 * @param i
 * @return 
 */
Month Month::operator ++(int) {

    Month result(name, monthNumber);

    ++(*this);

    return result;
}

/**
 * Reference to the function declaration
 * @return 
 */
Month Month::operator --() {
    int i;

    //Identify the current month
    for (i = 0; i < MONTH_SIZE && name != months[i].name; i++);

    //Go to December if the current month is January
    if (i == 0) {
        i = (MONTH_SIZE - 1);
    } else {
        i--; //Go back to the previous month
    }

    name = months[i].name;
    monthNumber = months[i].monthNumber;

    return *this;
}

/**
 * Reference to the function declaration 
 * @param 
 * @return 
 */
Month Month::operator --(int) {
    Month result(name, monthNumber);

    --(*this);

    return result;
}

/**
 * Reference to the friend function declaration 
 * @param os
 * @param month
 * @return 
 */
ostream &operator <<(ostream &os, const Month &month) {
    os << "This month is: " << month.name << "(" << month.monthNumber << ")\n";
    return os;
}

/**
 * Reference to the friend function declaration 
 * @param is
 * @param month
 * @return 
 */
istream &operator >>(istream &is, Month &month) {

    int mNumber;

    cout << "Please enter the number of a month:";
    is >> mNumber;

    month.setMonthNumber(mNumber);

    return is;
}