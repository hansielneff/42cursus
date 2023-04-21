#include <iostream>

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat constructor called" << std::endl;
	type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat &cat)
{
	std::cout << "Cat copy constructor called" << std::endl;
	type = cat.type;
	brain = new Brain(*cat.brain);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete brain;
}

Cat &Cat::operator=(const Cat &cat)
{	
	std::cout << "Cat copy assignment operator called" << std::endl;
	type = cat.type;
	delete brain;
	brain = new Brain(*cat.brain);
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Meow.." << std::endl;
}

Brain &Cat::getBrain()
{
	return *brain;
}
