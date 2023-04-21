#include <iostream>

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string name)
: name(name)
, health(10)
, energy(10)
, damage(0)
{
	std::cout << "Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &claptrap)
: name(claptrap.name)
, health(claptrap.health)
, energy(claptrap.energy)
, damage(claptrap.damage)
{
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &claptrap)
{	
	std::cout << "Copy assignment operator called" << std::endl;
	this->name = claptrap.name;
	this->health = claptrap.health;
	this->energy = claptrap.energy;
	this->damage = claptrap.damage;
	return *this;
}

void ClapTrap::attack(const std::string &target)
{
	if (!health || !energy)
		return ;
	energy--;
	if (energy < 0) energy = 0;
	std::cout << "ClapTrap " << name << " attacks " << target
		<< ", causing " << damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << name << " took damage for " << amount << " hit points!" << std::endl;
	health -= amount;
	if (health < 0) health = 0;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!health || !energy)
		return ;
	energy--;
	if (energy < 0) energy = 0;
	health += amount;
	std::cout << name << " repaired itself for " << amount << " hit points!" << std::endl;
}
