#include "BinaryCalculator.h"
#include "Get_user_input.h"
#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;



/* 
Function: isBinary
Input:    const string& str     // 输入字符串
Output:   bool                  // 是否为二进制数的布尔值
Description: 检测输入字符串是否仅由二进制字符 '0' 和 '1' 组成。
*/
bool isBinary(const string& str) {
    for (char c : str) {
        if (c != '0' && c != '1') {
            return false; // 发现非二进制字符
        }
    }
    return true; // 全部字符为二进制
}



/* 
Function: binaryAnd
Input:    const string& bin1, bin2 // 两个二进制字符串
Output:   string                   // 按位与的结果字符串
Description: 计算两个二进制字符串的按位与操作，支持对齐长度的字符串输入。
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
Input:    const string& bin1, bin2 // 两个二进制字符串
Output:   string                   // 按位或的结果字符串
Description: 计算两个二进制字符串的按位或操作，支持对齐长度的字符串输入。
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
Input:    const string& bin      // 二进制字符串
Output:   string                 // 按位非的结果字符串
Description: 计算二进制字符串的按位非操作。
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
Input:    const string& bin1, bin2 // 两个二进制字符串
Output:   string                   // 按位NAND的结果字符串
Description: 计算两个二进制字符串的按位与后，再按位非操作 (NAND = NOT(AND))。
*/
string binaryNand(const string& bin1, const string& bin2) {
    string andResult = binaryAnd(bin1, bin2);
    return binaryNot(andResult);
}



/* 
Function: binaryNor
Input:    const string& bin1, bin2 // 两个二进制字符串
Output:   string                   // 按位NOR的结果字符串
Description: 计算两个二进制字符串的按位或后，再按位非操作 (NOR = NOT(OR))。
*/
string binaryNor(const string& bin1, const string& bin2) {
    string orResult = binaryOr(bin1, bin2);
    return binaryNot(orResult);
}



/* 
Function: binaryXor
Input:    const string& bin1, bin2 // 两个二进制字符串
Output:   string                   // 按位异或的结果字符串
Description: 计算两个二进制字符串的按位异或操作，支持对齐长度的字符串输入。
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
Input:    const string& bin1, bin2 // 两个二进制字符串
Output:   string                   // 按位XNOR的结果字符串
Description: 计算两个二进制字符串的按位异或后，再按位非操作 (XNOR = NOT(XOR))。
*/
string binaryXnor(const string& bin1, const string& bin2) {
    string xorResult = binaryXor(bin1, bin2);
    return binaryNot(xorResult);
}




/*
函数调用示例：
    using namespace std;
    string bin1, bin2;

    // 获取第一个二进制数
    do {
        cout << "Enter the first binary number: ";
        bin1 = getStringInput();
        if (!isBinary(bin1)) {
            cout << "Invalid input! Please enter a binary number (only 0 and 1).\n";
        }
    } while (!isBinary(bin1));

    // 获取第二个二进制数
    do {
        cout << "Enter the second binary number: ";
        bin2 = getStringInput();
        if (!isBinary(bin2)) {
            cout << "Invalid input! Please enter a binary number (only 0 and 1).\n";
        }
    } while (!isBinary(bin2));

    // 显示计算结果
    cout << "\nResults:\n";
    cout << "AND:   " << binaryAnd(bin1, bin2) << endl;
    cout << "OR:    " << binaryOr(bin1, bin2) << endl;
    cout << "NOT (first number): " << binaryNot(bin1) << endl;
    cout << "NAND:  " << binaryNand(bin1, bin2) << endl;
    cout << "NOR:   " << binaryNor(bin1, bin2) << endl;
    cout << "XOR:   " << binaryXor(bin1, bin2) << endl;
    cout << "XNOR:  " << binaryXnor(bin1, bin2) << endl;
*/




