/*
This file provides the basic four operations of the package function,
to provide other functions to call when the operation.
*/
#include "Basic_op.h"
using namespace std;



/* 
Function:       calculate
Input:          double    a           // First operand
                double    b           // Second operand
                char      op          // Operator ('+', '-', '*', '/')
                double&   result      // Reference to store the result of the operation
Output:         basic_op  status      // Status of the operation (SUCCESS, DIVIDE_BY_ZERO, INVALID_OPERATOR)
Description:    Performs basic arithmetic operations based on the given operator and operands. 
                Handles division by zero and invalid operators.
*/
basic_op calculate(double a, double b, char op, double& result) {
    switch (op) {
        case '+':
            result = a + b;
            return basic_op::SUCCESS;
        case '-':
            result = a - b;
            return basic_op::SUCCESS;
        case '*':
            result = a * b;
            return basic_op::SUCCESS;
        case '/':
            if (b == 0) {
                return basic_op::DIVIDE_BY_ZERO; // 检查除零错误
            }
            result = a / b;
            return basic_op::SUCCESS;
        default:
            return basic_op::INVALID_OPERATOR; // 无效运算符
    }
}



/* 
Function:       getErrorMessage
Input:          basic_op  error       // Error code returned from the calculate function
Output:         string    message     // Corresponding error or success message
Description:    Returns a descriptive message based on the error code provided.
*/
string getErrorMessage(basic_op error) {
    switch (error) {
        case basic_op::SUCCESS:
            return "Operation successful.";
        case basic_op::DIVIDE_BY_ZERO:
            return "Error: Division by zero.";
        case basic_op::INVALID_OPERATOR:
            return "Error: Invalid operator.";
        default:
            return "Unknown error.";
    }
}




/*
函数调用示例:
    double result;
    basic_op status = calculate(5, 6, '+', result);

    if (status == basic_op::SUCCESS) {
        cout << "Result: " << result << endl;
    } 
    else 
    {
        cout << getErrorMessage(status) << endl;
    }
*/






