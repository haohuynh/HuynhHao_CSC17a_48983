/* 
 * File:   Month.h
 * Author: HaoHuynh
 *
 * Created on November 17, 2015, 4:27 PM
 */

#ifndef MONTH_H
#define	MONTH_H

#include <string>
#include <iostream>

using namespace std;

//The forward declaration of class Month
class Month;

//Function prototypes
ostream &operator << (ostream &, const Month &);
istream &operator >> (istream &, Month &);


class Month {
private:
      
    /*
     * The January instance of this Month class 
     */
    static const Month JANUARY;
    
    /*
     * The February instance of this Month class 
     */
    static const Month FEBRUARY;
    
    /*
     * The March instance of this Month class 
     */
    static const Month MARCH;
    
    /*
     * The April instance of this Month class 
     */
    static const Month APRIL;
    
    /*
     * The May instance of this Month class 
     */
    static const Month MAY;
    
    /*
     * The June instance of this Month class 
     */
    static const Month JUNE;
    
    /*
     * The July instance of this Month class 
     */
    static const Month JULY;
    
    /*
     * The August instance of this Month class 
     */
    static const Month AUGUST;
    
    /*
     * The September instance of this Month class 
     */
    static const Month SEPTEMBER;
    
    /*
     * The October instance of this Month class 
     */
    static const Month OCTOBER;
    
    /*
     * The November instance of this Month class 
     */
    static const Month NOVEMBER;
    
    /*
     * The December instance of this Month class 
     */
    static const Month DECEMBER;
    
    /*
     * The number of months in a year
     */
    static const int MONTH_SIZE = 12;
    
    /*
     * The list of names of months in a year
     */
    static const Month months[];
    
    /*
     * The name of a month
     */
    string name;

    /*
     * The number of the month
     */
    int monthNumber;
    
    /**
     * This private default constructor accepts the name and the number of a month as the arguments
     * and assigns them to the proper properties.
     * @param name
     * @param mNumber
     */
    Month(string name, int mNumber);
    
public:
    /*
     * This constructor that sets monthNumber to 1 and name to “January.” 
     */
    Month();

    /**
     * This constructor accepts the name of the month as an argument. It then sets name
     * to the value passed as the argument and sets monthNumber to the correct value.
     * @param name
     */
    Month(string name);

    /**
     * This constructor accepts the number of the month as an argument. It then sets
     * monthNumber to the value passed as the argument and sets name to the correct month
     * name.
     * @param monthNumber
     */
    Month(int monthNumber);

    /**
     * A get function for the name
     * @return 
     */
    string getName() const;

    /**
     * A get function for the month number
     * @return 
     */
    int getMonthNumber() const;

    /**
     * A set function for the name
     * @return 
     */
    void setName(string name);

    /**
     * A set function for the month number
     * @return 
     */
    void setMonthNumber(int monthNumber);

    /**
     * Prefix overloaded ++ operator functions that increment monthNumber
     * and set name to the name of next month. If monthNumber is set to 12 when these
     * functions execute, they should set monthNumber to 1 and name to “January.”
     * @return the next month
     */
    Month operator++();

    /**
     * Postfix overloaded ++ operator functions that increment monthNumber
     * and set name to the name of next month. If monthNumber is set to 12 when these
     * functions execute, they should set monthNumber to 1 and name to “January.”
     * @return this current month
     */
    Month operator++(int);

    /**
     * Prefix overloaded −− operator functions that decrement monthNumber
     * and set name to the name of previous month. If monthNumber is set to 1 when these
     * functions execute, they should set monthNumber to 12 and name to “December.”
     * @return the previous month
     */
    Month operator--();

    /**
     * Post overloaded −− operator functions that decrement monthNumber
     * and set name to the name of previous month. If monthNumber is set to 1 when these
     * functions execute, they should set monthNumber to 12 and name to “December.”
     * @param i
     * @return this current month
     */
    Month operator--(int);
    
    /*
     * Overloading cout ’s << operator
     */
    friend ostream &operator << (ostream &, const Month &);
    
    /*
     * Overloading cin ’s >> operator
     */
    friend istream &operator >> (istream &, Month &);

};

#endif	/* MONTH_H */

