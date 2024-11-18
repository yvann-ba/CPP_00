#include <iostream>
#include "ClapTrap.hpp"

int main( void ) {
    ClapTrap a("Yvann");
    ClapTrap b("Lilien");
    a.attack("random npc");
    b.takeDamage(5);
    b.beRepaired(6);
    ClapTrap c;
    c = b;
    ClapTrap d(a);

    return 0;
}
