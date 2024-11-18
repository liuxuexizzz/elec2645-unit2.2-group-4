#ifndef BASIC_OP_H
#define BASIC_OP_H

#include <string>
using namespace std;



// 定义枚举类型表示错误状态
enum class basic_op {
    SUCCESS,                        // 无错误
    DIVIDE_BY_ZERO,                 // 除零错误
    INVALID_OPERATOR                // 无效运算符错误
};



basic_op calculate(double a, double b, char op, double& result);        // 计算函数声明
string getErrorMessage(basic_op error);                                 // 错误信息输出函数声明

#endif // BASIC_OP_H
