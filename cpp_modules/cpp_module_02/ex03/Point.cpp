#include "Point.hpp"

Point::Point() : x(0), y(0)
{
	std::cout << "Point default constructor called" << std::endl;
}

Point::Point(const Fixed &x, const Fixed &y) : x(x), y(y)
{
	std::cout << "Point coordinates constructor called" << std::endl;
}

Point::Point(const Point &point) : x(point.x), y(point.y)
{
	std::cout << "Point copy constructor called" << std::endl;
}

Point::~Point()
{
	std::cout << "Point destructor called" << std::endl;
}

Point &Point::operator=(const Point &point)
{
	std::cout << "Point copy assignment operator called" << std::endl;
	const_cast<Fixed&>(x) = point.x;
	const_cast<Fixed&>(y) = point.y;
	return *this;
}

Fixed const&Point::getX() const
{
	return x;
}

Fixed const&Point::getY() const
{
	return y;
}
