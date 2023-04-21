#include <iostream>

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &animal) : type(animal.type)
{
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &animal)
{	
	std::cout << "Animal copy assignment operator called" << std::endl;
	type = animal.type;
	return *this;
}

void Animal::makeSound() const
{
	std::cout << "..." << std::endl;
}

std::string const&Animal::getType() const
{
	return type;
}
