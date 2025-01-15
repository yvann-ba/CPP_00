#include "RPN.hpp"
#include <stack>      // We use std::stack as our container (for RPN logic)
#include <sstream>    // std::istringstream
#include <cstdlib>    // std::atoi
#include <stdexcept>  // std::runtime_error
#include <iostream>   // debugging or error messages

RPN::RPN() {}

RPN::RPN(const RPN &other)
{
    *this = other;
}

RPN &RPN::operator=(const RPN &other)
{
    (void)other;
    return *this;
}

RPN::~RPN() {}

/*
 * isOperator
 * Checks if the token is one of "+", "-", "*", "/".
 */
bool RPN::isOperator(const std::string &token) const
{
    return (token == "+" || token == "-" || token == "*" || token == "/");
}

/*
 * applyOperation
 *  - Takes an operator (op) in string form
 *  - Takes two integers a and b
 *  - Returns the result of "a op b"
 *
 * NOTE: Because of typical RPN order, if the stack says "top is b, next is a",
 *        in the expression it's actually "a b op", so we do "a op b".
 *
 * We must handle division by zero.
 */
int RPN::applyOperation(const std::string &op, int a, int b) const
{
    if (op == "+")
        return a + b;
    else if (op == "-")
        return a - b;
    else if (op == "*")
        return a * b;
    else if (op == "/")
    {
        if (b == 0)
            throw std::runtime_error("division by zero");
        return a / b;
    }
    // Should never happen if our isOperator() check is correct
    throw std::runtime_error("unknown operator");
}

/*
 * calculateExpression
 * We parse the expr string:
 *   1) Split by spaces -> tokens
 *   2) If token is a number: push it onto the stack
 *   3) If token is an operator:
 *       - pop top two numbers from stack
 *       - apply operation => push result back
 *   4) At the end, there must be exactly ONE number in the stack => result
 * If any error (token not recognized, not enough numbers, or leftover stack items)
 * => throw an exception (we handle it in main, or you can handle it here).
 */
int RPN::calculateExpression(const std::string &expr)
{
    std::stack<int> stk;

    // We'll use an istringstream to read space-delimited tokens from expr
    std::istringstream iss(expr);
    std::string token;

    while (iss >> token)
    {
        // 1) If token is an operator?
        if (isOperator(token))
        {
            // Must have at least two operands on the stack
            if (stk.size() < 2)
                throw std::runtime_error("not enough operands for operator " + token);

            // The top of the stack is 'b', then beneath it is 'a'
            int b = stk.top(); 
            stk.pop();
            int a = stk.top();
            stk.pop();

            // Apply "a op b"
            int result = applyOperation(token, a, b);
            // push the result
            stk.push(result);
        }
        // 2) Else, is it a single-digit number? (since "numbers used... always < 10")
        else
        {
            // We check if the token is exactly one character and is digit [0-9].
            if (token.size() == 1 && token[0] >= '0' && token[0] <= '9')
            {
                int value = token[0] - '0'; // convert char -> int
                stk.push(value);
            }
            else
            {
                // The subject says if there's parentheses or decimals => Error
                // any other stuff => Error
                throw std::runtime_error("invalid token: " + token);
            }
        }
    }

    // After processing all tokens, we expect exactly one item in the stack
    if (stk.size() != 1)
        throw std::runtime_error("invalid RPN expression (stack not size 1)");

    return stk.top(); // final result
}
