#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
    private:
        Weapon _weapon;
        std::string _name;
    public:
        void attack();
};

#endif