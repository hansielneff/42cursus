#include <iostream>

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap constructor called" << std::endl;
	health = 100;
	energy = 50;
	damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &scavtrap) : ClapTrap(scavtrap.name)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	health = scavtrap.health;
	energy = scavtrap.health;
	damage = scavtrap.health;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &ScavTrap)
{	
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	this->name = ScavTrap.name;
	this->health = ScavTrap.health;
	this->energy = ScavTrap.energy;
	this->damage = ScavTrap.damage;
	return *this;
}

void ScavTrap::attack(const std::string &target)
{
	if (!health || !energy)
		return ;
	energy--;
	if (energy < 0) energy = 0;
	std::cout << "ScavTrap " << name << " attacks " << target
		<< ", causing " << damage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " has entered Gate Keeper mode." << std::endl;
}
