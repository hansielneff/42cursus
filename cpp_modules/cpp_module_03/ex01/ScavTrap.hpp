#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include <string>

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
    ScavTrap(const std::string name);
    ScavTrap(const ScavTrap &scavtrap);
    ~ScavTrap();
    ScavTrap &operator=(const ScavTrap &scavtrap);

	void attack(const std::string &target);
	void guardGate();
};

#endif