#include <iostream>

#include "FragTrap.hpp"

int main(void)
{
	FragTrap fraggy("Fraggy");
	fraggy.highFivesGuys();
	fraggy.attack("Teemu");
	fraggy.takeDamage(40);
	fraggy.beRepaired(20);
	fraggy.attack("June");
	fraggy.takeDamage(70);
	fraggy.attack("Dean");
	fraggy.takeDamage(10);
	// Should not work
	fraggy.beRepaired(20);
	fraggy.attack("Mark");
	return 0;
}
