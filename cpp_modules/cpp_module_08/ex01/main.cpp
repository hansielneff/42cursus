#include <iostream>

#include "Span.hpp"

int main()
{
	Span sp = Span(7);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	try
	{
		int arr[] = {42, 43, 150};
		sp.addNumbers(arr, arr + 3);
	}
	catch (std::exception &e)
	{
		std::cout << "Couldn't fit all the numbers!" << std::endl;
	}

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	return 0;
}
