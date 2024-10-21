#include "Weapon.hpp"
#include "HumanB.hpp"

void HumanB::attack()
{
    std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}
