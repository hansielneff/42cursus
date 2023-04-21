#include <iostream>

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat constructor called" << std::endl;
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &cat)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	type = cat.type;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &cat)
{	
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	type = cat.type;
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "Meow.." << std::endl;
}
