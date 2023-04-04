#ifndef HUMAN_A_H
#define HUMAN_A_H

#include <string>

#include "Weapon.hpp"

class HumanA
{
public:
	HumanA(std::string name, Weapon &weapon);
	void attack(void) const;
private:
	std::string name;
	Weapon &weapon;
};

#endif
