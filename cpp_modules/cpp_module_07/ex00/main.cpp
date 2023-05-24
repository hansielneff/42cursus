#include <iostream>

#include "functions.hpp"

int main()
{
	float a = 4;
	float b = 2;

	std::cout << "A:\t" << a << "\nB:\t" << b << std::endl;
	swap(a, b);
	std::cout << "A:\t" << a << "\nB:\t" << b << std::endl;
	std::cout << "Min:\t" << min(a,b) << std::endl;
	std::cout << "Max:\t" << max(a,b) << std::endl;

	return 0;
}
