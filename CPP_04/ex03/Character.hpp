#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter {
private:
    std::string name;
    AMateria* inventory[4];
    AMateria* floor[4];
public:
    Character();
    Character(std::string const &name);
    Character(const Character &other);
    Character &operator=(const Character &other);
    virtual ~Character();

    std::string const &getName() const;
    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter &target);
};

#endif