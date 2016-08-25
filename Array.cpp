// Author(s):      Youssef Almkari/ Dr. Spiegel
// Course:         CSC 136 020
// Assignment:     #3a
// Due Date:       October 8, 2013
// Filename:       Array.h
// Purpose:        to represent a polynomial in the form of a list
//                 with each element holding a Term.

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <assert.h>
#include "Array.h"
#include "SortSearch.h"

 using namespace std;

// Initialize static data member at file scope
int Array::arrayCount = 0;   // no objects yet

/*
Function: 	Constructor
Description: 	declares default capacity to 10
Parameters:	int - capacity of Array
Returns:      	void
*/

Array::Array( int arrayCapacity )
{
  setCapacity(( arrayCapacity > 0 ? arrayCapacity : 10 )); 
  ptr = new Term[getCapacity()]; // create space for array
  assert( ptr != 0 );            // terminate if memory not allocated
  ++arrayCount;                  // count one more object
  setEltsInUse (0);		 // sets elementsInUse to '0'
  
  for ( int i = 0; i < getCapacity(); i++ )
    ptr[ i ] = 0;          // initialize array, not really needed
}

/*
Function:	Copy constructor
Description: 	sets left Array to equal right Array
Parameters:	Array - to set left Array to
Returns:      	void
*/

Array::Array( const Array &init )
{ setCapacity (init.getCapacity());   // copy Array's capacity
  setEltsInUse (init.getEltsInUse()); // copy Array's numer of elements in use
  ptr = new Term[getCapacity()];      // create space for array
  assert( ptr != 0 );                 // terminate if memory not allocated
  ++arrayCount;                       // count one more object
  
  for ( int i = 0; i < getEltsInUse(); i++ ) // copy over elements in use only
    ptr[ i ] = init.ptr[ i ];                // copy init into object
}

/*
Function:	destructor
Description: 	deletes Array
Parameters:	none
Returns:      	void
*/

Array::~Array()
{
  delete [] ptr;            // reclaim space for array
  --arrayCount;             // one fewer objects
}

/*
Function:	setCapacity
Description: 	sets the capacity of Array
Parameters:	int - capacity of Array
Returns:      	void
*/

void Array::setCapacity(int elts)
{ capacity = elts; }

/*
Function: 	getCapacity
Description: 	returns the capacity of Array
Parameters:	none
Returns:      	int - capacity of Array
*/

int Array::getCapacity() const 
{ return capacity; }

/*
Function: 	getEltsInUse
Description: 	returns the elementsInUse of Array
Parameters:	none
Returns:      	int - elements in use of Array
*/

int Array::getEltsInUse() const
{ return elementsInUse; }

/*
Function: 	setEltsInUse
Description: 	sets the elementsInUse to a given int
Parameters:	int - to set the number of elements
Returns:      	void
*/

void Array::setEltsInUse(int num)
{ elementsInUse = num; }

/*
Function: 	operator=
Description: 	assign Arrays
Parameters: 	Array - right side of assignment
Returns:      	n/a
*/

const Array &Array::operator=( const Array &right )
{
  if ( &right != this ) {  // check for self-assignment
    
    // for arrays of different sizes, deallocate original
    // left side array, then allocate new left side array.
    if ( getCapacity() != right.getCapacity() ) {
      delete [] ptr;                       // reclaim space
      setCapacity (right.getCapacity());   // resize this object
      setEltsInUse (right.getEltsInUse()); // copys Array's number of elements in use
      ptr = new Term[getCapacity()];       // create space for array copy
      assert( ptr != 0 );                  // terminate if not allocated
    }
    
    for ( int i = 0; i < getEltsInUse(); i++ ) // copy over elements in use only
      ptr[ i ] = right[ i ];                   // copy array into object
  }

  return *this;   // enables x = y = z;
}

/*
Function:	operator==
Description: 	compares if two Arrays are equal
Parameters:	Array - right Array to compare
Returns:      	true if equal, false otherwise
*/

