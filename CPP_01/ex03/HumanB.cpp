#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name), _weapon(NULL) {}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon &weapon) {
    this->_weapon = &weapon;
}
void HumanB::attack()
{
    std::cout << this->_name << " attacks with their " << this->_weapon << std::endl;
}
