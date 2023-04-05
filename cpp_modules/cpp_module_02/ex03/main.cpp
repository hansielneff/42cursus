#include <iostream>

#include "Point.hpp"

int main( void ) {
	const Point a(Fixed(0), Fixed(0));
	const Point b(Fixed(0.0f), Fixed(10));
	const Point c(Fixed(5.3f), Fixed(0.0f));

	const Point point1(Fixed(3.42f), Fixed(3.13f));	// Inside
	const Point point2(Fixed(0), Fixed(3.7f));		// On line
	const Point point3(a);							// On vertex
	const Point point4(Fixed(5), Fixed(6));			// Outside

	const bool is_in_triangle1 = bsp(a, b, c, point1);
	const bool is_in_triangle2 = bsp(a, b, c, point2);
	const bool is_in_triangle3 = bsp(a, b, c, point3);
	const bool is_in_triangle4 = bsp(a, b, c, point4);

	std::cout << "Point a: (" << a.getX() << ", " << a.getY() << ")" << std::endl;
	std::cout << "Point b: (" << b.getX() << ", " << b.getY() << ")" << std::endl;
	std::cout << "Point c: (" << c.getX() << ", " << c.getY() << ")" << std::endl;
	
	std::cout << "Point point1: (" << point1.getX() << ", " << point1.getY() << ")" << std::endl;
	std::cout << "Point point2: (" << point2.getX() << ", " << point2.getY() << ")" << std::endl;
	std::cout << "Point point3: (" << point3.getX() << ", " << point3.getY() << ")" << std::endl;
	std::cout << "Point point4: (" << point4.getX() << ", " << point4.getY() << ")" << std::endl;
	
	std::cout << "point1 in triangle: " << (is_in_triangle1 ? "true" : "false") << std::endl;
	std::cout << "point2 in triangle: " << (is_in_triangle2 ? "true" : "false") << std::endl;
	std::cout << "point3 in triangle: " << (is_in_triangle3 ? "true" : "false") << std::endl;
	std::cout << "point4 in triangle: " << (is_in_triangle4 ? "true" : "false") << std::endl;

	return 0;
}
