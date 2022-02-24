/*
Title: Chapter Thirteen rectangleType Program -- Implementation file
Created by William Schaeffer
CPS 362
P. 997, Challenge 2, rectangleType Program, Week 5
2.17.2022
*/

#include <iostream>
#include "rectangleTypeClass.hpp"

using namespace std;

//overload the stream insertion operator
	//friend function
ostream& operator << (ostream& osObj, const rectangleType& rectangle)
{
	osObj << "Length = " << rectangle.length
		  << "; Width = " << rectangle.width;

	return osObj;
}

//overload the stream extraction operator
	//friend function
istream& operator >> (istream& isObj, rectangleType& rectangle)
{

	isObj >> rectangle.length >> rectangle.width;

	return isObj;
}

//Member functions
double rectangleType::area() const
{
	return length * width;
}

double rectangleType::perimeter() const
{
	return 2 * (length + width);
}

void rectangleType::print() const
{
	cout << "Length = " << length << "and Width = " << width;
}

//Setter or Mutator

void rectangleType::setDimension(double l, double w)
{
	if (l >= 0)
	{
		length = l;
	}
	else
	{
		while (l <= 0)
		{
			cout << "Invalid length entered. Please enter a non-negative value: ";
			cin >> l;
		}	
		length = l;
	}
		

	if (w >= 0)
	{
		width = w;
	}
	else
	{
		while (w <= 0)
		{
			cout << "Invalid width entered. Plese enter a non-negative value: ";
			cin >> w;
		}
		width = w;
	}
		
}

//Getter or Accessor

double rectangleType::getLength() const
{
	return length;
}

double rectangleType::getWidgth() const
{
	return width;
}

//Overload Operators

	//overload the + operator
rectangleType rectangleType::operator+(const rectangleType& rectangle) const
{
	rectangleType tempRec;
	tempRec.length = length + rectangle.length;
	tempRec.width = width + rectangle.width;

	return tempRec;
}

//overload the - operator
rectangleType rectangleType::operator-(const rectangleType& rectangle) const
{
	rectangleType tempRec;
	double l, w;											//length and width values to test for negative

	l = length - rectangle.length;
	
	w = width - rectangle.width;

	if (l >= 0 && w >= 0)
		tempRec.setDimension(l, w);
	else
		cout << "Cannot perform operations that result in negative length or width.\n\n";

	return tempRec;
}

	//overload the * operator
rectangleType rectangleType::operator*(const rectangleType& rectangle) const
{
	rectangleType tempRec;

	tempRec.length = length * rectangle.length;
	tempRec.width = width * rectangle.width;
	
	return tempRec;
}

	//overload the == operator
bool rectangleType::operator==(const rectangleType& rectangle) const
{	
	return (area() == rectangle.area());
}

	//overload the != operator
bool rectangleType::operator!=(const rectangleType& rectangle) const
{
	return (area() != rectangle.area());
}

	//overload the <= operator
bool rectangleType::operator<=(const rectangleType& rectangle) const
{
	return (area() <= rectangle.area());
}

//overload the < operator
bool rectangleType::operator<(const rectangleType& rectangle) const
{
	return (area() < rectangle.area());
}

//overload the >= operator
bool rectangleType::operator>=(const rectangleType& rectangle) const
{
	return (area() >= rectangle.area());
}

//overload the > operator
bool rectangleType::operator>(const rectangleType& rectangle) const
{
	return (area() > rectangle.area());
}

	//overload the pre-increment operator
rectangleType& rectangleType::operator++()
{
	++length;
	++width;

	return *this;
}

	//overload the post-increment operator
rectangleType rectangleType::operator++(int dummy)
{
	rectangleType temp = *this;

	length++;
	width++;

	return temp;
}

	//overload the pre-decrement operator
rectangleType& rectangleType::operator--()
{
	if (length >= 1)
	{
		--length;
	}
	else
	{
		cout << "Cannot use pre-decrement operator to create negative length value.\n\n";
	}
	
	if (width >= 1)
	{
		--width;
	}
	else
	{
		cout << "Cannot use pre-decrement operator to create negative width value.\n\n";
	}

	return *this;
}

	//overload the post-decrement operator
rectangleType rectangleType::operator--(int dummy)
{
	rectangleType temp = *this;

	if (length >= 1)
	{
		length--;
	}
	else
	{
		cout << "Cannot use post-decrement operator to create negative length value.\n\n";
	}

	if (width >= 1)
	{
		width--;
	}
	else
	{
		cout << "Cannot use post-decrement operator to create negative width value.\n\n";
	}

	return temp;
}

//Constructors

	//default constructor
rectangleType::rectangleType()
{
	length = 0;
	width = 0;
}

	//parameterized constructor
rectangleType::rectangleType(double l, double w)
{
	setDimension(l, w);
}