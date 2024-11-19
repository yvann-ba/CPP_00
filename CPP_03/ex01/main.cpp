#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ClapTrap a("Yvann");
    ClapTrap b("Lilien");
    a.attack("random npc");
    b.takeDamage(5);
    b.beRepaired(6);

    ScavTrap scav("Scavvy");
    scav.attack("enemy");
    scav.takeDamage(20);
    scav.beRepaired(15);
    scav.guardGate();

    ScavTrap copyScav(scav);
    ScavTrap assignedScav;
    assignedScav = scav;

    return 0;
}