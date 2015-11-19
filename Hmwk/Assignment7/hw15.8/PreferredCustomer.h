/* 
 * File:   PreferredCustomer.h
 * Author: HaoHuynh
 *
 * Created on November 18, 2015, 5:59 PM
 */

#ifndef PREFERREDCUSTOMER_H
#define	PREFERREDCUSTOMER_H

#include "CustomerData.h"

/*
 *A retail store has a preferred customer plan where customers may earn discounts on all
their purchases. The amount of a customer’s discount is determined by the amount of
the customer’s cumulative purchases in the store.
• When a preferred customer spends $500, he or she gets a 5% discount on all future
purchases.
• When a preferred customer spends $1,000, he or she gets a 6% discount on all
future purchases.
• When a preferred customer spends $1,500, he or she gets a 7% discount on all
future purchases.
• When a preferred customer spends $2,000 or more, he or she gets a 10% discount
on all future purchases.
Design a class named PreferredCustomer , which is derived from the CustomerData
class you created in Programming Challenge 7. The PreferredCustomer class should
have the following member variables:
• purchasesAmount (a double )
• discountLevel (a double )
The purchasesAmount variable holds the total of a customer’s purchases to date. The
discountLevel variable should be set to the correct discount percentage, according to
the store’s preferred customer plan. Write appropriate member functions for this class
and demonstrate it in a simple program.
Input Validation: Do not accept negative values for any sales figures.
 */
class PreferredCustomer : public CustomerData {
private:
    double purchasesAmount;
    double discountLevel;
    void setDiscountLevel(double discountLevel);
public:
    PreferredCustomer();

    double getDiscountLevel() const;
    void setPurchasesAmount(double purchasesAmount);
    double getPurchasesAmount() const;


};

#endif	/* PREFERREDCUSTOMER_H */

