#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name(""), _hit_points(10), _energy_points(10), _attack_damage(0) {
    std::cout << "Default Constructor Called" << std::endl;
}

ClapTrap::ClapTrap(const std::string name) : _name(name),  _hit_points(10), _energy_points(10), _attack_damage(0) {
    std::cout << "Default constructor with name parameter called" << std::endl;
}


ClapTrap::ClapTrap(const ClapTrap& rhs) {
    std::cout << "Copy Constructor Called" << std::endl;
    *this = rhs;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &rhs) {
    std::cout << "Copy assignement operator called" << std::endl;
    if (this != &rhs)
    {
        this->_hit_points = rhs._hit_points;
        this->_name = rhs._name;
        this->_energy_points = rhs._energy_points;
        this->_attack_damage = rhs._attack_damage;
    }
    return *this;
}
ClapTrap::~ClapTrap() {
    std::cout << "Default Destructor Called" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if (this->_energy_points > 0 && this->_hit_points > 0)
    {
        std::cout << "ClapTrap: " << this->_name << " attacks " << target << " causing " << this->_attack_damage << " points of damage !" << std::endl;
        this->_energy_points--;
        std::cout << "ClapTrap: " << this->_name << " now have " << this->_energy_points << " energy points left" << std::endl;
    }
    else
        std::cout << "ClapTrap: " << this->_name << " don't have any energy points or hit points left" << std::endl;
}


void ClapTrap::takeDamage(unsigned int amount) {
    if (this->_hit_points > 0)
    {
        std::cout << "ClapTrap: " << this->_name << " takes " << amount << " damage" << std::endl;
        this->_hit_points -= amount;
        std::cout << "ClapTrap: " << this->_name << " now have " << this->_hit_points << " hit point left" << std::endl;

    }
    else
        std::cout << "ClapTrap: " << this->_name << " can't take more damage" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->_energy_points > 0 && this->_hit_points > 0)
    {
        std::cout << "ClapTrap: " << this->_name << " repairs itself, getting" << amount << "hit points back" << std::endl;
        this->_energy_points--;
        this->_hit_points += amount;
        std::cout << "ClapTrap: " << this->_name << " now have " << this->_hit_points << " hit points" << std::endl;

    }
    else
        std::cout << "ClapTrap: " << this->_name << " don't have any energy points or hit points left" << std::endl;
}