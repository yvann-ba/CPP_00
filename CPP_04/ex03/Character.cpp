#include "Character.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

Character::Character() : name("default") {
    //std::cout << "Character Default constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
}
Character::Character(std::string const &name) : name(name) {
    //std::cout << "Character Parameterized constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
}

Character::Character(const Character &other) : name(other.name){
    //std::cout << "Character Copy constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        if (other.inventory[i])
            inventory[i] = other.inventory[i]->clone();
        else
            inventory[i] = NULL;
}

Character &Character::operator=(const Character &other) {
    //std::cout << "Character operator Assignement constructor called" << std::endl;

    if (this != &other) {
            name = other.name;
        for (int i = 0; i < 4; i++) {
            delete inventory[i];
            if (other.inventory[i])
                inventory[i] = other.inventory[i]->clone();
            else
                inventory[i] = NULL;
        }
    }
    return *this;
}

Character::~Character() {
    //std::cout << "Character destructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        delete inventory[i];
    for (size_t i = 0; i < droppedMaterias.size(); i++)
        delete droppedMaterias[i];
}

std::string const &Character::getName() const {
    return name;
}

void Character::equip(AMateria* m) {
    if (!m)
        return;
    for (int i = 0; i < 4; i++) {
        if (inventory[i] == NULL) {
            inventory[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4 && inventory[idx]) {
        droppedMaterias.push_back(inventory[idx]);
        inventory[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4 && inventory[idx])
        inventory[idx]->use(target);
}

