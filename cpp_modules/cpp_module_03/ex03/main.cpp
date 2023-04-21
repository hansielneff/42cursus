#include <iostream>

#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap diatrap("Diatrap");
	diatrap.whoAmI();
	diatrap.guardGate();
	diatrap.highFivesGuys();
	diatrap.attack("Teemu");
	diatrap.takeDamage(40);
	diatrap.beRepaired(20);
	diatrap.takeDamage(80);
	// This shouldn't work
	diatrap.beRepaired(42);
	return 0;
}
