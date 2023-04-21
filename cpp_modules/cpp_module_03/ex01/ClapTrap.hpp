#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <string>

class ClapTrap
{
public:
    ClapTrap(const std::string name);
    ClapTrap(const ClapTrap &claptrap);
    ~ClapTrap();
    ClapTrap &operator=(const ClapTrap &claptrap);

	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
protected:
	std::string name;
	int health;
	int energy;
	int damage;
};

#endif