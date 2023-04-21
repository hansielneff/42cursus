#include <iostream>

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog constructor called" << std::endl;
	type = "Dog";
}

Dog::Dog(const Dog &dog)
{
	std::cout << "Dog copy constructor called" << std::endl;
	type = dog.type;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &dog)
{	
	std::cout << "Dog copy assignment operator called" << std::endl;
	type = dog.type;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
}
