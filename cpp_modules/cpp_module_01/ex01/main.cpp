#include <iostream>

#include "Zombie.hpp"

int main(void)
{
	const int horde_size = 3;
	Zombie *horde = zombieHorde(horde_size, "Teemu");

	for (int i = 0; i < horde_size; i++)
		horde[i].announce();
	delete[] horde;
	return (0);
}
