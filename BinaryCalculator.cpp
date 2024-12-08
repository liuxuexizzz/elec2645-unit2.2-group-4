#include "BinaryCalculator.h"
#include "Get_user_input.h"
#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;



/* 
Function: isBinary
Input:    const string& str     // Enter a string.
Output:   bool                  // Boolean value indicating whether it is a binary number
Description: Check whether the input string consists solely of binary characters '0' and '1'.
*/
bool isBinary(const string& str) {
    for (char c : str) {
        if (c != '0' && c != '1') {
            return false; // Find non-binary characters.
        }
    }
    return true; // All characters are binary
}



/* 
Function: binaryAnd
Input:    const string& bin1, bin2 // Two binary strings.
Output:   string                   // The result string of bitwise AND operation.
Description: Perform bitwise AND operation on two binary strings, supporting input strings of variable length.
*/
string binaryAnd(const string& bin1, const string& bin2) {
    size_t len = max(bin1.size(), bin2.size());
    string padded1 = string(len - bin1.size(), '0') + bin1;
    string padded2 = string(len - bin2.size(), '0') + bin2;

    string result;
    for (size_t i = 0; i < len; ++i) {
        result += (padded1[i] == '1' && padded2[i] == '1') ? '1' : '0';
    }
    return result;
}



/* 
Function: binaryOr
Input:    const string& bin1, bin2 // Two binary strings.
Output:   string                   // The result string of bitwise OR operation.
Description: Perform bitwise OR operation on two binary strings, supporting aligned length input.
*/
string binaryOr(const string& bin1, const string& bin2) {
    size_t len = max(bin1.size(), bin2.size());
    string padded1 = string(len - bin1.size(), '0') + bin1;
    string padded2 = string(len - bin2.size(), '0') + bin2;

    string result;
    for (size_t i = 0; i < len; ++i) {
        result += (padded1[i] == '1' || padded2[i] == '1') ? '1' : '0';
    }
    return result;
}



/* 
Function: binaryNot
Input:    const string& bin      // Binary string
Output:   string                 // The result string of bitwise NOT operation
Description: Perform the bitwise NOT operation on a binary string.
*/
string binaryNot(const string& bin) {
    string result;
    for (char c : bin) {
        result += (c == '1') ? '0' : '1';
    }
    return result;
}



/* 
Function: binaryNand
Input:    const string& bin1, bin2 // Two binary strings.
Output:   string                   // The result string of bitwise NAND
Description: After computing the bitwise AND of two binary strings, perform a bitwise NOT operation (NAND = NOT(AND)).
*/
string binaryNand(const string& bin1, const string& bin2) {
    string andResult = binaryAnd(bin1, bin2);
    return binaryNot(andResult);
}



/* 
Function: binaryNor
Input:    const string& bin1, bin2 // Two binary strings.
Output:   string                   // The result string of bitwise NOR operation.
Description: After computing the bitwise OR of two binary strings, perform a bitwise NOT operation (NOR = NOT(OR)).
*/
string binaryNor(const string& bin1, const string& bin2) {
    string orResult = binaryOr(bin1, bin2);
    return binaryNot(orResult);
}



/* 
Function: binaryXor
Input:    const string& bin1, bin2 // Two binary strings.
Output:   string                   // The result of bitwise XOR operation on a string
Description: Perform a bitwise XOR operation on two binary string inputs, supporting aligned length input.
*/
string binaryXor(const string& bin1, const string& bin2) {
    size_t len = max(bin1.size(), bin2.size());
    string padded1 = string(len - bin1.size(), '0') + bin1;
    string padded2 = string(len - bin2.size(), '0') + bin2;

    string result;
    for (size_t i = 0; i < len; ++i) {
        result += (padded1[i] != padded2[i]) ? '1' : '0';
    }
    return result;
}



/* 
Function: binaryXnor
Input:    const string& bin1, bin2 // Two binary strings
Output:   string                   // The result string of bitwise XNOR operation.
Description: After computing the bitwise XOR of two binary strings, perform a bitwise NOT operation (XNOR = NOT(XOR)).
*/
string binaryXnor(const string& bin1, const string& bin2) {
    string xorResult = binaryXor(bin1, bin2);
    return binaryNot(xorResult);
}




/*
An example of a function call:
    using namespace std;
    string bin1, bin2;

    // Get the first binary number.
    do {
        cout << "Enter the first binary number: ";
        bin1 = getStringInput();
        if (!isBinary(bin1)) {
            cout << "Invalid input! Please enter a binary number (only 0 and 1).\n";
        }
    } while (!isBinary(bin1));

    // Get the second binary number.
    do {
        cout << "Enter the second binary number: ";
        bin2 = getStringInput();
        if (!isBinary(bin2)) {
            cout << "Invalid input! Please enter a binary number (only 0 and 1).\n";
        }
    } while (!isBinary(bin2));

    // Display the calculation results.
    cout << "\nResults:\n";
    cout << "AND:   " << binaryAnd(bin1, bin2) << endl;
    cout << "OR:    " << binaryOr(bin1, bin2) << endl;
    cout << "NOT (first number): " << binaryNot(bin1) << endl;
    cout << "NAND:  " << binaryNand(bin1, bin2) << endl;
    cout << "NOR:   " << binaryNor(bin1, bin2) << endl;
    cout << "XOR:   " << binaryXor(bin1, bin2) << endl;
    cout << "XNOR:  " << binaryXnor(bin1, bin2) << endl;
*/




