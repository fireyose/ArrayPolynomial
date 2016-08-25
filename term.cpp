// Author:         Youssef Almkari
// Course:         CSC 136 020 
// Assignment:     #3a
// Due Date:       October 8, 2013
// Filename:       term.cpp 
// Purpose:        implementation of Term class.
//                 includes navigation functions to access Term data.
//                 does not know of anything outside its scope

#include "term.h"
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

/*
Function: 	Constructor
Description: 	Sets data in Term to '0'
Parameters:    	double - represents a coefficient
  	       	int    - represents a exponent
Returns:      	void
*/

Term::Term (double coeff, int expn)
{ setCoefficient (coeff);
  setExponent (expn);
}

/* Sets */

/*
Function:      	setCoefficient
Description: 	sets coefficient to specified double
Parameters:   	double - represents a coefficient
Returns:      	void
*/

void Term::setCoefficient (double newCoeff) // Set coefficient
{ coefficient = newCoeff; }

/*
Function:     	setExponent
Description: 	sets exponent to specified int
Parameters:   	int - represents an exponent
Returns:      	void
*/

void Term::setExponent (int newExpn)        // Set exponent
{ exponent = newExpn; }

/* Gets */

/*
Function:      	getCoefficient
Description: 	gets the coefficient of the Term
Parameters:    	none
Returns:      	double - the Term's coefficient
*/

double Term::getCoefficient () const 
{ return coefficient; }

/*
Function:      	getExponent
Description: 	gets the exponent of the Term
Parameters:   	none
Returns:      	int - the Term's exponent
*/

int Term::getExponent () const
{ return exponent; }

/* Operators */

/*
Function:     	operator()
Description: 	evaluates Term for a specified input
Parameters:    	double - number to evaluate Term by
Returns:      	double - evaluated Term
*/

double Term::operator() (double x)
{ return (getCoefficient() * pow (x, getExponent())); }

/*
Function:     	operator*=
Description: 	multiplies Term by specified input
Parameters:    	double - number to multiply Term's coefficient by
Returns:      	void
*/

void Term::operator*= (double factor)
{ setCoefficient (getCoefficient() * factor); }

/*
Function:     	operator==
Description: 	checks if two Terms are equal
Parameters:  	Term - to compare the left Term to
Returns:      	true if Terms are equal, false otherwise
*/

bool Term::operator== (const Term &T)            // If Term expn are equal
{ return (getExponent() == T.getExponent()); }

/*
Function:     	operator<
Description: 	checks if left Term is less than right Term
Parameters:   	Term - to compare left Term to
Returns:      	true if left Term is less than right, false otherwise 
*/

bool Term::operator< (const Term &T)        // If left Term is less than right
{ return (getExponent() < T.getExponent()); }

/*
Function:     	operator>
Description: 	checks if left Term is greater than right Term
Parameters:    	Term - to compare left Term to
Returns:      	true if left Term is greater than right, false otherwise
*/

bool Term ::operator> (const Term &T)       // If left Term is Greater than right
{ return (getExponent() > T.getExponent()); }

/*
Function:     	operator!=
Description: 	checks if left Term is not equal to right Term
Parameters:   	Term - to compare left Term to
Returns:      	true if left Term is not equal to right, false otherwise
*/

bool Term::operator!= (const Term &T)       // If left Term is not equal to right 
{ return (getCoefficient() != T.getCoefficient() && getExponent() != T.getExponent()); }

/*
Function:     	operator>>
Description: 	Reads two numbers from file and places them in Term
Parameters:   	ifstream - holds file to read from
	      	Term     - Term to hold data
Returns:      	ifstream - to allow multiple extractions 
*/

ifstream &operator>> (ifstream &inFile, Term &T)
{ double coeff = 0;
  int expn = 0;
  inFile >> coeff >> expn;
  T.setCoefficient (coeff);
  T.setExponent (expn);
  return inFile;
}

/*
Function:     	operator>>
Description: 	reads data from input stream and places in Term
Parameters:    	istream - holds input
     		Term    - Term to hold data
Returns:      	istream - to allow multiple extractions
*/

istream &operator>> (istream &input, Term &T)
{ double coeff = 0;
  int expn = 0;
  input >> coeff >> expn;
  T.setCoefficient (coeff);
  T.setExponent (expn);
  return input;
}

/*
Function:    	operator<<
Description: 	outputs Term
Parameters:    	ostream - holds output stream 
      		Term    - Term to output
Returns:      	ostream - to allow multiple insertions
*/

ostream &operator<< (ostream &out, const Term &T)
{ if (T.getCoefficient() == 1 && T.getExponent() == 1)
    out << "x";
  else if (T.getCoefficient() == 1)
    out << "x^" << T.getExponent();
  else if (T.getExponent() == 1)
    out << T.getCoefficient() << "x";
  //else if (T.getCoefficient() == 0)
  else if (T.getExponent() == 0)
    out << T.getCoefficient();
  else
    out << T.getCoefficient() << "x^" << T.getExponent();
  return out;
}

