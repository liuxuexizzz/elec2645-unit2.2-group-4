#ifndef BINARY_CALCULATOR_H
#define BINARY_CALCULATOR_H

#include <string>


std::string binaryAnd(const std::string& bin1, const std::string& bin2);        // Bitwise AND operation
std::string binaryOr(const std::string& bin1, const std::string& bin2);         // Bitwise OR operation
std::string binaryNot(const std::string& bin);                                  // Bitwise NOT operation
std::string binaryNand(const std::string& bin1, const std::string& bin2);       // Bitwise NAND operation
std::string binaryNor(const std::string& bin1, const std::string& bin2);        // Bitwise NOR operation
std::string binaryXor(const std::string& bin1, const std::string& bin2);        // Bitwise XOR operation
std::string binaryXnor(const std::string& bin1, const std::string& bin2);       // Bitwise XNOR operation
bool isBinary(const std::string& str);                                          // Check if a string is a binary number.

#endif // BINARY_CALCULATOR_H
