#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    _hit_points = 100;
    _energy_points = 50;
    _attack_damage = 20;
    std::cout << "ScavTrap Default Constructor Called" << std::endl;
}


ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    _name = name;
    _hit_points = 100;
    _energy_points = 50;
    _attack_damage = 20;
    std::cout << "ScavTrap Parametrized Constructor Called for " << _name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& rhs) : ClapTrap(rhs) {
    std::cout << "ScavTrap Copy Constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &rhs) {
    std::cout << "ScavTrap Copy assignement operator called" << std::endl;
    if (this != &rhs)
        ClapTrap::operator=(rhs);
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap Default Destructor called for " << _name << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (_energy_points > 0 && _hit_points > 0)
    {
        std::cout << "ScavTrap: " << _name << " attacks " << target << " causing " << _attack_damage << " points of damage !" << std::endl;
        _energy_points--;
        std::cout << "ScavTrap: " << _name << " now have " << _energy_points << " energy points left" << std::endl;
    }
    else
        std::cout << "ScavTrap: " << _name << " don't have any energy points or hit points left" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap: " << _name << " is now in GateKeeper mode" << std::endl;
}