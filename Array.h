// Author(s):      Youssef Almkari / Dr.Spiegel
// Course:         CSC 136 020
// Assignment:     #3a
// Due Date:       October 8, 2013
// Filename:       Array.h
// Purpose:        to represent a polynomial in the form of a list
//                 with each element holding a Term.                 

#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include "term.h"

using namespace std;

class Array {

 public:
 
/*
Function: 	Constructor
Description: 	declares default capacity to 10
Parameters:	int - capacity of Array
Returns:      	void
*/
 
  Array( int = 10 );
  
/*
Function:	Copy constructor
Description: 	sets left Array to equal right Array
Parameters:	Array - to set left Array to
Returns:      	void
*/
  
  Array( const Array & );
  
/*
Function:	destructor
Description: 	deletes Array
Parameters:	none
Returns:      	void
*/
  
  ~Array();
  
  /** Sets & Gets **/
  
/*
Function:	setCapacity
Description: 	sets the capacity of Array
Parameters:	int - capacity of Array
Returns:      	void
*/

  void setCapacity(int);

/*
Function: 	getCapacity
Description: 	returns the capacity of Array
Parameters:	none
Returns:      	int - capacity of Array
*/
  
  int getCapacity() const;
  
/*
Function: 	getEltsInUse
Description: 	returns the elementsInUse of Array
Parameters:	none
Returns:      	int - elements in use of Array
*/
  
  int getEltsInUse() const;
  
/*
Function: 	setEltsInUse
Description: 	sets the elementsInUse to a given int
Parameters:	int - to set the number of elements
Returns:      	void
*/
  
  void setEltsInUse(int);
  
  /** Operators **/
  
/*
Function: 	operator=
Description: 	assign Arrays
Parameters: 	Array - right side of assignment
Returns:      	n/a
*/

  const Array &operator=( const Array & );
  
/*
Function:	operator==
Description: 	compares if two Arrays are equal
Parameters:	Array - right Array to compare
Returns:      	true if equal, false otherwise
*/
  
  bool operator==( const Array & ) const;
  
/*
Function: 	operator!=
Description: 	checks if two Arrays are not equal
Parameters:	Array - right Array to compare to
Returns:      	true if Arrays are not equal, false otherwise
*/
  
  bool operator!=( const Array &right ) const  
  { return ! ( *this == right ); }
 
/*
Function: 	operator[]
Description: 	checks if index access is valid
Parameters:	int  - represents index
Returns:      	Term - to access
*/

  Term &operator[]( int );
  
/*
Function: 	operator[] const
Description: 	checks if index access is valid for a cont Term
Parameters:	int  - represents index
Returns:      	Term - to access
*/
  
  const Term &operator[]( int ) const;
  
/*
Function: 	operator+=
Description: 	adds Term to Array 
Parameters:	Term - to add to the Array
Returns:      	void
*/
  
  void operator+=(Term &); 
  
/*
Function: 	getArrayCount
Description: 	returns how many Arrays there are
Parameters:	none
Returns:      	int - represents number of Arrays
*/

  static int getArrayCount();
  
/*
Function: 	addTerm
Description: 	decides wether to add, furnish, or reject a Potential Term 
Parameters:	Term - Term to be potentially added
Returns:      	true if Term added/furnished, false otherwise 
*/

  bool addTerm (Term &);
  
/*
Function: 	sort
Description: 	Calls selSort to sort Array
Parameters: 	none
Returns:      	void
*/
  
  void sort();   
  
 private:
  int capacity;           // size of the array
  Term *ptr;              // pointer to first element of array
  int elementsInUse;      // number of elements being used in Array
  static int arrayCount;  // # of Arrays instantiated
  
/*
Function: 	findDubLoc
Description:	finds index of dublicate Terms
Parameters:	Term - to check for a dublicate
		int  - holds index of Array 
Returns:      	true if a dublicate Term was found, false otherwise
*/  
			       
  bool findDubLoc(Term &, int &);
  
};

/*
Function:	operator<<
Description: 	Outputs Array to screen 
Parameters:	ostream - the out stream to screen
		Array   - to output
Returns:      	ostream - to allow multiple insertions 
*/

ostream &operator<<( ostream &, const Array & );

/*
Function: 	operator>>
Description: 	reads input to an Array
Parameters:	istream - hold input 
		Array   - to input to
Returns:      	istream - to allow mutltiple extractions 
*/

istream &operator>>( istream &, Array & );


#endif

