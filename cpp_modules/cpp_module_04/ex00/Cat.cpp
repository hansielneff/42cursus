#include <iostream>

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat constructor called" << std::endl;
	type = "Cat";
}

Cat::Cat(const Cat &cat)
{
	std::cout << "Cat copy constructor called" << std::endl;
	type = cat.type;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &cat)
{	
	std::cout << "Cat copy assignment operator called" << std::endl;
	type = cat.type;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Meow.." << std::endl;
}
