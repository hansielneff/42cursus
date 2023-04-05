#include "Point.hpp"

static bool point_on_line(Point const&a, Point const&b, Point const&point)
{
	if (a.getX() == b.getX() && a.getY() == b.getY()) return false;
	if ((b.getX() - a.getX()) == 0) return point.getX() == a.getX();
	const Fixed slope = (b.getY() - a.getY()) / (b.getX() - a.getX());
	const Fixed intercept = a.getY() - slope * a.getX();

	return point.getY() == slope * point.getX() + intercept;
}

static Fixed fixed_abs(Fixed const&x)
{
	if (x < 0.0f) return x * -1;
	return x;
}

static Fixed triangle_area(Point const&a, Point const&b, Point const&c)
{
	return fixed_abs(
		a.getX() * (b.getY() - c.getY()) +
		b.getX() * (c.getY() - a.getY()) +
		c.getX() * (a.getY() - b.getY())
	) / 2;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	const float accuracy = 0.01f;

	if (point_on_line(a, b, point) || point_on_line(b, c, point) || point_on_line(c, a, point))
		return false;
	return fixed_abs(
		triangle_area(a, b, c) - (
			triangle_area(point, b, c) +
			triangle_area(a, point, c) +
			triangle_area(a, b, point)
		)
	) < accuracy;
}
