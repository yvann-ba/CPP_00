#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    std::cout << "ScavTrap Default Constructor Called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
    std::cout << "ScavTrap Parametrized Constructor Called" << std::endl;
}



