#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {
    private:

    public:
        ScavTrap();
        ScavTrap(const std::string& name);
        ScavTrap(const ScavTrap& rhs);
        ScavTrap &operator=(const ScavTrap& rhs);
        ~ScavTrap();
};
#endif