#include "Get_user_input.h"
#include <iostream>
#include <limits>

using namespace std;

/* 
Function:       getDoubleInput
Input:          None (reads from standard input)
Output:         A valid double value entered by the user
Description:    Prompts the user to input a double value. If the user provides invalid input,
                the function clears the error state, discards invalid input, and recursively
                re-prompts the user until a valid double is entered.
*/
double getDoubleInput() {
    double input;
    cin >> input;

    // Validate the input
    if (cin.fail()) {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
        cout << "Invalid input. Please enter a valid double value.\n";
        return getDoubleInput(); // Recursively call until valid input
    }
    return input;
}



/* 
Function:       getIntInput
Input:          None (reads from standard input)
Output:         A valid integer value entered by the user
Description:    Prompts the user to input an integer value. If the user provides invalid input,
                the function clears the error state, discards invalid input, and recursively
                re-prompts the user until a valid integer is entered.
*/
int getIntInput() {
    int input;
    cin >> input;

    // Validate the input
    if (cin.fail()) {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
        cout << "Invalid input. Please enter a valid integer.\n";
        return getIntInput(); // Recursively call until valid input
    }
    return input;
}



/* 
Function:       getStringInput
Input:          None (reads from standard input)
Output:         A valid string entered by the user
Description:    Prompts the user to input a string. If the input buffer is in an error state
                or the user enters an empty string, the function re-prompts the user until
                a valid string is entered. 
*/
string getStringInput() {
    string input;

    // Clear the buffer if it's already in an error state
    if (cin.fail()) {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
    }

    getline(cin, input); // Read the entire line

    // Validate empty input
    while (input.empty()) {
        return getStringInput(); // Recursively call until valid input
    }

    return input;
}



/* 
Function:       getCharInput
Input:          None (reads from standard input)
Output:         A single character entered by the user
Description:    Prompts the user to input a single character. If the input buffer contains
                extra characters, they are discarded. The function always returns the first
                character entered by the user.
*/
char getCharInput() {
    char input;
    cin >> input; // Read a single character
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
    return input;
}



/*
Function Call Example:

    // Declare variables to hold user input
    double doubleInput;
    int intInput;
    string stringInput;
    char charInput;

    // Call getDoubleInput to get a valid double from the user
    cout << "Enter a double value: ";
    doubleInput = getDoubleInput();  // Function call

    // Call getIntInput to get a valid integer from the user
    cout << "Enter an integer value: ";
    intInput = getIntInput();  // Function call

    // Call getStringInput to get a valid string from the user
    stringInput = getStringInput();  // Function call

    // Call getCharInput to get a single character from the user
    cout << "Enter a single character: ";
    charInput = getCharInput();  // Function call
*/

