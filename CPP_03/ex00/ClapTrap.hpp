#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

#include <iostream>

class ClapTrap
{
    private:
        std::string _name;
        int _hit_points;
        int _energy_points;
        int _attack_damage;
    public:
        ClapTrap();
        ClapTrap(const ClapTrap& rhs);
        ~ClapTrap();
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif