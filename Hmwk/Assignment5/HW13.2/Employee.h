/* 
 * File:   Employee.h
 * Author: HaoHuynh
 *
 * Created on November 17, 2015, 11:15 AM
 */

#ifndef EMPLOYEE_H
#define	EMPLOYEE_H

#include <string>
using namespace std;

class Employee {
private:

    /*The employee’s name*/
    string name;

    /*The employee’s ID number*/
    int idNumber;

    /*The name of the department where the employee works.*/
    string department;

    /*The employee’s job title*/
    string position;

public:
    /**
     * The default constructor that assigns empty strings ( "" ) to the name , department , and
     * position member variables, and 0 to the idNumber member variable
     */
    Employee();

    /**
     * This constructor accepts the following values as arguments and assigns them to
     * the appropriate member variables: employee’s name, employee’s ID number, department,
     * and position
     * @param eName
     * @param eID
     * @param deprtmnt
     * @param position
     */
    Employee(string eName, int eId, string deprtmnt, string pos);

    /**
     * This constructor accepts the following values as arguments and assigns them to the
     * appropriate member variables: employee’s name and ID number. The department
     * and position fields should be assigned an empty string ( "" ).
     * @param eName
     * @param eID
     */
    Employee(string eName, int eId);
    
    /**
     * The employee's name getter
     * @return name 
     */
    string getName() const;
    
    /**
     * The employee's ID number getter
     * @return idNumber
     */
    int getIdNumber() const;
    
    /**
     * The department getter
     * @return department
     */
    string getDepartment() const;
    
    /**
     * The position getter
     * @return position
     */
    string getPosition() const;
    
    /**
     * The employee's name setter
     * @param eName
     */
    void setName(string eName);
    
    /**
     * The employee's ID number setter
     * @param eId
     */
    void setIdNumber(int eId);
    
    /**
     * The department setter
     * @param deprtmnt
     */
    void setDepartment(string deprtmnt);
    
    /**
     * The position setter
     * @param pos
     */
    void setPosition(string pos);
};

#endif	/* EMPLOYEE_H */

