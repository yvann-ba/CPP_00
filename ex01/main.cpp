#include "RPN.hpp"
#include <iostream>
#include <stdexcept> // for std::runtime_error

int main(int argc, char **argv)
{
    // The program must take exactly one argument: the RPN expression
    if (argc != 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    // Retrieve the expression from argv
    std::string expression = argv[1];

    RPN calculator;  // Instantiate our RPN class

    try
    {
        // Attempt to calculate
        int result = calculator.calculateExpression(expression);
        // Print the result on standard output
        std::cout << result << std::endl;
    }
    catch (const std::exception &e)
    {
        // If any error occurred (bad token, not enough operands, etc.)
        // we print "Error" as per the subject
        std::cerr << "Error" << std::endl;
        return 1;
    }

    return 0;
}
