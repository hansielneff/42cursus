#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP

#include <string>

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
    FragTrap(const std::string name);
    FragTrap(const FragTrap &fragtrap);
    ~FragTrap();
    FragTrap &operator=(const FragTrap &fragtrap);

	void attack(const std::string &target);
	void highFivesGuys();
};

#endif