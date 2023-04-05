#include <cmath>

#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) : value(fixed.value)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int value) : value(value << point)
{
	std::cout <<  "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f) : value(std::roundf(f * (1 << point)))
{
	std::cout <<  "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	value = fixed.value;
	return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return value;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	value = raw;
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(value) / (1 << point));
}

int Fixed::toInt(void) const
{
	return roundf(toFloat());
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	return out << fixed.toFloat();
}
