/* 
 * File:   Car.h
 * Author: HaoHuynh
 *
 * Created on November 17, 2015, 12:03 PM
 */

#ifndef CAR_H
#define	CAR_H

#include <string>

using namespace std;

class Car {
private:

    /*The car’s year model.*/
    int yearModel;

    /*The make of the car.*/
    string make;

    /*The car’s current speed.*/
    int speed;


public:
    /**
     * A default constructor
     */
    Car();

    /**
     * This constructor accepts the car’s year model and make as arguments.
     * These values are assigned to the object’s yearModel and make member
     * variables. The constructor also assigns 0 to the speed member variables.
     * @param yModel
     * @param mk
     */
    Car(int yModel, string mk);

    /**
     * The car’s year model getter
     * @return 
     */
    int getYearModel() const;

    /**
     * The make of the car getter
     * @return 
     */
    string getMake() const;

    /**
     * The car’s current speed getter
     * @return 
     */
    int getSpeed() const;
    
    /**
     * This function adds 5 to the speed member variable
     * each time it is called
     */
    void accelerate() {
        speed += 5;
    }

    /**
     * This function subtracts 5 from the speed member variable each
     * time it is called
     */
    void brake() {
        speed -= 5;
    }
};

#endif	/* CAR_H */

