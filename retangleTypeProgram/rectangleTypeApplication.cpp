/*
Title: Chapter Thirteen rectangleType Program -- Source file
Created by William Schaeffer
CPS 362
P. 997, Challenge 2, rectangleType Program, Week 5
2.17.2022
*/

//This program will demonstrate the updated rectangleType class

#include <iostream>
#include "rectangleTypeClass.hpp"

using namespace std;

//Function Prototypes
void welcomeUser();															//Function to welcome user
char inputValidation(char&);												//Function for input validation


int main()
{
	char runAgain = 'Y';													//initialize variable to run program again, default to yes to start

	welcomeUser();															//call introduction function

	while (toupper(runAgain) == 'Y')										//while 'Y', run program, else quits

	{
		rectangleType myRec(12, 20);										//initialize internal clock
		rectangleType yourRec;												//initialize user rectangle at default values
		rectangleType ourRec;												//initialize default rectangle to save operations to

		cout << "My rectangle:\n" << myRec << endl;
		cout << "Your initial rectangle: " << yourRec << endl;

		cout << "Please enter dimensions.\n";
		//cout << "You will enter length and width: ";
		//cin >> yourRec;													//honestly I don't love this because
																			//validating for negative input is a pain 
																			//unncomment this section AND 
//to test cin >> yourRec, comment this section vv
		double myRecLength;													//initialize variable to assign to length and width
		double myRecWidth;

		cout << "length: ";
		cin >> myRecLength;
		cout << endl;
		cout << "width: ";
		cin >> myRecWidth;
//to test cin>> yourRec, comment this section ^^
		
	//set the dimensions of your rectaingle
		yourRec.setDimension(myRecLength, myRecWidth);

		cout << endl << endl;

		cout << "The set dimensions for your rectangle are: " << yourRec << endl << endl;
		cout << "The set dimensions for our rectangle are: " << ourRec << endl << endl;

	//test overloaded post-decrement your rectangle
		cout << "post-decrement of your rectangle: \n\n";

		yourRec--;

		cout << "The set dimensions for your rectangle are: " << yourRec << endl << endl;

	//test overloaded pre-decrement your rectangle
		cout << "pre-decrement of your rectangle: \n\n";

		--yourRec;

		cout << "The set dimensions for your rectangle are: " << yourRec << endl << endl;

	//test overloaded post-increment of your rectangle
		cout << "post-increment of your rectangle: \n\n";

		yourRec++;

		cout << "The set dimensions for your rectangle are: " << yourRec << endl << endl;

	//test overloaded pre-increment of your rectangle
		cout << "pre-increment of your rectangle: \n\n";

		++yourRec;

		cout << "The set dimensions for your rectangle are: " << yourRec << endl << endl;

	//test overloaded == operator
		if (myRec == yourRec)
			cout << "My rectangle and your rectangle are equal in area.\n\n";
		else
			cout << "My rectangle and your rectangle are not equal in area.\n\n";

	//test overloaded != operator
		if (myRec != ourRec)
			cout << "My rectangle and our rectangle are not equal in area.\n\n";
		else
			cout << "My rectangle and our rectangle are equal in value.\n\n";

	//test overloaded <= operator
		if (myRec <= yourRec)
			cout << "My rectangle is less than or equal to the area of your rectangle.\n\n";
		else
			cout << "My rectangle is greater than the area of your rectangle.\n\n";

	//test overloaded < operator
		if (myRec < ourRec)
			cout << "My rectangle is less than the area of our rectangle.\n\n";
		else
			cout << "My rectangle is greater than or equal to the area of our rectangle.\n\n";

	//test overloaded >= operator
		if (myRec >= yourRec)
			cout << "My rectangle is greater than or equal to the value of your rectaingle.\n\n";
		else
			cout << "My rectangle is less than the area of your rectangle.\n\n";

	//test overloaded > operator
		if (myRec > ourRec)
			cout << "My rectangle is greater than the area of our rectangle.\n\n";
		else
			cout << "My rectangle is less than or equal to the area of our rectangle.\n\n";

	//test overloaded addition (+) operator
		ourRec = myRec + yourRec;

		cout << "The set dimensions for our rectangle are: " << ourRec << endl << endl;

	//test overloaded subtraction (-) operator
		ourRec = myRec - yourRec;

		cout << "The set dimensions for our rectangle are: " << ourRec << endl << endl;

	//run program again?
		cout << "\n\nWould you like to run program again? Please enter 'Y' or 'N':\n\n";

		cin >> runAgain;

		cout << endl;

		runAgain = inputValidation(runAgain);    							//user Validation of 'Y' or 'N'
	}

	cout << "Thank you for running the program.";

	return 0;
}
//Function Definitions

//Introduce User to Program

void welcomeUser()
{
	cout << "\tWelcome to the Rectangle Type Program.\n\n"
		<< "You will enter the dimensions to create a new rectangleType class object. This object will be used to"
		<< "test out various overloaded operator functions. Finally, the program will demonstrate \n"
		<< "various use of the overloaded operators as non=members of the class rectangleType. \n\n";
}

//User input validation for selections, must be 'Y' or 'N'

char inputValidation(char& input)
{
	while (toupper(input) != 'Y' && toupper(input) != 'N')    				//convert y or n to Y or N, do not accept any other input
	{
		cout << endl << "Please enter 'Y' or 'N':\n\n";
		cin >> input;
		cin.ignore();
	}

	return input;

}
