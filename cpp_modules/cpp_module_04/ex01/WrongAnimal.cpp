#include <iostream>

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &animal) : type(animal.type)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &animal)
{	
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	type = animal.type;
	return *this;
}

void WrongAnimal::makeSound() const
{
	std::cout << "..." << std::endl;
}

std::string const&WrongAnimal::getType() const
{
	return type;
}
