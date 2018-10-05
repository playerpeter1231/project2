/*
@ProgramAbstract: Exercise 1 Assignment 1
@Created by: Peter W. Rowe
@Date: October 2018
*/

/*
// Quick note, I was unsure if the input was to be from a file for assignment 2 or by hand
// I did it by file, hope that works for you!!
*/

#include <iostream>
#include <stack>
#include <fstream>

using namespace std;

int main()
{
	//Initializations//
	stack<float> postFix; //Stack for postFix 
	ifstream inputFile; //For inputting postfixes
	char charCheck;	//Checks what the current character is
	float operand1, operand2; //For operations
	bool exitEquation; //Lets the program know to end

	cout << "Welcome to the postfix program." << endl;
	inputFile.open("postfixes.txt");	
	//Main function
	for(int count = 0; count < 5; count++){	//Loops menu
		exitEquation = 0;
		while(exitEquation == 0){ //Loops inputs
			inputFile >> charCheck;
			cout << charCheck;
			switch(charCheck){
				//Enters the ints into stack
				case '0': postFix.push(0.0);
						  break;
				case '1': postFix.push(1.0);
						  break;
				case '2': postFix.push(2.0);
						  break;
				case '3': postFix.push(3.0);
						  break;
				case '4': postFix.push(4.0);
						  break;
				case '5': postFix.push(5.0);
						  break;
				case '6': postFix.push(6.0);
						  break;
				case '7': postFix.push(7.0);
						  break;
				case '8': postFix.push(8.0);
						  break;
				case '9': postFix.push(9.0);
						  break;
				//Performs operations
				case '+': operand1 = postFix.top();
						  postFix.pop();
						  operand2 = postFix.top();
						  postFix.pop();
						  postFix.push(operand2 + operand1);
						  break;
				case '-': operand1 = postFix.top();
						  postFix.pop();
						  operand2 = postFix.top();
						  postFix.pop();
						  postFix.push(operand2 - operand1);
						  break;
				case '*': operand1 = postFix.top();
						  postFix.pop();
						  operand2 = postFix.top();
						  postFix.pop();
						  postFix.push(operand2 * operand1);
						  break;
				case '/': operand1 = postFix.top();
						  postFix.pop();
						  operand2 = postFix.top();
						  postFix.pop();
						  postFix.push(operand2 / operand1);
						  break;
				//Sets flag for finished equation
				case '=': exitEquation = 1;
						  break;
				//Checks for unknown characters
				default: cout << endl << "One of the characters is invalid. Please try again.";
					   	 exitEquation = 1;
			}
		}
		//Outputs solution
		cout << " The output of the equation is = " << postFix.top() << endl << endl;
		postFix.pop();
	}
}