#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name(""), _hit_points(10), _energy_points(10), _attack_damage(0) {
    std::cout << "Default Constructor Called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& rhs) : {
    std::cout << "Copy Constructor Called" << std::endl;
    *this = rhs;
}

ClapTrap::~ClapTrap() {
    std::cout << "Default Destructor Called" << std::endl;
}

void ClapTrap::attack(const std::string& target) {

}

void ClapTrap::takeDamage(unsigned int amount) {

}

void ClapTrap::beRepaired(unsigned int amount) {

}