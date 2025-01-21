#include "Bureaucrat.hpp"

int main () {
    try 
    {
        Bureaucrat poppy("poppy", 1);
        std::cout << poppy << std::endl;

        poppy.incrementGrade();
        std::cout << poppy << std::endl;
    }
    catch(const std::exception& e) 
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Bureaucrat invalidHigh("InvalidHigh", 0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Bureaucrat invalidLow("InvalidLow", 151);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}