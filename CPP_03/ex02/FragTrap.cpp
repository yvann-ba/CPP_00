#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    _hit_points = 100;
    _energy_points = 100;
    _attack_damage = 30;
    std::cout << "FragTrap Default Constructor Called" << std::endl;
}


FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    _name = name;
    _hit_points = 100;
    _energy_points = 50;
    _attack_damage = 20;
    std::cout << "FragTrap Parametrized Constructor Called for " << _name << std::endl;
}

FragTrap::FragTrap(const FragTrap& rhs) : ClapTrap(rhs) {
    std::cout << "FragTrap Copy Constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &rhs) {
    std::cout << "FragTrap Copy assignement operator called" << std::endl;
    if (this != &rhs)
        ClapTrap::operator=(rhs);
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap Default Destructor called for " << _name << std::endl;
}

void FragTrap::attack(const std::string& target) {
    if (_energy_points > 0 && _hit_points > 0)
    {
        std::cout << "FragTrap: " << _name << " attacks " << target << " causing " << _attack_damage << " points of damage !" << std::endl;
        _energy_points--;
        std::cout << "FragTrap: " << _name << " now have " << _energy_points << " energy points left" << std::endl;
    }
    else
        std::cout << "FragTrap: " << _name << " don't have any energy points or hit points left" << std::endl;
}

void FragTrap::highFivesGuys() {
    std::cout << "FragTrap: " << _name << " is requesting a high five" << std::endl;
}