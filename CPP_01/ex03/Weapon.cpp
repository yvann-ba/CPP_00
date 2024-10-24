#include "Weapon.hpp"

Weapon::Weapon() {}

Weapon::Weapon(std::string type) {
    this->_type = type;
}

Weapon::~Weapon() {}

std::string Weapon::getType() const {
    return (this->_type);
}

void Weapon::setType(std::string new_type) {
    this->_type = new_type;
}