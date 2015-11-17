/* 
 * File:   Employee.cpp
 * Author: HaoHuynh
 * 
 * Created on November 17, 2015, 11:15 AM
 */

#include "Employee.h"

/**
 * Reference to the function declaration
 */
Employee::Employee() {
    name = "";
    idNumber = 0;
    department = "";
    position = "";
}

/**
 * Reference to the function declaration
 * @param eName
 * @param eID
 * @param deprtmnt
 * @param position
 */
Employee::Employee(string eName, int eId, string deprtmnt, string pos) {
    name = eName;
    idNumber = eId;
    department = deprtmnt;
    position = pos;
}

/**
 * Reference to the function declaration
 * @param eName
 * @param eID
 */
Employee::Employee(string eName, int eId) {
    name = eName;
    idNumber = eId;
    department = "";
    position = "";
}

/**
 * Reference to the function declaration
 * @return 
 */
string Employee::getName() const{
    return name;
}

/**
 * Reference to the function declaration
 * @return 
 */
int Employee::getIdNumber() const{
    return idNumber;
}

/**
 * Reference to the function declaration * 
 * @return 
 */
string Employee::getDepartment() const{
    return department;
}

/**
 * Reference to the function declaration
 * @return 
 */
string Employee::getPosition() const{
    return position;
}

/**
 * Reference to the function declaration* 
 * @param eName
 * @return 
 */
void Employee::setName(string eName){
    name = eName;
}

/**
 * Reference to the function declaration
 * @param eId
 */
void Employee::setIdNumber(int eId){
    idNumber = eId;
}

/**
 * Reference to the function declaration
 * @param deprtmnt
 */
void Employee::setDepartment(string deprtmnt){
    department = deprtmnt;
}

/**
 * Reference to the function declaration
 * @param pos
 */
void Employee::setPosition(string pos){
    position = pos;
}