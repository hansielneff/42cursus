#include <iostream>

#include "RPN.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Usage: ./RPN expression" << std::endl;
		return 1;
	}
	std::string expr(argv[1]);
	try { std::cout << RPN::evaluate(expr) << std::endl; }
	catch (std::exception &e) { std::cout << "Error" << std::endl; }
	return 0;
}
