/*
Title: Chapter Thirteen rectangleType Program -- rectangleTypeHeader file
Created by William Schaeffer
CPS 362
P. 997, Challenge 2, rectangleType Program, Week 5
2.17.2022
*/

#ifndef H_rectangleType
#define H_rectangleType

#include <iostream>

using namespace std;

class rectangleType
{
//Friend Functions

	//Overload stream insertion and extraction operators
	friend ostream& operator << (ostream&, const rectangleType&);
	friend istream& operator >> (istream&, rectangleType&);

public:

//Member functions

	//calculate area of rectangle via member variables
		//postcondition: return length * width
	double area() const;

	//calculate perimeter of rectangle via member variables
		//postcondition: return 2 * (length + width)
	double perimeter() const;

	//print the length and width of the rectangle via member variables
	void print() const;

//Setter or Mutator

	//set rectangleType member variables
		//postcondition: if l >=0, length = l. If l <= 0, prompt user to enter non-negative value
			//if w >=0, width = w. If w <= 0, prompt user to enter non-negative value
	void setDimension(double l, double w);

//Getter or Accessor
 
	//return the length via rectangleType member variable
	double getLength() const;

	//return the width via rectangleType member variable
	double getWidgth() const;

//Overload Operators

 //overload arithmetic operators

	//overload the + operator
		//postcondition: add length of rectangle 1 and 2, save to temporary rectangle
			//add width of rectangle 1 and 2, save to temporary rectangle.
			//return the temporary rectangle
	rectangleType operator+(const rectangleType&) const;

	//overload the - operator
		//postcondition: subtract length of rectangle 1 from 2, save to temporary rectangle  
			//subtract width of rectangle 1 from 2, save to temporary rectangle 
			//if any results would be negative, do not assign to tempRec
			//return the temporary rectangle
	rectangleType operator-(const rectangleType&) const;

	//overload the * operator
		//postcondition:  multiply length of rectangle 1 by 2, save to temporary rectangle
			//return the temporary rectangle
	rectangleType operator*(const rectangleType&) const;

//overload relational operators

	//overload the == operator
		//postcondition: compare area() of rectangle 1 and 2, return true or false
	bool operator==(const rectangleType&) const;

	//overload the != operator
		//postcondition: compare area() of rectangle 1 and 2, return true or false
	bool operator!=(const rectangleType&) const;

	//overload the <= operator
		//postcondition: compare area() of rectangle 1 and 2, return true or false
	bool operator<=(const rectangleType&) const;

	//overload the < operator
		//postcondition: compare area() of rectangle 1 and 2, return true or false
	bool operator<(const rectangleType&) const;

	//overload the >= operator
		//postcondition: compare area() of rectangle 1 and 2, return true or false
	bool operator>=(const rectangleType&) const;

	//overload the > operator
		//postcondition: compare area() of rectangle 1 and 2, return true or false
	bool operator>(const rectangleType&) const;

 //overload increment and decrement operators

		//postcondition: pre-increment length and width values, return pointer to this to update new values
			//use clockType object by reference
	rectangleType& operator++();
		
		//postcondition: post-increment length and width values, return temp, temp = *this
	rectangleType operator++(int);

		//postcondition: pre-decrement length and width values, unless those values are less than 1
			//return pointer to this to update new values
			//use clockType object by reference
	rectangleType& operator--();

		//postcondition: post-decrement length and width values, unless those values are less than 1
			//return temp, temp = *this
	rectangleType operator--(int);

//Constructors

	//default constructor
		//postcondition: set length and width to 0
	rectangleType();

	//parameterized constructor
		//initialize the object with the values specified by the user. If no values are specified,
			//default values are assumed.
		//postcondition: setDimension()
	rectangleType(double l, double w);

//Abstract Functions
	//none
//Destructor
	//none

private:
	double length;
	double width;
};

#endif
