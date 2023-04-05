#include <cmath>

#include "Fixed.hpp"

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return a.getRawBits() < b.getRawBits() ? a : b;
}

Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (Fixed&)(a.getRawBits() < b.getRawBits() ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return a.getRawBits() > b.getRawBits() ? a : b;
}

Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (Fixed&)(a.getRawBits() > b.getRawBits() ? a : b);
}

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

bool Fixed::operator>(const Fixed &other) const
{
	return value > other.getRawBits();
}

bool Fixed::operator<(const Fixed &other) const
{
	return value < other.getRawBits();
}

bool Fixed::operator>=(const Fixed &other) const
{
	return value >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed &other) const
{
	return value <= other.getRawBits();
}

bool Fixed::operator==(const Fixed &other) const
{
	return value == other.getRawBits();
}

bool Fixed::operator!=(const Fixed &other) const
{
	return value != other.getRawBits();
}

Fixed Fixed::operator+(const Fixed &other) const
{
	return Fixed(toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
	return Fixed(toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{
	return Fixed(toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
	if (other.getRawBits() != 0)
		return Fixed(toFloat() / other.toFloat());
	else
	{
		std::cout << "Error: division by zero" << std::endl;
		return Fixed();
	}
}

Fixed &Fixed::operator++()
{
	value++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed result(*this);
	value++;
	return result;
}

Fixed &Fixed::operator--()
{
	value--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed result(*this);
	value--;
	return result;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	return out << fixed.toFloat();
}
