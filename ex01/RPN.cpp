#include "RPN.hpp"
#include <stack>
#include <sstream>
#include <cstdlib>
#include <stdexcept>
#include <iostream>

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

bool RPN::isOperator(const std::string &token) const
{
    return (token == "+" || token == "-" || token == "*" || token == "/");
}

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
    throw std::runtime_error("unknown operator");
}

int RPN::calculateExpression(const std::string &expr)
{
    std::stack<int> stk;

    std::istringstream iss(expr);
    std::string token;

    while (iss >> token)
    {
        if (isOperator(token))
        {
            if (stk.size() < 2)
                throw std::runtime_error("not enough operands for operator " + token);

            int b = stk.top();
            stk.pop();
            int a = stk.top();
            stk.pop();

            int result = applyOperation(token, a, b);
            stk.push(result);
        }
        else
        {
            if (token.size() == 1 && token[0] >= '0' && token[0] <= '9')
            {
                int value = token[0] - '0';
                stk.push(value);
            }
            else
            {
                throw std::runtime_error("invalid token: " + token);
            }
        }
    }

    if (stk.size() != 1)
        throw std::runtime_error("invalid RPN expression (stack not size 1)");

    return stk.top();
}