bool Array::operator==( const Array &right ) const
{
  if ( getCapacity() != right.getCapacity() )
    return false;    // arrays of different capacity
  
  for ( int i = 0; i < getEltsInUse(); i++ ) // check only elements in use
    if ( ptr[ i ] != right[ i ] )
      return false;   // arrays are not equal
  
  return true;        // arrays are equal
}

/*
Function: 	operator[]
Description: 	checks if index access is valid
Parameters:	int  - represents index
Returns:      	Term - to access
*/

Term &Array::operator[]( int subscript )
{
  // check for subscript out of range error
  // check elements in use only
  assert( 0 <= subscript && subscript < getEltsInUse() );
  
  return ptr[ subscript ]; // reference return
}

/*
Function: 	operator[] const
Description: 	checks if index access is valid for a cont Term
Parameters:	int  - represents index
Returns:      	Term - to access
*/

const Term &Array::operator[]( int subscript ) const
{
  // check for subscript out of range error
  // check elements in use only
  assert( 0 <= subscript && subscript < getEltsInUse() );
  
  return ptr[ subscript ]; // const reference return
}

/*
Function: 	operator+=
Description: 	adds Term to Array 
Parameters:	Term - to add to the Array
Returns:      	void
*/

void Array::operator+=(Term &right)
{ ptr[elementsInUse++] = right;
}

/*
Function: 	getArrayCount
Description: 	returns how many Arrays there are
Parameters:	none
Returns:      	int - represents number of Arrays
*/
 
int Array::getArrayCount() 
{ return arrayCount; }

/*
Function: 	addTerm
Description: 	decides whether to add, furnish, or reject a Potential Term 
Parameters:	Term - Term to be potentially added
Returns:      	true if Term added/furnished, false otherwise 
*/

bool Array::addTerm (Term &T)
{ int dubLoc = 20;
  // Matching Exponents                                                                                                                             
  if (findDubLoc (T, dubLoc)) {
    ptr[dubLoc].setCoefficient (ptr[dubLoc].getCoefficient() + T.getCoefficient());
    return true;
    }
  // Add term to the end of array                                                                                                                   
  else if (getEltsInUse() < getCapacity()) {
    *this += T;
    sort();
    return true;
  }
  // No match or room                                                                                                                               
  else
    return false;
}

/*
Function: 	sort
Description: 	Calls selSort to sort Array
Parameters: 	none
Returns:      	void
*/

void Array::sort()
{ selSort (ptr, getEltsInUse()); }

/*
Function: 	findDubLoc
Description:	finds index of dublicate Terms
Parameters:	Term - to check for a dublicate
		int  - holds index of Array 
Returns:      	true if a dublicate Term was found, false otherwise
*/

bool Array::findDubLoc (Term &T, int &dubLoc)
{ for (int i = 0; i < getEltsInUse(); i++)
    if (ptr[i] == T) {
      dubLoc = i;
      break;
      }
  if (dubLoc >= 0 && dubLoc < 10)
    return true;
  else
    return false;
}

/*
Function:	operator<<
Description: 	Outputs Array to screen 
Parameters:	ostream - the out stream to screen
		Array   - to output
Returns:      	ostream - to allow multiple insertions 
*/
 
ostream &operator<<( ostream &output, const Array &a )
{
  int i;
  for ( i = 0; i < a.getEltsInUse(); i++ ) {
    if (i == a.getEltsInUse()-1)
	output << a[ i ];
    else
	output << a[ i ] << " + ";
    
  }
  
  if ( i % 5 != 0 )
    output << endl;
  
  return output;   // enables cout << x << y;
}

/*
Function: 	operator>>
Description: 	reads input to an Array
Parameters:	istream - hold input 
		Array   - to input to
Returns:      	istream - to allow mutltiple extractions 
*/

istream &operator>>( istream &input, Array &a )
{
  for ( int i = 0; i < a.getCapacity(); i++ )
    input >> a[ i ];
  
  return input;   // enables cin >> x >> y;
}
