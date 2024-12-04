#include "Boolean_Algebra.h"
#include "BinaryCalculator.h" 
#include <iostream>
#include <stack>
#include <unordered_map>
#include <stdexcept>

using namespace std;



/* 
Function: precedence (unordered_map)
Input:    None
Output:   unordered_map<char, int> // A map of operators with their precedence values
Description: Defines the precedence for logical operators used in the expression evaluation.
*/
unordered_map<char, int> precedence = {
    {'(', 0},
    {'|', 1},  // OR
    {'&', 2},  // AND
    {'^', 3},  // XOR
    {'!', 4},  // NOT
    {'N', 5},  // NAND
    {'R', 5},  // NOR
    {'X', 5}   // XNOR
};



/* 
Function: evaluate
Input:    const string& a, b     // Two binary operands
          char op               // Operator for the logical operation
Output:   string                // Result of the operation between the operands
Description: Evaluates the result of two operands (a and b) based on the operator (op).
*/
string evaluate(const string& a, const string& b, char op) {
    if (op == '&') return binaryAnd(a, b);
    if (op == '|') return binaryOr(a, b);
    if (op == '^') return binaryXor(a, b);
    if (op == 'N') return binaryNand(a, b);
    if (op == 'R') return binaryNor(a, b);
    if (op == 'X') return binaryXnor(a, b);
    throw invalid_argument("Invalid operator"); // Throws an error if an invalid operator is encountered
}



/* 
Function: applyNot
Input:    const string& a  // Operand to be negated
Output:   string           // Result of the NOT operation applied to operand a
Description: Applies the NOT operation to a given operand.
*/
string applyNot(const string& a) {
    return binaryNot(a);
}



/* 
Function: evaluateExpression
Input:    const string& expression  // A string representing a logical expression
Output:   string                    // The result of the evaluated expression
Description: Parses the expression and computes the result by applying logical operations. Supports parentheses and operator precedence.
*/
string evaluateExpression(const string& expression) {
    stack<string> operands;  // Operand stack
    stack<char> operators;   // Operator stack

    size_t i = 0;
    while (i < expression.size()) {
        char c = expression[i];

        if (c == ' ') {
            // Skip spaces
            ++i;
            continue;
        }

        if (c == '(') {
            // Left parenthesis, push to operators stack
            operators.push(c);
        } else if (c == ')') {
            // Right parenthesis, process until left parenthesis is found
            while (!operators.empty() && operators.top() != '(') {
                char op = operators.top();
                operators.pop();

                if (op == '!') {
                    string a = operands.top(); operands.pop();
                    operands.push(applyNot(a));
                } else {
                    string b = operands.top(); operands.pop();
                    string a = operands.top(); operands.pop();
                    operands.push(evaluate(a, b, op));
                }
            }
            operators.pop(); // Pop the left parenthesis
        } else if (precedence.count(c)) {
            // Operator handling
            while (!operators.empty() && precedence[operators.top()] >= precedence[c]) {
                char op = operators.top();
                operators.pop();

                if (op == '!') {
                    string a = operands.top(); operands.pop();
                    operands.push(applyNot(a));
                } else {
                    string b = operands.top(); operands.pop();
                    string a = operands.top(); operands.pop();
                    operands.push(evaluate(a, b, op));
                }
            }
            operators.push(c); // Push the current operator to the stack
        } else {
            // Operand handling (binary number)
            string binaryStr;
            while (i < expression.size() && (expression[i] == '0' || expression[i] == '1')) {
                binaryStr += expression[i++];
            }
            --i; // Backtrack one character

            if (!isBinary(binaryStr)) {
                throw invalid_argument("Invalid binary number in expression"); // Check if operand is a valid binary string
            }
            operands.push(binaryStr); // Push the operand to the stack
        }

        ++i;
    }

    // Process remaining operators
    while (!operators.empty()) {
        char op = operators.top();
        operators.pop();

        if (op == '!') {
            string a = operands.top(); operands.pop();
            operands.push(applyNot(a));
        } else {
            string b = operands.top(); operands.pop();
            string a = operands.top(); operands.pop();
            operands.push(evaluate(a, b, op));
        }
    }

    return operands.top(); // Return the final result
}



/* 
Function: isValidExpression
Input:    const string& expression  // A string representing a boolean expression to be checked
Output:   bool                     // Returns true if the expression is valid, false otherwise
Description: Checks the validity of a boolean expression by verifying the syntax, including:
             - Valid characters (0, 1, logical operators, parentheses)
             - Proper placement of operators (e.g., no consecutive operators)
             - Balanced parentheses
             - Correct operand and operator positioning
             The function ensures that the expression conforms to standard boolean algebra rules.
*/
bool isValidExpression(const string& expression) {
    stack<char> parentheses;  // 用来检查括号匹配
    bool lastWasOperator = true; // 用来检查操作符位置
    bool lastWasOperand = false; // 用来检查操作数位置

    for (size_t i = 0; i < expression.size(); ++i) {
        char c = expression[i];

        // 忽略空格
        if (c == ' ') {
            continue;
        }

        // 检查数字（只能是0或1）
        if (c == '0' || c == '1') {
            lastWasOperand = true;
            lastWasOperator = false;
        }
        // 检查左括号
        else if (c == '(') {
            parentheses.push(c);
            lastWasOperator = true; // 左括号后面应该跟操作数或另一左括号
        }
        // 检查右括号
        else if (c == ')') {
            if (parentheses.empty()) {
                return false; // 如果没有匹配的左括号
            }
            parentheses.pop();
            lastWasOperand = false; // 右括号后面应该跟操作符或右括号
        }
        // 检查运算符
        else if (c == '&' || c == '|' || c == '^' || c == 'N' || c == 'R' || c == 'X') {
            if (lastWasOperator) {
                return false; // 如果连续出现运算符（例如，&& 或 !!）
            }
            lastWasOperand = false;
            lastWasOperator = true;
        }
        // 检查 NOT 运算符（'!'）
        else if (c == '!') {
            if (!lastWasOperator && i > 0 && expression[i-1] != '(') {
                return false; // '!' 后面不应该跟着数字
            }
            lastWasOperator = true;
            lastWasOperand = false;
        }
        else {
            // 如果有其他无效字符
            return false;
        }
    }

    // 最后应该是一个操作数，而不是操作符
    return !lastWasOperator && parentheses.empty();
}



/*
调用示例：
    std::string expression = "0011&0111&(0001|0000)";
    cout << expression << endl;
    try {
        std::string result = evaluateExpression(expression);
        std::cout << "Expression result: " << result << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
*/




