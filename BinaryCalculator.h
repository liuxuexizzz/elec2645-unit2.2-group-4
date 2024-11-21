#ifndef BINARY_CALCULATOR_H
#define BINARY_CALCULATOR_H

#include <string>


std::string binaryAnd(const std::string& bin1, const std::string& bin2);        // 按位与操作
std::string binaryOr(const std::string& bin1, const std::string& bin2);         // 按位或操作
std::string binaryNot(const std::string& bin);                                  // 按位非操作
std::string binaryNand(const std::string& bin1, const std::string& bin2);       // 按位NAND操作
std::string binaryNor(const std::string& bin1, const std::string& bin2);        // 按位NOR操作
std::string binaryXor(const std::string& bin1, const std::string& bin2);        // 按位XOR操作
std::string binaryXnor(const std::string& bin1, const std::string& bin2);       // 按位XNOR操作
bool isBinary(const std::string& str);                                          // 检测字符串是否为二进制数

#endif // BINARY_CALCULATOR_H
