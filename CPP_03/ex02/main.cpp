#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    // Testing ClapTrap
    ClapTrap a("Yvann");
    ClapTrap b("Lilien");
    a.attack("random npc");
    b.takeDamage(5);
    b.beRepaired(6);

    // Testing ScavTrap
    ScavTrap scav("Scavvy");
    scav.attack("enemy");
    scav.takeDamage(20);
    scav.beRepaired(15);
    scav.guardGate();

    // Copy and assignment tests
    ScavTrap copyScav(scav);
    ScavTrap assignedScav;
    assignedScav = scav;

    return 0;
}