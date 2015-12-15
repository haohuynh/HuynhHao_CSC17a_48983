// SimpleVector class template
#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H
#include <iostream>
#include <new>       // Needed for bad_alloc exception
#include <cstdlib>   // Needed for the exit function
using namespace std;

template <class T>
class SimpleVector
{
private:
   T *aptr;          // To point to the allocated array
   int arraySize;    // Number of utilizede elements in the array
   int maxSize;      // Max Size of array
   void memError();  // Handles memory allocation errors
   void subError();  // Handles subscripts out of range

public:
   // Default constructor
   SimpleVector()
      { aptr = 0; arraySize = 0; maxSize = 0;}
      
   // Constructor declaration
   SimpleVector(int);
   
   // Copy constructor declaration
   SimpleVector(const SimpleVector &);
   
   // Destructor declaration
   ~SimpleVector();
   
   // Accessor to return the array size
   int size() const
      { return arraySize; }
   
   int mSize() const
      { return maxSize; }

   // Accessor to return a specific element
   T getElementAt(int position);

   // Overloaded [] operator declaration
   T &operator[](const int &);
   
   //Add and delete elements
   void push_back(T val);
   T pop();
   
   //Add and delete elements inefficiently 
   void pushBack(T val);
   T popValue();
};

//New delete function
template <class T>
T SimpleVector<T>::pop(){
    //Create the new array
    if(arraySize<=maxSize/2){
        maxSize/=2;
        T *nPtr=new T[maxSize];
        //Fill with old values
        for(int i=0;i<arraySize;i++){
                nPtr[i]=aptr[i];
        }
        //Destroy the old array
        delete []aptr;
        //Point the old to the new
        aptr=nPtr;
    }
    return aptr[--arraySize];
}

//New add to function
template <class T>
void SimpleVector<T>::push_back(T val){
    //Create the new array
    if(arraySize==maxSize){
        maxSize*=2;
        T *nPtr=new T[maxSize];
        //Fill with old values
        for(int i=0;i<arraySize;i++){
                nPtr[i]=aptr[i];
        }
        //New Value add
        nPtr[arraySize++]=val;
        //Destroy the old array
        delete []aptr;
        //Point the old to the new
        aptr=nPtr;
    }else{
        aptr[arraySize++]=val;
    }
}

/**
 * New inefficient add function
 * @param val
 */
template <class T>
void SimpleVector<T>::pushBack(T val){
    //Create the new array
    if(arraySize==maxSize){
        maxSize = (arraySize + 1);
        T *nPtr=new T[maxSize];
        //Fill with old values
        for(int i=0;i<arraySize;i++){
                nPtr[i]=aptr[i];
        }
        //New Value add
        nPtr[arraySize++]=val;
        //Destroy the old array
        delete []aptr;
        //Point the old to the new
        aptr=nPtr;
    }else{
        aptr[arraySize++]=val;
    }
}

/**
 * New inefficient delete function
 * @return 
 */
template <class T>
T SimpleVector<T>::popValue(){
    return aptr[--arraySize];
}

//***********************************************************
// Constructor for SimpleVector class. Sets the size of the *
// array and allocates memory for it.                       *
//***********************************************************

template <class T>
SimpleVector<T>::SimpleVector(int s)
{
   arraySize = s;
   maxSize=s;
   // Allocate memory for the array.
   try
   {
      aptr = new T [s];
   }
   catch (bad_alloc)
   {
      memError();
   }

   // Initialize the array.
   for (int count = 0; count < arraySize; count++)
      *(aptr + count) = 0;
}

//*******************************************
// Copy Constructor for SimpleVector class. *
//*******************************************

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj)
{
   // Copy the array size.
   arraySize = obj.arraySize;
   maxSize = obj.maxSize; 
   
   // Allocate memory for the array.
   aptr = new T [arraySize];
   if (aptr == 0)
      memError();
      
   // Copy the elements of obj's array.
   for(int count = 0; count < arraySize; count++)
      *(aptr + count) = *(obj.aptr + count);
}

//**************************************
// Destructor for SimpleVector class.  *
//**************************************

template <class T>
SimpleVector<T>::~SimpleVector()
{
   if (arraySize > 0)
      delete [] aptr;
}

//*******************************************************
// memError function. Displays an error message and     *
// terminates the program when memory allocation fails. *
//*******************************************************

template <class T>
void SimpleVector<T>::memError()
{
   cout << "ERROR:Cannot allocate memory.\n";
   exit(EXIT_FAILURE);
}

//***********************************************************
// subError function. Displays an error message and         *
// terminates the program when a subscript is out of range. *
//***********************************************************

template <class T>
void SimpleVector<T>::subError()
{
   cout << "ERROR: Subscript out of range.\n";
   exit(EXIT_FAILURE);
}

//*******************************************************
// getElementAt function. The argument is a subscript.  *
// This function returns the value stored at the sub-   *
// cript in the array.                                  *
//*******************************************************

template <class T>
T SimpleVector<T>::getElementAt(int sub)
{
   if (sub < 0 || sub >= arraySize)
      subError();
   return aptr[sub];
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************

template <class T>
T &SimpleVector<T>::operator[](const int &sub)
{
   if (sub < 0 || sub >= arraySize)
      subError();
   return aptr[sub];
}
#endif