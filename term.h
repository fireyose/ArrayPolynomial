// Author:         Youssef Almkari
// Course:         CSC 136 020
// Assignment:     #3a
// Due Date:       October 8, 2013
// Filename:       term.h
// Purpose:        represents a single Term identity. 
                   

#ifndef TERM_H
#define TERM_H

#include <iostream>

using namespace std;

class Term {

 public:

/*
Function: 	Constructor
Description: 	Sets data in Term to '0'
Parameters:	double - represents a coefficient
		int    - represents a exponent
Returns:      	void
*/

  Term (double = 0, int = 0);

  /* Sets */

/*
Function: 	setCoefficient
Description: 	sets coefficient to specified double
Parameters: 	double - represents a coefficient
Returns:      	void
*/

  void setCoefficient (double);
  
/*
Function:	setExponent
Description: 	sets exponent to specified int
Parameters:	int - represents an exponent
Returns:      	void
*/

  void setExponent (int);

  /* Gets */
  
/*
Function: 	getCoefficient
Description: 	gets the coefficient of the Term
Parameters:	none
Returns:      	double - the Term's coefficient
*/

  double getCoefficient () const;

/*
Function: 	getExponent
Description: 	gets the exponent of the Term
Parameters:	none
Returns:      	int - the Term's exponent
*/

  int getExponent () const;
 
  /* Operators */

/*
Function: 	operator()
Description: 	evaluates Term for a specified input
Parameters:	double - number to evaluate Term by
Returns:      	double - evaluated Term
*/

  double operator() (double);

/*
Function: 	operator*=
Description: 	multiplies Term by specified input
Parameters: 	double - number to multiply Term's coefficient by
Returns:      	void
*/

  void operator*= (double);
  
/*
Function: 	operator==
Description: 	checks if two Terms are equal
Parameters: 	Term - to compare the left Term to
Returns:      	true if Terms are equal, false otherwise
*/

  bool operator== (const Term &);
  
/*
Function: 	operator<
Description: 	checks if left Term is less than right Term
Parameters: 	Term - to compare left Term to
Returns:      	true if left Term is less than right, false otherwise 
*/

  bool operator< (const Term &);

/*
Function: 	operator>
Description: 	checks if left Term is greater than right Term
Parameters: 	Term - to compare left Term to
Returns:      	true if left Term is greater than right, false otherwise
*/

  bool operator> (const Term &);
  
/*
Function: 	operator!=
Description: 	checks if left Term is not equal to right Term
Parameters: 	Term - to compare left Term to
Returns:      	true if left Term is not equal to right, false otherwise
*/

  bool operator!= (const Term &); // If not equal Terms
  
  private:
  double coefficient;
  int exponent;
};

/*
Function: 	operator>>
Description: 	Reads two numbers from file and places them in Term
Parameters:	ifstream - holds file to read from
		Term     - Term to hold data
Returns:      	ifstream - to allow multiple extractions 
*/

ifstream &operator>> (ifstream &, Term &);

/*
Function: 	operator>>
Description: 	reads data from input stream and places in Term
Parameters:    	istream - holds input
		Term    - Term to hold data
Returns:      	istream - to allow multiple extractions
*/

istream &operator>> (istream &, Term &);

/*
Function: 	operator<<
Description: 	outputs Term
Parameters: 	ostream - holds output stream 
		Term    - Term to output
Returns:      	ostream - to allow multiple insertions
*/

ostream &operator<< (ostream &, const Term &);

#endif
