#include "Zombie.hpp"

Zombie::Zombie() : _name("Nameless Zombie") { 
}

Zombie::Zombie(std::string name) : _name(name) {
}

Zombie::~Zombie() {
    std::cout << this->_name << " is destroyed!" << std::endl;
}

std::string Zombie::getName() const{
    return this->_name;
}

void Zombie::setName(std::string name) {
    this->_name = name;
}

void Zombie::announce(void) {
    std::cout << this->_name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}
