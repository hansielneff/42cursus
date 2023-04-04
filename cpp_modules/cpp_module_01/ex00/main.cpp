#include <iostream>

#include "Zombie.hpp"

int main(void)
{
	randomChump("Teemu");
	Zombie *zombie_dean = newZombie("Dean");
	zombie_dean->announce();
	delete zombie_dean;
	return (0);
}
