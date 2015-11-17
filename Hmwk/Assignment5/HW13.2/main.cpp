/* 
 * File:   main.cpp
 * Author: HaoHuynh
 *
 * Created on November 17, 2015, 11:14 AM
 */

#include <cstdlib>
#include <iostream>
#include "Employee.h"

using namespace std;

/*
 * Employee main thread
 */
int main(int argc, char** argv) {

    Employee* e1 = new Employee("Susan Meyers", 47899, "Accounting", "Vice President");
    Employee* e2 = new Employee("Mark Jones", 39119, "IT", "Programmer");
    Employee* e3 = new Employee("Joy Rogers", 81774, "Manufacturing", "Engineer");

    cout << "---------------------------------------------------------------------------\n";
    cout << "Name                ID Number              Department              Position\n";
    cout << "---------------------------------------------------------------------------\n";
    cout << e1->getName() << "        " << e1->getIdNumber() << "                "
            << e1->getDepartment() << "                " << e1->getPosition() << endl;
    cout << e2->getName() << "          " << e2->getIdNumber() << "                "
            << e2->getDepartment() << "                        " << e2->getPosition() << endl;
    cout << e3->getName() << "          " << e3->getIdNumber() << "                "
            << e3->getDepartment() << "             " << e3->getPosition() << endl;


    return 0;
}

