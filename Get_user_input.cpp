#include "Get_user_input.h"
#include <iostream>
#include <limits>

using namespace std;

// Function to get a double input from the user
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



// Function to get an integer input from the user
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



// Function to get a string input from the user
string getStringInput() {
    string input;

    // Clear the buffer if it's already in an error state
    if (cin.fail()) {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
    }

    cout << "Please enter a string: ";
    getline(cin, input); // Read the entire line

    // Validate empty input
    if (input.empty()) {
        cout << "Input cannot be empty. Please try again.\n";
        return getStringInput(); // Recursively call until valid input
    }

    return input;
}



// Function to get a single character input from the user
char getCharInput() {
    char input;
    cin >> input; // Read a single character
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
    return input;
}
