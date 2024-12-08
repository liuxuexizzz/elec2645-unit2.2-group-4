#ifndef BOOLEAN_ALGEBRA_H
#define BOOLEAN_ALGEBRA_H

#include <string>
#include <unordered_map>
#include <stack>
#include <stdexcept>
using namespace std;

string evaluateExpression(const string& expression);                  // Parse and evaluate the expression
bool isValidExpression(const string& expression);                     // Check if a Boolean expression is valid
#endif // BOOLEAN_ALGEBRA_H
