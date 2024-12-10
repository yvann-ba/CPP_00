#ifndef CURE_HPP
# define CURE_HPP

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"
class Ice : public AMateria {
    Ice();
    Ice(const Ice &other);
    Ice &operator=(const Ice &other);
    virtual ~Ice();

    virtual AMateria* clone() const;
    virtual void use(ICharacter& target);
};

#endif