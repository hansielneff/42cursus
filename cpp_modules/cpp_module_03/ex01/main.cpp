#include <iostream>

#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap scavvy("Scavvy");
	scavvy.guardGate();
	scavvy.attack("Teemu");
	scavvy.takeDamage(40);
	scavvy.beRepaired(20);
	scavvy.attack("June");
	scavvy.takeDamage(70);
	scavvy.attack("Dean");
	scavvy.takeDamage(10);
	// Should not work
	scavvy.beRepaired(20);
	scavvy.attack("Mark");
	return 0;
}
