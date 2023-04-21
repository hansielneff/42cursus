#include <iostream>

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap constructor called" << std::endl;
	health = 100;
	energy = 100;
	damage = 30;
}

FragTrap::FragTrap(const FragTrap &fragtrap) : ClapTrap(fragtrap.name)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	health = fragtrap.health;
	energy = fragtrap.health;
	damage = fragtrap.health;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &FragTrap)
{	
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	this->name = FragTrap.name;
	this->health = FragTrap.health;
	this->energy = FragTrap.energy;
	this->damage = FragTrap.damage;
	return *this;
}

void FragTrap::attack(const std::string &target)
{
	if (!health || !energy)
		return ;
	energy--;
	if (energy < 0) energy = 0;
	std::cout << "FragTrap " << name << " attacks " << target
		<< ", causing " << damage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << name << " says \"Hey guys, high five!\"" << std::endl;
}
