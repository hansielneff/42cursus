#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

#include "Fixed.hpp"

class Point
{
public:
    Point();
	Point(const Fixed &x, const Fixed &y);
    Point(const Point &fixed);
    ~Point();
    Point &operator=(const Point &fixed);

	Fixed const&getX() const;
	Fixed const&getY() const;

private:
	Fixed const x;
	Fixed const y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
