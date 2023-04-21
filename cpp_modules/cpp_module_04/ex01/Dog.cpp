#include <iostream>

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog constructor called" << std::endl;
	type = "Dog";
	brain = new Brain();
}

Dog::Dog(const Dog &dog)
{
	std::cout << "Dog copy constructor called" << std::endl;
	type = dog.type;
	brain = new Brain(*dog.brain);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete brain;
}

Dog &Dog::operator=(const Dog &dog)
{	
	std::cout << "Dog copy assignment operator called" << std::endl;
	type = dog.type;
	delete brain;
	brain = new Brain(*dog.brain);
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
}

Brain &Dog::getBrain()
{
	return *brain;
}
