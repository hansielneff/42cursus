#include <iostream>

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap clappy("Clappy");
	clappy.attack("Teemu");
	clappy.takeDamage(4);
	clappy.beRepaired(2);
	clappy.attack("June");
	clappy.takeDamage(7);
	clappy.attack("Dean");
	clappy.takeDamage(1);
	// Should not work
	clappy.beRepaired(2);
	clappy.attack("Mark");
	return 0;
}
