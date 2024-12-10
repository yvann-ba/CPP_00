
#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"
class Character : public ICharacter {
private:
    std::string name;
    AMateria* inventory[4];
public:
    Character(std::string const &name);
    Character(const Character &other);
    Character &operator=(const Character &other);
    virtual ~Character();

    std::string const getName()
};