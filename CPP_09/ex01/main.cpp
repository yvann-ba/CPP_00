#include "RPN.hpp"
#include <iostream>
#include <stdexcept>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    std::string expression = argv[1];

    RPN calculator;
    try
    {
        int result = calculator.calculateExpression(expression);
        std::cout << result << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    return 0;
}
