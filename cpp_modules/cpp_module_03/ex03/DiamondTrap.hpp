#ifndef DIAMOND_TRAP_HPP
#define DIAMOND_TRAP_HPP

#include <string>

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
public:
    DiamondTrap(const std::string name);
    DiamondTrap(const DiamondTrap &diamondtrap);
    ~DiamondTrap();
    DiamondTrap &operator=(const DiamondTrap &diamondtrap);

	void attack(const std::string &target);
    void guardGate();
    void highFivesGuys();
    void whoAmI();

private:
    std::string name;
};

#endif