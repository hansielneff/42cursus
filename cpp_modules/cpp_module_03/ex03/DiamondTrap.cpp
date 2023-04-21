#include <iostream>

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string name)
: ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), name(name)
{
	std::cout << "DiamondTrap constructor called" << std::endl;
	health = FragTrap::health;
	energy = ScavTrap::energy;
	damage = FragTrap::damage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondtrap)
: ClapTrap(diamondtrap.name + "_clap_name"), FragTrap(diamondtrap.name), ScavTrap(diamondtrap.name)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	health = diamondtrap.health;
	energy = diamondtrap.energy;
	damage = diamondtrap.damage;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &DiamondTrap)
{	
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	this->name = DiamondTrap.name;
	this->health = DiamondTrap.health;
	this->energy = DiamondTrap.energy;
	this->damage = DiamondTrap.damage;
	return *this;
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::guardGate()
{
	std::cout << "DiamondTrap " << name << " has entered Gate Keeper mode." << std::endl;
}

void DiamondTrap::highFivesGuys()
{
	std::cout << "DiamondTrap " << name << " says \"Hey guys, high five!\"" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << name << " - " << ClapTrap::name << std::endl;
}
