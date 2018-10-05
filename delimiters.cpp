//--------------------------------------------------------------------
//
//   delimiters.cpp
//
//--------------------------------------------------------------------

#include <iostream>
#include <stack>    //To bring over the stack functionality
using namespace std;
//#if LAB6_TEST1
//#   include "StackLinked.cpp"
//#else            //Commented out since needed files were not provided
//#   include "StackArray.cpp"
//#endif

//--------------------------------------------------------------------

bool delimitersOk(const string &expression);

//--------------------------------------------------------------------

int main()
{
    string inputLine;            // Input line
    char   ch;                   // Holding pen for input chars

    cout << "This program checks for properly matched delimiters."
         << endl;

    while( cin )
    {
        cout << "Enter delimited expression (<EOF> to quit) : "
             << endl;

        // Read in one line
        inputLine = "";
        cin.get(ch);
        while( cin && ch != '\n' )
        {
            inputLine = inputLine + ch;
            cin.get(ch);
        }

        if( ! cin )              // Reached EOF: stop processing
            break;
    
        if ( delimitersOk (inputLine) )
            cout << "Valid" << endl;
        else
            cout << "Invalid" << endl;
    }

    return 0;
}

//--------------------------------------------------------------------
// delimitersOk: the function that students must implement for 
//    Programming Exercise 3.
// Note: we used the term "braces" to describe '[' and ']'. It would
//    have been better to use the term "brackets". The program can be
//    easily modified to process any set of matching delimiters.
//--------------------------------------------------------------------

// Insert your delimitersOk function below

bool delimitersOk(const string &expression)
{
    stack<char> holdDelimiter;  //Create the stack

    for(int count = 0; count < expression.size(); count++){ //Loop through string
        if(expression[count] == '(' || expression[count] == '['){
            holdDelimiter.push(expression[count]);
        }   //If there is open character, push onto stack
        if(expression[count] == ')'){   //If closed character, check stack
            if(holdDelimiter.top() == '('){ //If it is a pair, pop old character
                holdDelimiter.pop();
            }
            else{   //If it is open, return false
                return false;
            }
        } 
        if(expression[count] == ']'){   //Same as ')'
            if(holdDelimiter.top() == '['){
                holdDelimiter.pop();
            }
            else{
                return false;
            }
        }
    }
    if(holdDelimiter.empty()){  //Check if there aren't any lonely open pairs
        return true;    //Only way to return valid
    }
    return false;   //If there is, return invalid
}
