/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on June 4, 2014, 1:01 PM
 */

//System Libraries
#include <cstdlib>
#include <iostream>
using namespace std;

//User Libraries
#include "SimpleVector.h"

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Instantiate a vector
    int size=5;
    SimpleVector<int> vec(size);
    cout<<"The vector size = "<<vec.size()<<endl;
    cout<<"The vector max size = "<<vec.mSize()<<endl;
    //Fill the vector with values
    for(int i=0;i<size;i++){
        vec[i]=i;
    }
    //Print the result
    for(int i=0;i<size;i++){
        cout<<i<<" = "<<vec[i]<<endl;
    }
    //Add a new element
    vec.pushBack(500);
    cout<<"The vector size = "<<vec.size()<<endl;
    cout<<"The vector max size = "<<vec.mSize()<<endl;
    for(int i=0;i<vec.size();i++){
        cout<<i<<" = "<<vec[i]<<endl;
    }
    //Add a new element
    vec.pushBack(1000);
    cout<<"The vector size = "<<vec.size()<<endl;
    cout<<"The vector max size = "<<vec.mSize()<<endl;
    for(int i=0;i<vec.size();i++){
        cout<<i<<" = "<<vec[i]<<endl;
    }
    //Delete 3 elements
    vec.popValue();
    vec.popValue();
    vec.popValue();
    cout<<"The vector size = "<<vec.size()<<endl;
    cout<<"The vector max size = "<<vec.mSize()<<endl;
    for(int i=0;i<vec.size();i++){
        cout<<i<<" = "<<vec[i]<<endl;
    }
    //Exit stage right
    return 0;
}

