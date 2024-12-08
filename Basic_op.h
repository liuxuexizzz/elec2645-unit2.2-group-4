#ifndef BASIC_OP_H
#define BASIC_OP_H

#include <string>
using namespace std;



// Defining enumerated types represents error states.
enum class basic_op {
    SUCCESS,                        // There are no errors.
    DIVIDE_BY_ZERO,                 // Zero Error
    INVALID_OPERATOR                // Invalid operator error
};



basic_op calculate(double a, double b, char op, double& result);        // Declaring Computational Functions
string getErrorMessage(basic_op error);                                 // Declaration of the error message output function

#endif // BASIC_OP_H
