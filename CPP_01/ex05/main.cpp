#include "Harl.hpp"

int main()
{
    Harl harl;
    std::cout << "Harl Debug :" << std::endl;
    harl.complain("DEBUG");
    std::cout << std::endl;

    std::cout << "Harl Info :" << std::endl;
    harl.complain("INFO");
    std::cout << std::endl;

    std::cout << "Harl Warning :" << std::endl;
    harl.complain("WARNING");
    std::cout << std::endl;

    std::cout << "Harl Error :" << std::endl;
    harl.complain("ERROR");
    std::cout << std::endl;

    std::cout << "Empty Input :" << std::endl;
    harl.complain("");
    std::cout << std::endl;

    std::cout << "Invalid Input :" << std::endl;
    harl.complain("xfgbfghfgv");
    std::cout << std::endl;
    return 0;
}