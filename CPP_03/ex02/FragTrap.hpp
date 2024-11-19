#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap {
    private:

    public:
        FragTrap();
        FragTrap(const std::string& name);
        FragTrap(const FragTrap& rhs);
        FragTrap &operator=(const FragTrap& rhs);
        ~FragTrap();

        void attack(const std::string &target);
        void highFivesGuys();
};
#endif